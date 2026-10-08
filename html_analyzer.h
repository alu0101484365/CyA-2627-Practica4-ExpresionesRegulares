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
#include "list.h"

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

  // Modificacion
  void ExtractLists(const std::string& content);

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
  std::vector<List> lists_;
};