#include "Monstruo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
// Hornerot
Hornerot::Hornerot() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/hornero.jpg")) {
        std::cerr << "Error al cargar hornero.jpg" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
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
}

// Pelucin
Pelucin::Pelucin() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/pelucin.PNG")) {
        std::cerr << "Error al cargar pelucin.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
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

// Balleton
Balleton::Balleton() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/balleton.PNG")) {
        std::cerr << "Error al cargar balleton.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
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

// Velom
Velom::Velom() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/velom.PNG")) {
        std::cerr << "Error al cargar velom.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
}

void Velom::Sumarvida(float vida) {
    _vida = vida + std::rand() % 300 + 100;
}

void Velom::Sumarataque(float danio) {
    _danio = danio + std::rand() % 100 + 100;
}

void Velom::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Velom::getBounds() const {
    return _sprite.getGlobalBounds();
}

// Tukin
Tukin::Tukin() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/tukin.PNG")) {
        std::cerr << "Error al cargar tukin.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
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
}

// Lechuza
Lechuza::Lechuza() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/FuckingLechuza.PNG")) {
        std::cerr << "Error al cargar FuckingLechuza.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
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
}
