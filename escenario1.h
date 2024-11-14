#ifndef ESCENARIO1_H_INCLUDED
#define ESCENARIO1_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Escenario : public sf::Drawable
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    // Aquí puedes agregar métodos y constructores si es necesario
};

class Bush : public sf::Drawable
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    // Aquí puedes agregar métodos y constructores si es necesario
};

#endif // ESCENARIO1_H_INCLUDED
