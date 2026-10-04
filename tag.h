/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Práctica 4: Expresiones Regulares
 * Autor: Raúl Navarro Cobos
 * Correo: alu0101484365@ull.edu.es
 * Fecha: 03/10/2026
 * Archivo tag.g: programa donde se definen los métodos la clase TAG
 * Historial de revisiones:
 *   03/10/2026 - Creación del código
 */ 

#pragma once

#include <string>

class Tag {
 public: // Métodos
  Tag(int line, const std::string& name);
  int GetLine() const;
  std::string GetName() const;
 private: // Atributos
  int line_;
  std::string name_;
};
