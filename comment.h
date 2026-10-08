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
 * Archivo comment.h: Declaración de la clase Comment.
 */

#pragma once

#include <string>

/**
 * @brief Clase que representa un comentario dentro de un archivo HTML.
 */
class Comment {
 public:
  /**
   * @brief Constructor de la clase Comment.
   * @param start_line Línea donde inicia el comentario.
   * @param end_line Línea donde finaliza el comentario.
   * @param text Texto completo dentro del comentario.
   * @param is_description Indica si actúa como la descripción principal.
   */
  Comment(int start_line, int end_line, const std::string& text, bool is_description = false);
  /**
   * @brief Obtiene la línea de inicio.
   * @return Línea de inicio.
   */
  int GetStartLine() const;
  /**
   * @brief Obtiene la línea final.
   * @return Línea final.
   */
  int GetEndLine() const;
  /**
   * @brief Obtiene el contenido textual del comentario.
   * @return Texto del comentario.
   */
  std::string GetText() const;
  /**
   * @brief Consulta si el comentario es la descripción del documento.
   * @return true si es la descripción, false en caso contrario.
   */
  bool IsDescription() const;
 private:
  int start_line_;       
  int end_line_;         
  std::string text_;   
  bool is_description_;
};