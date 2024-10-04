#ifndef MONSTRUO_H
#define MONSTRUO_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Hornerot: public sf::Drawable
{
    private:

       float _vida=100;
       float _danio=25;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Hornerot();
 void Sumarvida(float vida);
 void Sumarataque( float danio);

};

class Pelucin : public sf::Drawable
{
    private:

       float _vida=100;
       float _danio=25;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Pelucin();
 void Sumarvida(float vida);
 void Sumarataque( float danio);

};
class Balleton : public sf::Drawable
{
    private:

       float _vida=100;
       float _danio=25;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Balleton();
 void Sumarvida(float vida);
 void Sumarataque( float danio);

};
class Velom : public sf::Drawable
{
    private:

       float _vida=100;
       float _danio=25;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Velom();
 void Sumarvida(float vida);
 void Sumarataque( float danio);

};

class Tukin : public sf::Drawable
{
    private:

       float _vida=100;
       float _danio=25;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Tukin();
 void Sumarvida(float vida);
 void Sumarataque( float danio);

};
class Lechuza : public sf::Drawable
{
    private:

       float _vida=100;
       float _danio=25;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Lechuza();
 void Sumarvida(float vida);
 void Sumarataque( float danio);

};



#endif // MONSTRUO_H
