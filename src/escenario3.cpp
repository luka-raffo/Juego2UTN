#include "escenario3.h"

Escenariojefe::Escenariojefe(){

//Asignacion para la textura
    _texture.loadFromFile("Tileset/SInVALLAS.jpg");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

    //reescalar ell fondo (porque es muy grande, igual hay q cambiarlo)





        if (!_texture.loadFromFile("Tileset/SInVALLAS.jpg")) {
            cerr << "Error cargando la textura" << endl;
        }
        _sprite.setTexture(_texture);
    }
    //caverna
caverna::caverna() {



//Asignacion para la textura
    _texture.loadFromFile("tileset/Cueva.png");

    //selecciono las coordenada del arbusto en una hoja con varios sprites



    _sprite.setTexture(_texture); // Asignar la textura al sprite
    //_sprite.setTextureRect(idleRestRect); // Asignar el rectángulo de textura al sprite


    if (!_texture.loadFromFile("tileset/Cueva.png")) {
            cerr << "Error cargando la textura piso" << endl;
        }
        _sprite.setTexture(_texture);


}

sf::FloatRect caverna::getBounds() const {
    return _sprite.getGlobalBounds();
}

void caverna::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

CavernaBattleBackground::CavernaBattleBackground(){

//Asignacion para la textura
    _texture.loadFromFile("tileset/cueva2.png");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

    //reescalar el fondo (porque es muy grande, igual hay q cambiarlo)
    _sprite.setScale(5, 5);


    _sprite.setPosition(0, 0);

        if (!_texture.loadFromFile("tileset/cueva2.png")) {
            cerr << "Error cargando la textura" << endl;
        }
        _sprite.setTexture(_texture);
    }

        vallas::vallas(){

        _texture.loadFromFile("tileset/Vallas.sprite.jpg"); // Usa la ruta de la textura de la barrera
        _sprite.setTexture(_texture);
        //_sprite.setPosition(500, 300); // Ajusta la posición según sea necesario


    }
sf::FloatRect vallas::getBounds() const {
    return _sprite.getGlobalBounds();
}

void vallas::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}
suelo::suelo(){



//Asignacion para la textura
    _texture.loadFromFile("tileset/suelo.png");

    //selecciono las coordenada del arbusto en una hoja con varios sprites



    _sprite.setTexture(_texture); // Asignar la textura al sprite
    //_sprite.setTextureRect(idleRestRect); // Asignar el rectángulo de textura al sprite


    if (!_texture.loadFromFile("tileset/suelo.png")) {
            cerr << "Error cargando la textura piso" << endl;
        }
        _sprite.setTexture(_texture);


}

sf::FloatRect suelo::getBounds() const {
    return _sprite.getGlobalBounds();
}

void suelo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

