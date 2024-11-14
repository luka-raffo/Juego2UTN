#ifndef PEDIRNOMBRE_H_INCLUDED
#define PEDIRNOMBRE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>

// Declara la función pedirNombre, que muestra una ventana para que el usuario ingrese su nombre
std::string pedirNombre(sf::RenderWindow &window, sf::Font &font, bool usar=false);



#endif // PEDIRNOMBRE_H_INCLUDED


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
