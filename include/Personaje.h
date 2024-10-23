#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Graphics.hpp>
#include "Colisionable.h"
#include "inventory.h"


class Personaje: public sf::Drawable, public Colisionable
{
    float _velocity=3;


    sf::Sprite _sprite;
    sf::Texture _texture;

    sf::IntRect idleDownRect; // Frame de reposo mirando hacia abajo
    sf::IntRect idleLeftRect; // Frame de reposo mirando hacia la izquierda
    sf::IntRect idleRightRect; // Frame de reposo mirando hacia la derecha
    sf::IntRect idleUpRect; // Frame de reposo mirando hacia arriba

    sf::IntRect downRect[3]; // Tres frames para la animación hacia abajo
    sf::IntRect leftRect[3]; // Tres frames para la animación hacia la izquierda
    sf::IntRect rightRect[3]; // Tres frames para la animación hacia la derecha
    sf::IntRect upRect[3]; // Tres frames para la animación hacia arriba
    sf::Clock _animationClock; // Reloj para controlar la animación
    int _currentFrame = 0; // Frame actual de la animación

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

};

#endif // PERSONAJE_H
