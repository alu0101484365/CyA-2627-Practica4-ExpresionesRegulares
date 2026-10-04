#include "html_analyzer.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

HTMLAnalyzer::HTMLAnalyzer(const std::string& input_file, const std::string& output_file)
    : input_file_(input_file), output_file_(output_file), has_html_(false), has_head_(false), has_body_(false), doctype_(""), description_("") {}

bool HTMLAnalyzer::Analyze() {
  std::ifstream file(input_file_);
  if (!file.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << input_file_ << std::endl;
    return false;
  }

  // Leemos todo el contenido del archivo a un std::string
  std::stringstream buffer;
  buffer << file.rdbuf();
  std::string content = buffer.str();
  file.close();

  // Ejecutamos las tres fases de extracción
  CheckStructure(content);
  ExtractComments(content);
  ExtractTagsAndAttributes(content);

  return true;
}

void HTMLAnalyzer::CheckStructure(const std::string& content) {
  std::regex doctype_regex("<!DOCTYPE\\s+html>", std::regex::icase);
  if (std::regex_search(content, doctype_regex)) {
    doctype_ = "HTML5";
  }

  std::regex html_regex("<html", std::regex::icase);
  std::regex head_regex("<head", std::regex::icase);
  std::regex body_regex("<body", std::regex::icase);

  has_html_ = std::regex_search(content, html_regex);
  has_head_ = std::regex_search(content, head_regex);
  has_body_ = std::regex_search(content, body_regex);
}

void HTMLAnalyzer::ExtractComments(const std::string& content) {
  std::regex comment_regex("<!--([\\s\\S]*?)-->");
  auto comments_begin = std::sregex_iterator(content.begin(), content.end(), comment_regex);
  auto comments_end = std::sregex_iterator();

  bool is_first = true;
  for (std::sregex_iterator i = comments_begin; i != comments_end; ++i) {
    std::smatch match = *i;
    size_t pos = match.position();

    // Contamos las líneas anteriores para saber la línea de inicio
    int start_line = 1;
    for (size_t j = 0; j < pos; ++j) {
      if (content[j] == '\n') start_line++;
    }

    // Contamos las líneas del comentario para saber la línea final
    std::string full_comment = match.str();
    int newlines = 0;
    for (char c : full_comment) {
      if (c == '\n') newlines++;
    }
    int end_line = start_line + newlines;

    std::string text = match[1].str();

    // Si es el primer comentario tras el DOCTYPE, es la descripción
    bool is_desc = false;
    if (is_first && !doctype_.empty()) {
      is_desc = true;
      // Limpiamos espacios y saltos de línea al inicio y final
      size_t first = text.find_first_not_of(" \t\n\r");
      size_t last = text.find_last_not_of(" \t\n\r");
      if (first != std::string::npos && last != std::string::npos) {
        description_ = text.substr(first, (last - first + 1));
      } else {
        description_ = text;
      }
      is_first = false;
    }

    comments_.push_back(Comment(start_line, end_line, full_comment, is_desc));
  }
}

void HTMLAnalyzer::ExtractTagsAndAttributes(const std::string& content) {
  std::regex tag_regex("<(/)?(html|head|title|body|h1|p|a|img)(\\s*|\\s+[^>]*?)>", std::regex::icase);
  std::regex attr_regex("([a-zA-Z\\-]+)\\s*=\\s*\"([^\"]*)\"");

  auto tags_begin = std::sregex_iterator(content.begin(), content.end(), tag_regex);
  auto tags_end = std::sregex_iterator();

  for (std::sregex_iterator i = tags_begin; i != tags_end; ++i) {
    std::smatch match = *i;
    size_t pos = match.position();

    // Calcular la línea de aparición
    int line = 1;
    for (size_t j = 0; j < pos; ++j) {
      if (content[j] == '\n') line++;
    }

    bool is_closing = match[1].matched;
    std::string tag_name = match[2].str();
    if (is_closing) {
      tag_name = "/" + tag_name;
    }

    tags_.push_back(Tag(line, tag_name));

    // Si es etiqueta de apertura, buscamos sus atributos
    if (!is_closing) {
      std::string attr_content = match[3].str();
      auto attr_begin = std::sregex_iterator(attr_content.begin(), attr_content.end(), attr_regex);
      auto attr_end = std::sregex_iterator();

      for (std::sregex_iterator j = attr_begin; j != attr_end; ++j) {
        std::smatch attr_match = *j;
        std::string attr_name = attr_match[1].str();
        std::string attr_value = attr_match[2].str();
        attributes_.push_back(Attribute(line, match[2].str(), attr_name, attr_value));
      }
    }
  }
}

bool HTMLAnalyzer::WriteReport() const {
  std::ofstream out(output_file_);
  if (!out.is_open()) {
    std::cerr << "Error: No se pudo crear el archivo de salida " << output_file_ << std::endl;
    return false;
  }

  out << "PROGRAM: " << input_file_ << "\n\n";

  out << "DESCRIPTION:\n";
  if (!description_.empty()) {
    out << description_ << "\n";
  }
  out << "\n";

  out << "STRUCTURE:\n";
  out << "HTML: " << (has_html_ ? "True" : "False") << "\n";
  out << "HEAD: " << (has_head_ ? "True" : "False") << "\n";
  out << "BODY: " << (has_body_ ? "True" : "False") << "\n";
  out << "DOCTYPE: " << (doctype_.empty() ? "None" : doctype_) << "\n\n";

  out << "TAGS:\n";
  for (const auto& tag : tags_) {
    out << "[Line " << tag.GetLine() << "] " << tag.GetName() << "\n";
  }
  out << "\n";

  out << "ATTRIBUTES:\n";
  int current_line = -1;
  std::string current_tag = "";
  for (const auto& attr : attributes_) {
    if (attr.GetLine() != current_line || attr.GetTagName() != current_tag) {
      if (current_line != -1) out << "\n";
      out << "[Line " << attr.GetLine() << "] " << attr.GetTagName() << "\n";
      current_line = attr.GetLine();
      current_tag = attr.GetTagName();
    }
    out << attr.GetName() << " = \"" << attr.GetValue() << "\"\n";
  }
  out << "\n";

  out << "COMMENTS:\n";
  for (const auto& comment : comments_) {
    if (comment.IsDescription()) {
      out << "[Line " << comment.GetStartLine() << "] DESCRIPTION\n";
    } else if (comment.GetStartLine() == comment.GetEndLine()) {
      out << "[Line " << comment.GetStartLine() << "]\n";
    } else {
      out << "[Line " << comment.GetStartLine() << "-" << comment.GetEndLine() << "]\n";
    }
    out << comment.GetText() << "\n\n";
  }

  out.close();
  return true;
}