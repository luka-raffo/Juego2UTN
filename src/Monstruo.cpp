#include "Monstruo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "inventory.h"

// Constructor por defecto de Monstruo con valores aleatorios
Monstruo::Monstruo() : _vida(0), _danio(0), _defensa(0) {}

// Constructor con parámetros
Monstruo::Monstruo(float vida, float danio, float defensa): _vida(vida), _danio(danio), _defensa(defensa) {}

// Métodos de vida
float Monstruo::getVida() const {
    return _vida;
}

void Monstruo::Sumarvida(float vida) {
    _vida += vida;
}

void Monstruo::setVida(float vida){
    _vida = vida;
}

// Métodos de daño
float Monstruo::getDanio() const {
    return _danio;
}

void Monstruo::Sumarataque(float danio) {
    _danio += danio;
}

void Monstruo::setAtaque(float danio){
 _danio=danio;
}


// Métodos de defensa
float Monstruo::getDefensa() const {
    return _defensa;
}

void Monstruo::setDefensa(float defensa) {
    _defensa = defensa;
}

// Métodos para posición y escala
void Monstruo::setPosition(float x, float y) {
    _sprite.setPosition(x, y);
}

void Monstruo::setScale(float x, float y) {
    _sprite.setScale(x, y);
}

// Método para obtener el sprite

const sf::Sprite& Monstruo::getSprite() const {
    return _sprite;
}

// Método protegido para acceder al sprite
sf::Sprite& Monstruo::getSprite() {
    return _sprite;
}

// Método para obtener el nombre
string Monstruo::getNombre() const {
    return nombre;
}

void Monstruo::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

// Sobrecarga del operador ==
bool Monstruo::operator==(const Monstruo& other) const {
    return _vida == other._vida && _danio == other._danio && _defensa == other._defensa && nombre == other.nombre;
}

// Función para dibujar
void Monstruo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

// Función para obtener los límites del sprite
sf::FloatRect Monstruo::getBounds() const {
    return _sprite.getGlobalBounds();
}

// Método para cargar la textura del Monstruo
bool Monstruo::cargarTextura(const std::string& archivo) {
    if (!_texture.loadFromFile(archivo)) {
        return false;
    }
    _sprite.setTexture(_texture);
    return true;
}



// Hornerot
Hornerot::Hornerot(float vida, float danio, float defensa, const string& texturaArchivo) : Monstruo(vida, danio, defensa) {
if (!cargarTextura(texturaArchivo)) {
        throw std::runtime_error("Error al cargar la textura del hornerot");
    }
}


// Sobrescribir la función draw
void Hornerot::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Llamar a la función draw de la clase base
    Monstruo::draw(target, states);
    // Aquí podrías añadir código para dibujar elementos específicos del sprite
}

// Sobrescribir la función getBounds
sf::FloatRect Hornerot::getBounds() const {
    return Monstruo::getBounds();
}

// Método para cargar la textura del Dragon
bool Hornerot::cargarTextura(const string& archivo) {
    if (!_HornerotTexture.loadFromFile(archivo)) {
        return false;
    }
    getSprite().setTexture(_HornerotTexture);
    return true;

}
//peluchin
Peluchin::Peluchin(float vida, float danio, float defensa, const string& texturaArchivo) : Monstruo(vida, danio, defensa) {
if (!cargarTextura(texturaArchivo)) {
        throw std::runtime_error("Error al cargar la textura del Peluchin");
    }
}


// Sobrescribir la función draw
void Peluchin::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Llamar a la función draw de la clase base
    Monstruo::draw(target, states);
    // Aquí podrías añadir código para dibujar elementos específicos del sprite
}

// Sobrescribir la función getBounds
sf::FloatRect Peluchin::getBounds() const {
    return Monstruo::getBounds();
}

// Método para cargar la textura del Dragon
bool Peluchin::cargarTextura(const string& archivo) {
    if (!_PeluchinTexture.loadFromFile(archivo)) {
        return false;
    }
    getSprite().setTexture(_PeluchinTexture);
    return true;

}
//balleton

balleton::balleton(float vida, float danio, float defensa, const string& texturaArchivo) : Monstruo(vida, danio, defensa) {
if (!cargarTextura(texturaArchivo)) {
        throw std::runtime_error("Error al cargar la textura del balleton");
    }
}


// Sobrescribir la función draw
void balleton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Llamar a la función draw de la clase base
    Monstruo::draw(target, states);
    // Aquí podrías añadir código para dibujar elementos específicos del sprite
}

// Sobrescribir la función getBounds
sf::FloatRect balleton::getBounds() const {
    return Monstruo::getBounds();
}

