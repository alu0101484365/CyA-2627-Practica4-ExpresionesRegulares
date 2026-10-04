#pragma once

#include <string>
#include <vector>

#include "attribute.h"
#include "comment.h"
#include "tag.h"

class HTMLAnalyzer {
 // Métodos
 public:
  // Constructor: recibe el fichero de entrada (.html) y el de salida (.txt)
  HTMLAnalyzer(const std::string& input_file, const std::string& output_file);
  // Ejecuta todo el análisis del archivo HTML
  bool Analyze();
  // Genera el informe final en el fichero de salida
  bool WriteReport() const;

 // Atributos
 private:
  // Métodos auxiliares para organizar la búsqueda con regex
  void CheckStructure(const std::string& content);
  void ExtractTagsAndAttributes(const std::string& content);
  void ExtractComments(const std::string& content);

  // Ficheros de entrada y salida
  std::string input_file_;
  std::string output_file_;

  // Estructura del documento
  bool has_html_;
  bool has_head_;
  bool has_body_;
  std::string doctype_;
  std::string description_;

  // Contenedores para almacenar los elementos encontrados
  std::vector<Tag> tags_;
  std::vector<Attribute> attributes_;
  std::vector<Comment> comments_;
};