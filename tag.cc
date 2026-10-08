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
 * Archivo tag.cc: Implementación de los métodos de la clase Tag.
 */

#include "tag.h"

/**
 * @brief Constructor de la clase Tag.
 */
Tag::Tag(int line, const std::string& name) : line_(line), name_(name) {}

/**
 * @brief Devuelve la línea de la etiqueta.
 */
int Tag::GetLine() const {
  return line_;
}

/**
 * @brief Devuelve el nombre de la etiqueta.
 */
std::string Tag::GetName() const {
  return name_;
}
