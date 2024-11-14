#pragma once
#include <string>
#include <vector>

// Estructura para almacenar el nombre y tiempo de cada jugador
struct Jugador {
    std::string nombre;
    double tiempo; // Cambiado a double para mayor precisión
};

// Función para agregar un jugador al ranking y guardar en el archivo
void agregarJugador(const std::string &nombre, double tiempo, const std::string &archivo);

// Función para mostrar el ranking
void mostrarRanking(const std::string &archivo);

// Función para cargar el ranking desde un archivo
std::vector<Jugador> cargarRanking(const std::string &archivo);
