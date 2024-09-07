#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <SFML/Graphics.hpp>


class Personaje: public sf::Drawable
{
    float _velocity=10;

    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    Personaje();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;


};

#endif // PERSONAJE_H
