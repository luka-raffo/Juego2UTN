#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Graphics.hpp>
#include "Colisionable.h"


class Personaje: public sf::Drawable, public Colisionable
{
    float _velocity=4;


    sf::Sprite _sprite;
    sf::Texture _texture;

    sf::IntRect idleDownRect; // Frame de reposo mirando hacia abajo
    sf::IntRect idleLeftRect; // Frame de reposo mirando hacia la izquierda
    sf::IntRect idleRightRect; // Frame de reposo mirando hacia la derecha
    sf::IntRect idleUpRect; // Frame de reposo mirando hacia arriba

    sf::IntRect downRect[3]; // Tres frames para la animaci�n hacia abajo
    sf::IntRect leftRect[3]; // Tres frames para la animaci�n hacia la izquierda
    sf::IntRect rightRect[3]; // Tres frames para la animaci�n hacia la derecha
    sf::IntRect upRect[3]; // Tres frames para la animaci�n hacia arriba
    sf::Clock _animationClock; // Reloj para controlar la animaci�n
    int _currentFrame = 0; // Frame actual de la animaci�n

    bool _isMoving=false;

     sf::IntRect* _currentIdleRect; // Frame de reposo actual


public:
    Personaje();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds() const override;

    void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    }
    sf::Vector2f getPosition() const {
    return _sprite.getPosition();}

   void guardarPosicion();  // Guarda la posici�n actual en un archivo
    void cargarPosicion();   // Carga la posici�n desde un archivo

};

#endif // PERSONAJE_H
