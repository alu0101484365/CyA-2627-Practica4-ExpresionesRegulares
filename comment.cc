/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2.º
 * Práctica 4: Expresiones Regulares
 * Autor: Raul Navarro Cobos
 * Fecha: 08/10/2026
 * Archivo comment.cc: Implementación de la clase Comment.
 */

#include "comment.h"

Comment::Comment(int start_line, int end_line, const std::string& text,
                 bool is_description)
    : start_line_(start_line),
      end_line_(end_line),
      text_(text),
      is_description_(is_description) {
}

int Comment::GetStartLine() const {
  return start_line_;
}

int Comment::GetEndLine() const {
  return end_line_;
}

std::string Comment::GetText() const {
  return text_;
}

bool Comment::IsDescription() const {
  return is_description_;
}