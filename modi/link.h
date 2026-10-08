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
 * Archivo link.h: Declaración de la clase Link (URL + TEXT).
 */

#pragma once

#include <string>

/**
 * @brief Clase que representa un enlace HTML con su URL y texto visible.
 */
class Link {
 public:
  /**
   * @brief Constructor de la clase Link.
   * @param line Número de línea donde se encuentra la etiqueta <a>.
   * @param url Dirección URL completa extraída de href.
   * @param text Texto visible entre <a> y </a>.
   */
  Link(int line, const std::string& url, const std::string& text);

  /**
   * @brief Obtiene la línea del enlace.
   * @return Número de línea.
   */
  int GetLine() const;

  /**
   * @brief Obtiene la URL completa.
   * @return Cadena con la URL.
   */
  std::string GetUrl() const;

  /**
   * @brief Obtiene el texto visible.
   * @return Cadena con el texto encerrado.
   */
  std::string GetText() const;

 private:
  int line_;          ///< Línea de aparición.
  std::string url_;   ///< URL completa del atributo href.
  std::string text_;  ///< Texto entre <a> y </a>.
};
