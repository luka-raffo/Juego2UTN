#ifndef ESCENARIO_H
#define ESCENARIO_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


using namespace std;

class Escenario: public sf::Drawable
{
    private:
    string _texturaArchivo;
    sf::Texture _texture;
    sf::Sprite _sprite;

    public:
        Escenario();
        Escenario(string texturaArchivo);

        sf::Sprite& getSprite() ;

        bool cargarTextura(const string& archivo);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }

        virtual ~Escenario();

    protected:


};

#endif // ESCENARIO_H
