/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2.º
 * Práctica 4: Expresiones Regulares
 * Autor: Raul Navarro Cobos
 * Correo: alu0101484365@ull.edu.es
 * Fecha: 08/10/2026
 * Archivo html_analyzer.h: Declaración de la clase principal HTMLAnalyzer.
 */

#pragma once

#include <string>
#include <vector>

#include "attribute.h"
#include "comment.h"
#include "tag.h"

/**
 * @brief Clase analizadora de archivos HTML mediante Expresiones Regulares.
 */
class HTMLAnalyzer {
 public:
  /**
   * @brief Constructor del analizador HTML.
   * @param input_file Ruta del archivo HTML de entrada.
   * @param output_file Ruta del archivo TXT de salida.
   */
  HTMLAnalyzer(const std::string& input_file, const std::string& output_file);

  /**
   * @brief Realiza la lectura y extracción con expresiones regulares.
   * @return true si el proceso fue exitoso, false si falló la apertura.
   */
  bool Analyze();

  /**
   * @brief Genera el archivo de informe estructurado.
   * @return true si se pudo escribir el informe, false en caso contrario.
   */
  bool WriteReport() const;

 private:
  /**
   * @brief Revisa la presencia de DOCTYPE, html, head y body.
   * @param content Texto completo del archivo HTML.
   */
  void CheckStructure(const std::string& content);

  /**
   * @brief Extrae los comentarios HTML y detecta la descripción principal.
   * @param content Texto completo del archivo HTML.
   */
  void ExtractComments(const std::string& content);

  /**
   * @brief Extrae las etiquetas permitidas y sus atributos internos.
   * @param content Texto completo del archivo HTML.
   */
  void ExtractTagsAndAttributes(const std::string& content);


/**
 * Método ExtractLinks para la Variante 1 (URL + TEXT)
 */
/**
 void HTMLAnalyzer::ExtractLinks(const std::string& content) {
  // Grupo 1: URL entre comillas de href | Grupo 2: Texto entre <a> y </a>
  std::regex link_regex("<a\\s+[^>]*href=\"([^\"]*)\"[^>]*>([\\s\\S]*?)</a>", std::regex::icase); // protocol <a\\s+[^>]*href=\"([a-zA-Z0-9]+)://[^\"]*\"[^>]*>([\\s\\S]*?)</a>"
  auto links_begin = std::sregex_iterator(content.begin(), content.end(), link_regex);
  auto links_end = std::sregex_iterator();

  for (std::sregex_iterator i = links_begin; i != links_end; ++i) {
    std::smatch match = *i;
    size_t pos = match.position();

    // Calcular la línea
    int line = 1;
    for (size_t j = 0; j < pos; ++j) {
      if (content[j] == '\n') line++;
    }

    std::string url = match.str(1);   // Grupo 1: URL
    std::string text = match.str(2);  // Grupo 2: Texto interno

    // Limpiar espacios sobrantes en el texto
    size_t first = text.find_first_not_of(" \t\n\r");
    size_t last = text.find_last_not_of(" \t\n\r");
    if (first != std::string::npos && last != std::string::npos) {
      text = text.substr(first, (last - first + 1));
    }

    links_.push_back(Link(line, url, text));
  }
}
*/
  std::string input_file_;   
  std::string output_file_;  

  bool has_html_;             
  bool has_head_;             
  bool has_body_;             
  std::string doctype_;       
  std::string description_;   

  std::vector<Tag> tags_;           
  std::vector<Attribute> attributes_; 
  std::vector<Comment> comments_;   
  // std::vector<Link> links_;
};