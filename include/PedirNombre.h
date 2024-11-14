#ifndef PEDIRNOMBRE_H
#define PEDIRNOMBRE_H

#include <SFML/Graphics.hpp>
#include <string>

// Declara la función pedirNombre, que muestra una ventana para que el usuario ingrese su nombre
std::string pedirNombre(sf::RenderWindow &window, sf::Font &font, bool usar=false);

#endif // PEDIRNOMBRE_H
