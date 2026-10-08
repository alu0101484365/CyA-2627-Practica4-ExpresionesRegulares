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
 * Archivo main.cc: Programa principal para análisis de ficheros HTML.
 */

#include <iostream>
#include <string>

#include "html_analyzer.h"

/**
 * @brief Muestra el modo de empleo del programa en la línea de comandos.
 * @param program_name Nombre del ejecutable.
 */
void ShowUsage(const std::string& program_name) {
  std::cout << "Uso: " << program_name << " <fichero_entrada.html> <fichero_salida.txt>\n"
            << "Descripción: Analiza un fichero HTML y genera un informe estructurado "
            << "con sus etiquetas, atributos y comentarios.\n"
            << "Opciones:\n"
            << "  --help, -h    Muestra este mensaje de ayuda.\n";
}

/**
 * @brief Función principal del programa.
 * @param argc Número de argumentos pasados por consola.
 * @param argv Array de argumentos pasados por consola.
 * @return 0 si finaliza con éxito, 1 si ocurre algún error.
 */
int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::string arg = argv[1];
    if (arg == "--help" || arg == "-h") {
      ShowUsage(argv[0]);
      return 0;
    }
  }

  if (argc != 3) {
    std::cerr << "Error: Número incorrecto de argumentos.\n\n";
    ShowUsage(argv[0]);
    return 1;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  std::cout << "Iniciando análisis del archivo HTML: " << input_file << "...\n";

  HTMLAnalyzer analyzer(input_file, output_file);

  if (!analyzer.Analyze()) {
    std::cerr << "Error: Ocurrió un fallo durante el análisis del fichero.\n";
    return 1;
  }

  if (!analyzer.WriteReport()) {
    std::cerr << "Error: Ocurrió un fallo al escribir el informe de salida.\n";
    return 1;
  }

  std::cout << "Análisis completado con éxito. Informe guardado en: " << output_file << "\n";

  return 0;
}
