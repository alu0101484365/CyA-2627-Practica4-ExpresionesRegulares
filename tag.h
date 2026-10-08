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
 * Archivo tag.h: Declaración de la clase Tag.
 */

#pragma once

#include <string>

/**
 * @brief Clase que representa una etiqueta HTML y la línea donde aparece.
 */
class Tag {
 public:
  /**
   * @brief Constructor de la clase Tag.
   * @param line Número de línea en el archivo HTML.
   * @param name Nombre de la etiqueta HTML (ej. "head", "/p").
   */
  Tag(int line, const std::string& name);
  /**
   * @brief Obtiene el número de línea.
   * @return Número de línea donde se encontró la etiqueta.
   */
  int GetLine() const;
  /**
   * @brief Obtiene el nombre de la etiqueta.
   * @return Cadena con el nombre de la etiqueta.
   */
  std::string GetName() const;
 private:
  int line_;
  std::string name_;
};