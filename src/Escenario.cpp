#include "Escenario.h"

using namespace std;

Escenario::Escenario()
{

//Asignacion para la textura
    _texture.loadFromFile("sprites/background/Lienzo3.JPG");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);


    _sprite.setPosition(0, 0);

    if (!_texture.loadFromFile("sprites/background/Lienzo3.JPG"))
    {
        cout<< "Error cargando la textura" << endl;
    }
    _sprite.setTexture(_texture);
}

bool Escenario::cargarTextura(const string& archivo)
{
    if (!_texture.loadFromFile(archivo))
    {
        return false;
    }
    getSprite().setTexture(_texture);
    return true;

}

sf::Sprite& Escenario::getSprite()
{
    return _sprite;
}


Escenario::Escenario(string texturaArchivo){
    if (!_texture.loadFromFile(texturaArchivo))
    {
        cout << "Error cargando la textura" << endl;
    }
    _sprite.setTexture(_texture);
    _sprite.setPosition(0, 0);

}


Escenario::~Escenario()
{
    //dtor
}
