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

bush::bush() {
//Asignacion para la textura
    _texture.loadFromFile("Include/Bush.jpeg");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
}

sf::FloatRect bush::getBounds() const {
    return _sprite.getGlobalBounds();
}

void bush::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}


