#include <SFML/Graphics.hpp>
#include <iostream>
#include "escenario1.h"
using namespace std;

escenario::escenario(){

//Asignacion para la textura
    _texture.loadFromFile("Tileset/TileSetEscenario.PNG");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

    //reescalar ell fondo (porque es muy grande, igual hay q cambiarlo)
    _sprite.setScale(2, 2);


    _sprite.setPosition(0, 0);

        if (!_texture.loadFromFile("Tileset/TileSetEscenario.PNG")) {
            cerr << "Error cargando la textura" << endl;
        }
        _sprite.setTexture(_texture);
    }

bush::bush() {



//Asignacion para la textura
    _texture.loadFromFile("Tileset/TileSetEscenario.PNG");

    //selecciono las coordenada del arbusto en una hoja con varios sprites
    sf::IntRect idleRestRect = sf::IntRect(57, 408, 15, 15);



    _sprite.setTexture(_texture); // Asignar la textura al sprite
    _sprite.setTextureRect(idleRestRect); // Asignar el rect�ngulo de textura al sprite


    if (!_texture.loadFromFile("TileSetEscenario.PNG")) {
            cerr << "Error cargando la textura Bush" << endl;
        }
        _sprite.setTexture(_texture);


}

sf::FloatRect bush::getBounds() const {
    return _sprite.getGlobalBounds();
}

void bush::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

bush6x4::bush6x4() {



//Asignacion para la textura
    _texture.loadFromFile("arbustos4x4.PNG");

    //selecciono las coordenada del arbusto en una hoja con varios sprites




    _sprite.setTexture(_texture); // Asignar la textura al sprite


    if (!_texture.loadFromFile("arbustos4x4.PNG")) {
            cerr << "Error cargando la textura Bush4x4" << endl;
        }
        _sprite.setTexture(_texture);


}

sf::FloatRect bush6x4::getBounds() const {
    return _sprite.getGlobalBounds();
}

void bush6x4::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

