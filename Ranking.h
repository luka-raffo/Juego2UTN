
#ifndef RANKING_H
#define RANKING_H

#include <string>
#include <vector>

struct Puntaje {
    std::string nombre;
    float tiempo;
};

std::vector<Puntaje> cargarRanking();
void guardarRanking(const std::vector<Puntaje>& ranking);
void actualizarRanking(const std::string& nombreJugador, float tiempo);

#endif
