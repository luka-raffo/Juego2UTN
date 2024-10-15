#include "Monstruo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
//hornero

Hornerot:: Hornerot(){
//Asignacion para la textura
    _texture.loadFromFile("include/hornero.jpg");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

}

void Hornerot::Sumarvida(float vida){
    _vida = vida;
    vida + std::rand()%300+100;


}
void Hornerot::Sumarataque( float danio){
   _danio = danio;
     danio+std::rand()%100+100;

}
//peluche
Pelucin:: Pelucin(){
//Asignacion para la textura
    _texture.loadFromFile("include/pelucin.PNG");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

}

void Pelucin::Sumarvida(float vida){
    _vida = vida;
    vida + std::rand()%300+100;


}
void Pelucin::Sumarataque( float danio){
   _danio = danio;
     danio+std::rand()%100+100;

}
//ballena
Balleton:: Balleton(){
//Asignacion para la textura
    _texture.loadFromFile("include/balleton.PNG");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

}

void Balleton::Sumarvida(float vida){
    _vida = vida;
    vida + std::rand()%300+100;

}
void Balleton::Sumarataque( float danio){
   _danio = danio;
     danio+std::rand()%100+100;

}
//vela
Velom:: Velom(){
//Asignacion para la textura
    _texture.loadFromFile("include/velom.PNG");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

}

void Velom::Sumarvida(float vida){
    _vida = vida;
    vida + std::rand()%300+100;


}
void Velom::Sumarataque( float danio){
   _danio = danio;
     danio+std::rand()%100+100;

}
//tuka
Tukin :: Tukin(){
//Asignacion para la textura
    _texture.loadFromFile("include/tukin.PNG");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

}

void Tukin::Sumarvida(float vida){
    _vida = vida;
    vida + std::rand()%300+100;


}
void Tukin::Sumarataque( float danio){
   _danio = danio;
     danio+std::rand()%100+100;

}
Lechuza :: Lechuza(){
//Asignacion para la textura
    _texture.loadFromFile("include/FuckingLechuza.PNG");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

}

void Lechuza::Sumarvida(float vida){
    _vida = vida;
    vida + std::rand()%300+100;


}
void Lechuza::Sumarataque( float danio){
   _danio = danio;
     danio+std::rand()%100+100;

}
