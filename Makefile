# Variables de compilación
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Nombre del ejecutable final
TARGET = p04_html_analyzer

# Archivos fuente (.cc) y objetos (.o)
SRCS = main.cc html_analyzer.cc tag.cc attribute.cc comment.cc
OBJS = $(SRCS:.cc=.o)

# Regla principal: compilar el ejecutable
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar cada archivo .cc a su correspondiente .o
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla de limpieza para borrar ejecutable y objetos creados
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean