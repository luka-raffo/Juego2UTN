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
/*Hornerot::Hornerot() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/velom.PNG")) {
        std::cerr << "Error al cargar velom.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setPosition(0,0);
    _sprite.setScale(2,2);
}

void Hornerot::Sumarvida(float vida) {
    _vida = vida + std::rand() % 300 + 100;
}

void Hornerot::Sumarataque(float danio) {
    _danio = danio + std::rand() % 100 + 100;
}

void Hornerot::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Hornerot::getBounds() const {
    return _sprite.getGlobalBounds();
}*/

/*
// Pelucin
Pelucin::Pelucin() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/pelucin.PNG")) {
        std::cerr << "Error al cargar pelucin.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}

void Pelucin::Sumarvida(float vida) {
    _vida = vida + std::rand() % 300 + 100;
}

void Pelucin::Sumarataque(float danio) {
    _danio = danio + std::rand() % 100 + 100;
}

void Pelucin::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Pelucin::getBounds() const {
    return _sprite.getGlobalBounds();
}
*/
/*
// Balleton
Balleton::Balleton() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/balleton.PNG")) {
        std::cerr << "Error al cargar balleton.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}

void Balleton::Sumarvida(float vida) {
    _vida = vida + std::rand() % 300 + 100;
}

void Balleton::Sumarataque(float danio) {
    _danio = danio + std::rand() % 100 + 100;
}

void Balleton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Balleton::getBounds() const {
    return _sprite.getGlobalBounds();
}
*/

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


/*

// Tukin
Tukin::Tukin() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/tukin.PNG")) {
        std::cerr << "Error al cargar tukin.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}

void Tukin::Sumarvida(float vida) {
    _vida = vida + std::rand() % 300 + 100;
}

void Tukin::Sumarataque(float danio) {
    _danio = danio + std::rand() % 100 + 100;
}

void Tukin::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Tukin::getBounds() const {
    return _sprite.getGlobalBounds();
}*/
/*
// Lechuza
Lechuza::Lechuza() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/FuckingLechuza.PNG")) {
        std::cerr << "Error al cargar FuckingLechuza.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}

void Lechuza::Sumarvida(float vida) {
    _vida = vida + std::rand() % 300 + 100;
}

void Lechuza::Sumarataque(float danio) {
    _danio = danio + std::rand() % 100 + 100;
}

void Lechuza::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Lechuza::getBounds() const {
    return _sprite.getGlobalBounds();
}

// Bufalont
Bufalont::Bufalont() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/bufalont.PNG")) {
        std::cerr << "Error al cargar bufalont.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}

void Bufalont::Sumarvida(float vida) {
    _vida = vida + std::rand() % 300 + 100;
}

void Bufalont::Sumarataque(float danio) {
    _danio = danio + std::rand() % 100 + 100;
}

void Bufalont::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Bufalont::getBounds() const {
    return _sprite.getGlobalBounds();
}*/
