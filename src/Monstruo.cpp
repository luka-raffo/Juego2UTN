#include "Monstruo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "inventory.h"
// Constructor por defecto de Monstruo con valores aleatorios
Monstruo::Monstruo() {
    srand(static_cast<unsigned>(time(0)));  // Inicializar la semilla para números aleatorios solo una vez
    _vida = rand() % 101 + 100;   // Vida aleatoria entre 100 y 200
    _danio = rand() % 51 + 20;    // Daño aleatorio entre 20 y 70
    _defensa = rand() % 21 + 10;  // Defensa aleatoria entre 10 y 30
}

// Constructor con parámetros
Monstruo::Monstruo(float vida, float danio, float defensa)
    : _vida(vida), _danio(danio), _defensa(defensa) {}

// Métodos de vida
float Monstruo::getVida() const {
    return _vida;
}

void Monstruo::Sumarvida(float vida) {
    _vida += vida;
}

// Métodos de daño
float Monstruo::getDanio() const {
    return _danio;
}

void Monstruo::Sumarataque(float danio) {
    _danio += danio;
}

// Métodos de defensa
float Monstruo::getDefensa() const {
    return _defensa;
}

void Monstruo::setDefensa(float defensa) {
    _defensa = defensa;
}

// Implementación de las clases derivadas con valores aleatorios

Hornerot::Hornerot() : Monstruo() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/hornerot.PNG")) {
        std::cerr << "Error al cargar velom.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setPosition(0,0);
    _sprite.setScale(2,2);
}

void Hornerot::setPosition(float x, float y) {
    _sprite.setPosition(x, y);
}

const sf::Sprite& Hornerot::getSprite() const {
    return _sprite;
}

void Hornerot::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Hornerot::getBounds() const {
    return _sprite.getGlobalBounds();
}

// Implementación de Pelucin
Pelucin::Pelucin() : Monstruo() {
   // Asignacion para la textura
    if (!_texture.loadFromFile("include/pelucin.PNG")) {
        std::cerr << "Error al cargar pelucin.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}

void Pelucin::setPosition(float x, float y) {
    _sprite.setPosition(x, y);
}

const sf::Sprite& Pelucin::getSprite() const {
    return _sprite;
}

void Pelucin::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

sf::FloatRect Pelucin::getBounds() const {
    return _sprite.getGlobalBounds();
}

// Implementación similar para las otras clases (Balleton, Velom, Tukin, Lechuza, Bufalont)
//balleton
Balleton::Balleton() : Monstruo() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/balleton.PNG")) {
        std::cerr << "Error al cargar balleton.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}
void Balleton::setPosition(float x, float y) {
    _sprite.setPosition(x, y); }

const sf::Sprite& Balleton::getSprite() const {
    return _sprite; }
void Balleton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states); }

sf::FloatRect Balleton::getBounds() const { return _sprite.getGlobalBounds(); }
//velom
Velom::Velom() : Monstruo() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/velom.PNG")) {
        cout << "Error al cargar velom.PNG" << endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}

Velom::Velom(const string& nombre) : Monstruo(), nombre(nombre) {}
string Velom::getNombre() const { return nombre; }

bool Velom::operator==(const Velom& other) const {
    return nombre == other.nombre; }

void Velom::setPosition(float x, float y) {
     _sprite.setPosition(x, y); }

const sf::Sprite& Velom::getSprite() const {
    return _sprite; }

void Velom::draw(sf::RenderTarget& target, sf::RenderStates states) const { target.draw(_sprite, states); }

sf::FloatRect Velom::getBounds() const { return _sprite.getGlobalBounds(); }
//tukin
Tukin::Tukin() : Monstruo() {
   // Asignacion para la textura
    if (!_texture.loadFromFile("include/tukin.PNG")) {
        std::cerr << "Error al cargar tukin.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}
void Tukin::setPosition(float x, float y) {
    _sprite.setPosition(x, y); }

const sf::Sprite& Tukin::getSprite() const {
     return _sprite; }
void Tukin::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states); }
sf::FloatRect Tukin::getBounds() const {
    return _sprite.getGlobalBounds(); }
//lechuza
Lechuza::Lechuza() : Monstruo() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/FuckingLechuza.PNG")) {
        std::cerr << "Error al cargar FuckingLechuza.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}
void Lechuza::setPosition(float x, float y) {
    _sprite.setPosition(x, y); }

const sf::Sprite& Lechuza::getSprite() const {
    return _sprite; }

void Lechuza::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states); }

sf::FloatRect Lechuza::getBounds() const {
    return _sprite.getGlobalBounds(); }
//bufalont
Bufalont::Bufalont() : Monstruo() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/bufalont.PNG")) {
        std::cerr << "Error al cargar bufalont.PNG" << std::endl;
    }
    // Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);
    _sprite.setScale(2,2);
}
void Bufalont::setPosition(float x, float y) {
    _sprite.setPosition(x, y); }

const sf::Sprite& Bufalont::getSprite() const {
    return _sprite; }

void Bufalont::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states); }

sf::FloatRect Bufalont::getBounds() const { return _sprite.getGlobalBounds(); }
/*
// Hornerot
Hornerot::Hornerot() {
    // Asignacion para la textura
    if (!_texture.loadFromFile("include/hornerot.PNG")) {
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
*/
