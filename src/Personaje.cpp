#include "Personaje.h"

Personaje::Personaje()
{
    //Asignacion para la textura
    _texture.loadFromFile("personajeF.png");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
}

void Personaje::update(){
//mapeo de las teclas
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            _sprite.move(0,-_velocity);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            _sprite.move(0,_velocity);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            _sprite.move(-_velocity,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            _sprite.move(_velocity,0);
        }



        //Validaciones para que el personaje no salga de la pantalla
        if(_sprite.getPosition().x <0){
            _sprite.setPosition(0,_sprite.getPosition().y);
        }

        if(_sprite.getPosition().y <0){
            _sprite.setPosition(_sprite.getPosition().x,0);
        }

        if(_sprite.getPosition().x+_sprite.getGlobalBounds().width >1920){
            _sprite.setPosition(800-_sprite.getGlobalBounds().width,_sprite.getPosition().y);
        }

        if(_sprite.getPosition().y+_sprite.getGlobalBounds().height >1080){
            _sprite.setPosition(_sprite.getPosition().x,600-_sprite.getGlobalBounds().height);
        }
}

    void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(_sprite, states);
    }
