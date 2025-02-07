#include <SFML/Graphics.hpp>
#include <iostream>
#include "escenario1.h"
using namespace std;

escenario::escenario(){

//Asignacion para la textura
    _texture.loadFromFile("include/Fondo.jpeg");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

        if (!_texture.loadFromFile("include/Fondo.jpeg")) {
            cerr << "Error cargando la textura" << endl;
        }
        _sprite.setTexture(_texture);
    }
}
bush::bush() {
    if (!_texture.loadFromFile("Bush.png")) {
        std::cerr << "Error al cargar la textura del arbusto" << std::endl;
    }
    _sprite.setTexture(_texture);
    _sprite.setPosition(300, 300); // Cambia según necesites
}

sf::FloatRect bush::getBounds() const {
    return _sprite.getGlobalBounds();
}

void bush::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}
