/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2.º
 * Práctica 4: Expresiones Regulares
 * Autor: [Tu Nombre]
 * Correo: [aluXXXXXXXX@ull.edu.es]
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

  std::string input_file_;   ///< Fichero de entrada.
  std::string output_file_;  ///< Fichero de salida.

  bool has_html_;             ///< Existencia de <html
  bool has_head_;             ///< Existencia de <head
  bool has_body_;             ///< Existencia de <body
  std::string doctype_;       ///< Tipo de DOCTYPE (HTML5).
  std::string description_;   ///< Descripción del documento.

  std::vector<Tag> tags_;           ///< Vector de etiquetas encontradas.
  std::vector<Attribute> attributes_; ///< Vector de atributos encontrados.
  std::vector<Comment> comments_;   ///< Vector de comentarios encontrados.
};