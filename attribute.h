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
 * Archivo attribute.h: Declaración de la clase Attribute.
 */

#pragma once

#include <string>

/**
 * @brief Clase que representa un atributo perteneciente a una etiqueta HTML.
 */
class Attribute {
 public:
  /**
   * @brief Constructor de la clase Attribute.
   * @param line Número de línea donde se encuentra.
   * @param tag_name Nombre de la etiqueta padre.
   * @param name Nombre del atributo.
   * @param value Valor asignado al atributo.
   */
  Attribute(int line, const std::string& tag_name, const std::string& name, const std::string& value);
  /**
   * @brief Obtiene la línea del atributo.
   * @return Número de línea.
   */
  int GetLine() const;
  /**
   * @brief Obtiene el nombre de la etiqueta contenedora.
   * @return Nombre de la etiqueta padre.
   */
  std::string GetTagName() const;
  /**
   * @brief Obtiene el nombre del atributo.
   * @return Nombre del atributo (ej. "href", "src").
   */
  std::string GetName() const;
  /**
   * @brief Obtiene el valor del atributo.
   * @return Valor del atributo entre comillas.
   */
  std::string GetValue() const;
 private:
  int line_;    
  std::string tag_name_;
  std::string name_;
  std::string value_;
};
