#include "Monstruo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "inventory.h"
// Hornerot
Hornerot::Hornerot() {
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
}


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


// Velom
Velom::Velom(const string& nombre) : nombre(nombre) {



    // Asignacion para la textura
    if (!_texture.loadFromFile("include/velom.PNG")) {
        cout << "Error al cargar velom.PNG" << endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);


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

string Velom::getNombre() const{
        return nombre;
    }

bool Velom::operator==(const Velom& other) const {
        return nombre == other.nombre;
    }


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
}

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
}
