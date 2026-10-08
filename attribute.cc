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
 * Archivo attribute.cc: Implementación de la clase Attribute.
 */

#include "attribute.h"

/**
 * @brief Constructor de la clase Attribute.
 */
Attribute::Attribute(int line, const std::string& tag_name, const std::string& name, const std::string& value) : line_(line), tag_name_(tag_name), name_(name), value_(value) {}

/**
 * @brief Devuelve el número de línea.
 */
int Attribute::GetLine() const {
  return line_;
}

/**
 * @brief Devuelve el nombre de la etiqueta contenedora.
 */
std::string Attribute::GetTagName() const {
  return tag_name_;
}

/**
 * @brief Devuelve el nombre del atributo.
 */
std::string Attribute::GetName() const {
  return name_;
}

/**
 * @brief Devuelve el valor del atributo.
 */
std::string Attribute::GetValue() const {
  return value_;
}
