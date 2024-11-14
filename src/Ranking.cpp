#include "Ranking.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

// Cargar el ranking desde el archivo
std::vector<Jugador> cargarRanking(const std::string &archivo) {
    std::vector<Jugador> ranking;
    std::ifstream archivoEntrada(archivo);
    if (archivoEntrada.is_open()) {
        std::string nombre;
        double tiempo;
        while (archivoEntrada >> nombre >> tiempo) {
            ranking.push_back({nombre, tiempo});
        }
        archivoEntrada.close();
    }
    return ranking;
}

// Guardar el ranking en el archivo
void guardarRanking(const std::vector<Jugador> &ranking, const std::string &archivo) {
    std::ofstream archivoSalida(archivo);
    if (archivoSalida.is_open()) {
        for (const auto &jugador : ranking) {
            archivoSalida << jugador.nombre << " " << jugador.tiempo << "\n";
        }
        archivoSalida.close();
    }
}

// Agregar un jugador al ranking y guardar en el archivo
void agregarJugador(const std::string &nombre, double tiempo, const std::string &archivo) {
    std::vector<Jugador> ranking = cargarRanking(archivo);
    ranking.push_back({nombre, tiempo});
    std::sort(ranking.begin(), ranking.end(), [](const Jugador &a, const Jugador &b) {
        return a.tiempo < b.tiempo;
    });
    guardarRanking(ranking, archivo);
}

// Mostrar el ranking
void mostrarRanking(const std::string &archivo) {
    std::vector<Jugador> ranking = cargarRanking(archivo);
    std::cout << "Ranking:\n";
    for (const auto &jugador : ranking) {
        std::cout << jugador.nombre << ", Tiempo: " << jugador.tiempo << " segundos\n";
    }
}
void guardarResultado(const std::string& nombre, double tiempo) {
    std::string archivo = "ranking.txt"; // Archivo donde se guarda el ranking
    agregarJugador(nombre, tiempo, archivo);
}
