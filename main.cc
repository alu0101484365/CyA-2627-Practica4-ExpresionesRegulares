#include <iostream>
#include <string>

#include "html_analyzer.h"

// Función auxiliar para mostrar la ayuda sobre el uso del programa
void ShowUsage(const std::string& program_name) {
  std::cout << "Uso: " << program_name << " <fichero_entrada.html> <fichero_salida.txt>\n"
            << "Descripción: Analiza un fichero HTML y genera un informe estructurado "
            << "con sus etiquetas, atributos y comentarios.\n"
            << "Opciones:\n"
            << "  --help, -h    Muestra este mensaje de ayuda.\n";
}

int main(int argc, char* argv[]) {
  // Comprobar si el usuario pide ayuda explícitamente
  if (argc == 2) {
    std::string arg = argv[1];
    if (arg == "--help" || arg == "-h") {
      ShowUsage(argv[0]);
      return 0;
    }
  }

  // Verificar que se hayan pasado exactamente 2 argumentos (entrada y salida)
  if (argc != 3) {
    std::cerr << "Error: Número incorrecto de argumentos.\n\n";
    ShowUsage(argv[0]);
    return 1;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  std::cout << "Iniciando análisis del archivo HTML: " << input_file << "...\n";

  // Crear la instancia del analizador principal
  HTMLAnalyzer analyzer(input_file, output_file);

  // Paso 1: Analizar el contenido del fichero HTML
  if (!analyzer.Analyze()) {
    std::cerr << "Error: Ocurrió un fallo durante el análisis del fichero.\n";
    return 1;
  }

  // Paso 2: Escribir el informe de resumen en el fichero de salida
  if (!analyzer.WriteReport()) {
    std::cerr << "Error: Ocurrió un fallo al escribir el informe de salida.\n";
    return 1;
  }

  std::cout << "Análisis completado con éxito. Informe guardado en: " << output_file << "\n";

  return 0;
}