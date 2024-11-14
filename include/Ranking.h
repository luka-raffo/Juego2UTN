#pragma once
#include <string>
#include <vector>

// Estructura para almacenar el nombre y tiempo de cada jugador
struct Jugador {
    std::string nombre;
    double tiempo; // Cambiado a double para mayor precisi�n
};

// Funci�n para agregar un jugador al ranking y guardar en el archivo
void agregarJugador(const std::string &nombre, double tiempo, const std::string &archivo);

// Funci�n para mostrar el ranking
void mostrarRanking(const std::string &archivo);

// Funci�n para cargar el ranking desde un archivo
std::vector<Jugador> cargarRanking(const std::string &archivo);
