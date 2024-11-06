#include <SFML/Graphics.hpp>
#include <iostream>
#include "escenario1.h"

using namespace std;



escenariollegada::escenariollegada(){

//Asignacion para la textura
    _texture.loadFromFile("sprites/background/Lienzo3.JPG");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

    //reescalar ell fondo (porque es muy grande, igual hay q cambiarlo)

     // _sprite.setScale(0.50, 0.50);


    _sprite.setPosition(0, 0);

        if (!_texture.loadFromFile("sprites/background/Lienzo3.JPG")) {
            cerr << "Error cargando la textura" << endl;
        }
        _sprite.setTexture(_texture);
    }
//////////////////////////////////////////////////////////////////////////////////////////////
    Barrera::Barrera(){

        _texture.loadFromFile("Sprites/Edificio/Casa.png"); // Usa la ruta de la textura de la barrera
        _sprite.setTexture(_texture);
       // _sprite.setPosition(500, 300); // Ajusta la posición según sea necesario


    }
sf::FloatRect Barrera::getBounds() const {
    return _sprite.getGlobalBounds();
}

void Barrera::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}
//////////////////////////////////////////////////////////////////////////////
    Barcito::Barcito(){

        _texture.loadFromFile("Sprites/Edificio/Barcito1.png"); // Usa la ruta de la textura de la barrera
        _sprite.setTexture(_texture);
        //_sprite.setPosition(500, 300); // Ajusta la posición según sea necesario


    }
sf::FloatRect Barcito::getBounds() const {
    return _sprite.getGlobalBounds();
}

void Barcito::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}
////////////////////////////////////////////////////////////////////
    Flores::Flores(){

        _texture.loadFromFile("Sprites/Edificio/Flores1.png"); // Usa la ruta de la textura de la barrera
        _sprite.setTexture(_texture);
        //_sprite.setPosition(500, 300); // Ajusta la posición según sea necesario


    }
sf::FloatRect Flores::getBounds() const {
    return _sprite.getGlobalBounds();
}

void Flores::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}
//////////////////////////////////////////////////////////////////////////////////
    Cerco::Cerco(){

        _texture.loadFromFile("Sprites/Edificio/Cerco1.png"); // Usa la ruta de la textura de la barrera
        _sprite.setTexture(_texture);
        //_sprite.setPosition(500, 300); // Ajusta la posición según sea necesario


    }
sf::FloatRect Cerco::getBounds() const {
    return _sprite.getGlobalBounds();
}

void Cerco::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}
////////////////////////////////////////
pasto::pasto() {



//Asignacion para la textura
    _texture.loadFromFile("sprites/Edificio/piso1.png");

    //selecciono las coordenada del arbusto en una hoja con varios sprites

   _sprite.setScale(2,2);


    _sprite.setTexture(_texture); // Asignar la textura al sprite
    //_sprite.setTextureRect(idleRestRect); // Asignar el rectángulo de textura al sprite


    if (!_texture.loadFromFile("sprites/Edificio/piso1.png")) {
            cerr << "Error cargando la textura piso" << endl;
        }
        _sprite.setTexture(_texture);


}
sf::FloatRect pasto::getBounds() const {
    return _sprite.getGlobalBounds();
}

void pasto::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}
