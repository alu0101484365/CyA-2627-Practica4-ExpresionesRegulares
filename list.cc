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
 * Archivo List.cc: Implementación de la clase List.
 */

#include "list.h"

/**
 * @brief Constructor de la clase List.
 */
List::List(int line, const std::string& type, const std::string& text)
    : line_(line), type_(type), text_(text) {}

/**
 * @brief Devuelve el número de línea.
 */
int List::GetLine() const {
  return line_;
}

/**
 * @brief Devuelve la URL del enlace.
 */
std::string List::GetType() const {
  return type_;
}

/**
 * @brief Devuelve el texto interno del enlace.
 */
std::string List::GetTexts() const {
  return text_;
}