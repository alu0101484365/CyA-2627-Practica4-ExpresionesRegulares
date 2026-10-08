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
 * Archivo List.h: Declaración de la clase List
 */

#pragma once

#include <string>

/**
 * @brief Clase que representa un enlace HTML con su URL y texto visible.
 */
class List {
 public:
  /**
   * @brief Constructor de la clase Link.
   * @param line Número de línea donde se encuentra la etiqueta <a>.
   * @param url Dirección URL completa extraída de href.
   * @param text Texto visible entre <a> y </a>.
   */
  List(int line, const std::string& type, const std::string& text);

  /**
   * @brief Obtiene la línea del enlace.
   * @return Número de línea.
   */
  int GetLine() const;

  /**
   * @brief Obtiene la URL completa.
   * @return Cadena con la URL.
   */
  std::string GetType() const;

  /**
   * @brief Obtiene el texto visible.
   * @return Cadena con el texto encerrado.
   */
  std::string GetTexts() const;

 private:
  int line_;
  std::string type_;
  std::string text_;
};


