#include "Escenario2.h"

using namespace std;

escenario::escenario(){

//Asignacion para la textura
    _texture.loadFromFile("Tileset/nuevo.JPG");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

    //reescalar ell fondo (porque es muy grande, igual hay q cambiarlo)



    _sprite.setPosition(0, 0);

        if (!_texture.loadFromFile("Tileset/nuevo.JPG")) {
            cerr << "Error cargando la textura" << endl;
        }
        _sprite.setTexture(_texture);
    }

bush::bush() {



//Asignacion para la textura
    _texture.loadFromFile("include/bush.jpeg");

    //selecciono las coordenada del arbusto en una hoja con varios sprites
    sf::IntRect idleRestRect = sf::IntRect(57, 408, 15, 15);



    _sprite.setTexture(_texture); // Asignar la textura al sprite
    _sprite.setTextureRect(idleRestRect); // Asignar el rectángulo de textura al sprite


    if (!_texture.loadFromFile("include/bush.jpeg")) {
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

BattleBackground::BattleBackground(){

//Asignacion para la textura
    _texture.loadFromFile("Battle Backgrounds/With Textboxes/BattleBackground.Png");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

    //reescalar el fondo (porque es muy grande, igual hay q cambiarlo)
    _sprite.setScale(5, 5);


    _sprite.setPosition(0, 0);

        if (!_texture.loadFromFile("Battle Backgrounds/With Textboxes/BattleBackground.png")) {
            cerr << "Error cargando la textura" << endl;
        }
        _sprite.setTexture(_texture);
    }
//piso
piso::piso() {



//Asignacion para la textura
    _texture.loadFromFile("tileset/piso.png");

    //selecciono las coordenada del arbusto en una hoja con varios sprites



    _sprite.setTexture(_texture); // Asignar la textura al sprite
    //_sprite.setTextureRect(idleRestRect); // Asignar el rectángulo de textura al sprite


    if (!_texture.loadFromFile("tileset/piso.png")) {
            cerr << "Error cargando la textura piso" << endl;
        }
        _sprite.setTexture(_texture);


}

sf::FloatRect piso::getBounds() const {
    return _sprite.getGlobalBounds();
}

void piso::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

//arboles
arboles::arboles() {



//Asignacion para la textura
    _texture.loadFromFile("tileset/arboles.png");

    //selecciono las coordenada del arbusto en una hoja con varios sprites



    _sprite.setTexture(_texture); // Asignar la textura al sprite
    //_sprite.setTextureRect(idleRestRect); // Asignar el rectángulo de textura al sprite


    if (!_texture.loadFromFile("tileset/arboles.png")) {
            cerr << "Error cargando la textura piso" << endl;
        }
        _sprite.setTexture(_texture);


}

sf::FloatRect arboles::getBounds() const {
    return _sprite.getGlobalBounds();
}

void arboles::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}
