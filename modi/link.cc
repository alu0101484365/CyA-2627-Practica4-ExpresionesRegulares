/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2.º
 * Práctica 4: Expresiones Regulares (Modificación 1)
 * Autor: [Tu Nombre]
 * Correo: [aluXXXXXXXX@ull.edu.es]
 * Fecha: 08/10/2026
 * Archivo link.cc: Implementación de la clase Link.
 */

#include "link.h"

/**
 * @brief Constructor de la clase Link.
 */
Link::Link(int line, const std::string& url, const std::string& text)
    : line_(line), url_(url), text_(text) {}

/**
 * @brief Devuelve el número de línea.
 */
int Link::GetLine() const {
  return line_;
}

/**
 * @brief Devuelve la URL del enlace.
 */
std::string Link::GetUrl() const {
  return url_;
}

/**
 * @brief Devuelve el texto interno del enlace.
 */
std::string Link::GetText() const {
  return text_;
}