// Método para cargar la textura del Dragon
bool balleton::cargarTextura(const string& archivo) {
    if (!_BalletonTexture.loadFromFile(archivo)) {
        return false;
    }
    getSprite().setTexture(_BalletonTexture);
    return true;

}

// Velom
Velom::Velom(float vida, float danio, float defensa, const string& texturaArchivo) : Monstruo(vida, danio, defensa) {
if (!cargarTextura(texturaArchivo)) {
        throw std::runtime_error("Error al cargar la textura del Dragon");
    }
}


// Sobrescribir la función draw
void Velom::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Llamar a la función draw de la clase base
    Monstruo::draw(target, states);
    // Aquí podrías añadir código para dibujar elementos específicos del sprite
}

// Sobrescribir la función getBounds
sf::FloatRect Velom::getBounds() const {
    return Monstruo::getBounds();
}

// Método para cargar la textura del Dragon
bool Velom::cargarTextura(const string& archivo) {
    if (!_velomTexture.loadFromFile(archivo)) {
        return false;
    }
    getSprite().setTexture(_velomTexture);
    return true;
}

//tukin

Tukin::Tukin(float vida, float danio, float defensa, const string& texturaArchivo) : Monstruo(vida, danio, defensa) {
if (!cargarTextura(texturaArchivo)) {
        throw std::runtime_error("Error al cargar la textura del tukin");
    }
}


// Sobrescribir la función draw
void Tukin::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Llamar a la función draw de la clase base
    Monstruo::draw(target, states);
    // Aquí podrías añadir código para dibujar elementos específicos del sprite
}

// Sobrescribir la función getBounds
sf::FloatRect Tukin::getBounds() const {
    return Monstruo::getBounds();
}

// Método para cargar la textura del Dragon
bool Tukin::cargarTextura(const string& archivo) {
    if (!_TukinTexture.loadFromFile(archivo)) {
        return false;
    }
    getSprite().setTexture(_TukinTexture);
    return true;
}
//lechuza
Lechuza::Lechuza(float vida, float danio, float defensa, const string& texturaArchivo) : Monstruo(vida, danio, defensa) {
if (!cargarTextura(texturaArchivo)) {
        throw std::runtime_error("Error al cargar la textura de la fucking lechuza");
    }
}


// Sobrescribir la función draw
void Lechuza::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Llamar a la función draw de la clase base
    Monstruo::draw(target, states);
    // Aquí podrías añadir código para dibujar elementos específicos del sprite
}

// Sobrescribir la función getBounds
sf::FloatRect Lechuza::getBounds() const {
    return Monstruo::getBounds();
}

// Método para cargar la textura del Dragon
bool Lechuza::cargarTextura(const string& archivo) {
    if (!_LechuzaTexture.loadFromFile(archivo)) {
        return false;
    }
    getSprite().setTexture(_LechuzaTexture);
    return true;
}
//bufalont
Bufalont::Bufalont(float vida, float danio, float defensa, const string& texturaArchivo) : Monstruo(vida, danio, defensa) {
if (!cargarTextura(texturaArchivo)) {
        throw std::runtime_error("Error al cargar la textura del bufalont");
    }
}


// Sobrescribir la función draw
void Bufalont::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Llamar a la función draw de la clase base
    Monstruo::draw(target, states);
    // Aquí podrías añadir código para dibujar elementos específicos del sprite
}

// Sobrescribir la función getBounds
sf::FloatRect Bufalont::getBounds() const {
    return Monstruo::getBounds();
}

// Método para cargar la textura del Dragon
bool Bufalont::cargarTextura(const string& archivo) {
    if (!_BufalontTexture.loadFromFile(archivo)) {
        return false;
    }
    getSprite().setTexture(_BufalontTexture);
    return true;
}
//Lobizon
Lobizon::Lobizon(float vida, float danio, float defensa, const string& texturaArchivo) : Monstruo(vida, danio, defensa) {
if (!cargarTextura(texturaArchivo)) {
        throw std::runtime_error("Error al cargar la textura del bufalont");
    }
}
void Lobizon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Llamar a la función draw de la clase base
    Monstruo::draw(target, states);
    // Aquí podrías añadir código para dibujar elementos específicos del sprite
}

// Sobrescribir la función getBounds
sf::FloatRect Lobizon::getBounds() const {
    return Monstruo::getBounds();
}

// Método para cargar la textura del Dragon
bool Lobizon::cargarTextura(const string& archivo) {
    if (!_LobizonTexture.loadFromFile(archivo)) {
        return false;
    }
    getSprite().setTexture(_LobizonTexture);
    return true;
}
