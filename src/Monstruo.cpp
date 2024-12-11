#include "Monstruo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Funciones.h"
#include "AnimacionAtaque.h"


// Constructor por defecto de Monstruo con valores aleatorios
Monstruo::Monstruo(string texturaArchivo)
    : _vida(getRandomStat(100.0f, 150.0f)),  // Vida entre 50 y 100
      _danio(getRandomStat(40.0f, 80.0f)),  // Da�o entre 10 y 30
      _defensa(getRandomStat(30.0f, 60.0f)),  // Defensa entre 5 y 20
      _texturaArchivo(texturaArchivo)

{}

// Constructor con par�metros
Monstruo::Monstruo(float vida, float danio, float defensa,string texturaArchivo): _vida(vida), _danio(danio), _defensa(defensa), _texturaArchivo(texturaArchivo) {


}



bool Monstruo::estaVivo(float vida) {
        return vida > 0;
    }



// M�todos de vida
float Monstruo::getVida() const
{
    return _vida;
}

void Monstruo::Sumarvida(float vida)
{
    _vida += vida;
}

void Monstruo::setVida(float vida)
{
    _vida = vida;
}

// M�todos de da�o
float Monstruo::getDanio() const
{
    return _danio;
}

void Monstruo::Sumarataque(float danio)
{
    _danio += danio;
}

void Monstruo::setAtaque(float danio)
{
    _danio=danio;
}


// M�todos de defensa
float Monstruo::getDefensa() const
{
    return _defensa;
}

void Monstruo::setDefensa(float defensa)
{
    _defensa = defensa;
}

// M�todo para obtener el nivel
int Monstruo::getNivel() const
{
    return _nivel;
}

// M�todo para obtener la experiencia actual
float Monstruo::getExperiencia() const
{
    return _experiencia;
}

// M�todo para ganar experiencia y subir de nivel si llega a 100
void Monstruo::ganarExperiencia(float exp)
{
    _experiencia += exp;
    if (_experiencia >= 100)
    {
        _experiencia -= 100; // Reiniciar experiencia
        _nivel++; // Subir de nivel
        _vida += 10; // Aumentar vida
        _defensa += 5; // Aumentar defensa
        _danio += 5; // Aumentar da�o
    }
}
// M�todos para posici�n y escala
void Monstruo::setPosition(float x, float y)
{
    _sprite.setPosition(x, y);
}

void Monstruo::setScale(float x, float y)
{
    _sprite.setScale(x, y);
}

// M�todo para obtener el sprite

const sf::Sprite& Monstruo::getSprite() const
{
    return _sprite;
}

// M�todo protegido para acceder al sprite
sf::Sprite& Monstruo::getSprite()
{
    return _sprite;
}

// M�todo para obtener el nombre
string Monstruo::getNombre() const
{
    return nombre;
}

void Monstruo::setNombre(const std::string& nombre)
{
    this->nombre = nombre;
}

// Sobrecarga del operador ==
bool Monstruo::operator==(const Monstruo& other) const
{
    return _vida == other._vida && _danio == other._danio && _defensa == other._defensa && nombre == other.nombre;
}

// Funci�n para dibujar
void Monstruo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}




// M�todo para cargar la textura del Monstruo
bool Monstruo::cargarTextura(const std::string& archivo)
{
    if (!_texture.loadFromFile(archivo))
    {

        return false;
    }
    _sprite.setTexture(_texture);
    return true;
}

bool Monstruo::atacar(){
    cout << "Atacas al enemigo!" << endl;



}



// Hornerot
Hornerot::Hornerot(float vida, float danio, float defensa, string texturaArchivo) : Monstruo(vida, danio, defensa,texturaArchivo)
{
    if (!cargarTextura(texturaArchivo))
    {
        cout<<"Error al cargar la textura del hornerot"<<endl;
    }
}


// Sobrescribir la funci�n draw
void Hornerot::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Llamar a la funci�n draw de la clase base
    Monstruo::draw(target, states);
    // Aqu� podr�as a�adir c�digo para dibujar elementos espec�ficos del sprite
}

// Sobrescribir la funci�n getBounds
sf::FloatRect Hornerot::getBounds() const
{
    return Hornerot::getBounds();
}

// M�todo para cargar la textura del Dragon
bool Hornerot::cargarTextura(const string& archivo)
{
    if (!_HornerotTexture.loadFromFile(archivo))
    {
        return false;
    }
    getSprite().setTexture(_HornerotTexture);
    return true;

}
//peluchin
Peluchin::Peluchin(float vida, float danio, float defensa, string texturaArchivo) : Monstruo(vida, danio, defensa,texturaArchivo)
{
    if (!cargarTextura(texturaArchivo))
    {
        cout<<"Error al cargar la textura del Peluchin"<<endl;
    }
}


// Sobrescribir la funci�n draw
void Peluchin::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Llamar a la funci�n draw de la clase base
    Monstruo::draw(target, states);
    // Aqu� podr�as a�adir c�digo para dibujar elementos espec�ficos del sprite
}

// Sobrescribir la funci�n getBounds
sf::FloatRect Peluchin::getBounds() const
{
    return Peluchin::getBounds();
}

// M�todo para cargar la textura del Dragon
bool Peluchin::cargarTextura(const string& archivo)
{
    if (!_PeluchinTexture.loadFromFile(archivo))
    {
        return false;
    }
    getSprite().setTexture(_PeluchinTexture);
    return true;

}
//balleton

balleton::balleton(float vida, float danio, float defensa, string texturaArchivo) : Monstruo(vida, danio, defensa,texturaArchivo)
{
    if (!cargarTextura(texturaArchivo))
    {
        cout<<"Error al cargar la textura del balleton"<<endl;
    }
}


// Sobrescribir la funci�n draw
void balleton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Llamar a la funci�n draw de la clase base
    Monstruo::draw(target, states);
    // Aqu� podr�as a�adir c�digo para dibujar elementos espec�ficos del sprite
}

// Sobrescribir la funci�n getBounds
sf::FloatRect balleton::getBounds() const
{
    return balleton::getBounds();
}

// M�todo para cargar la textura del Dragon
bool balleton::cargarTextura(const string& archivo)
{
    if (!_BalletonTexture.loadFromFile(archivo))
    {
        return false;
    }
    getSprite().setTexture(_BalletonTexture);
    return true;

}

// Velom
Velom::Velom(float vida, float danio, float defensa,string texturaArchivo) : Monstruo(vida, danio, defensa,texturaArchivo)
{

if (!cargarTextura(texturaArchivo))
    {
        cout<<"Error al cargar la textura del monstruo"<<endl;
    }
}



// Sobrescribir la funci�n draw
void Velom::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Llamar a la funci�n draw de la clase base
    Monstruo::draw(target, states);
    // Aqu� podr�as a�adir c�digo para dibujar elementos espec�ficos del sprite
}

// Sobrescribir la funci�n getBounds
sf::FloatRect Velom::getBounds() const
{
    return Velom::getBounds();
}

// M�todo para cargar la textura del Dragon
bool Velom::cargarTextura(const string& archivo)
{
    if (!_velomTexture.loadFromFile(archivo))
    {
        return false;
    }
    getSprite().setTexture(_velomTexture);
    return true;
}

//tukin

Tukin::Tukin(float vida, float danio, float defensa, string texturaArchivo) : Monstruo(vida, danio, defensa,texturaArchivo)
{
    if (!cargarTextura(texturaArchivo))
    {
        cout<<"Error al cargar la textura del tukin"<<endl;
    }
}


// Sobrescribir la funci�n draw
void Tukin::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Llamar a la funci�n draw de la clase base
    Monstruo::draw(target, states);
    // Aqu� podr�as a�adir c�digo para dibujar elementos espec�ficos del sprite
}

// Sobrescribir la funci�n getBounds
sf::FloatRect Tukin::getBounds() const
{
    return Tukin    ::getBounds();
}

// M�todo para cargar la textura del Dragon
bool Tukin::cargarTextura(const string& archivo)
{
    if (!_TukinTexture.loadFromFile(archivo))
    {
        return false;
    }
    getSprite().setTexture(_TukinTexture);
    return true;
}
//lechuza
Lechuza::Lechuza(float vida, float danio, float defensa, string texturaArchivo) : Monstruo(vida, danio, defensa,texturaArchivo)
{
    if (!cargarTextura(texturaArchivo))
    {
        cout<<"Error al cargar la textura de la fucking lechuza"<<endl;
    }
}


// Sobrescribir la funci�n draw
void Lechuza::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Llamar a la funci�n draw de la clase base
    Monstruo::draw(target, states);
    // Aqu� podr�as a�adir c�digo para dibujar elementos espec�ficos del sprite
}

// Sobrescribir la funci�n getBounds
sf::FloatRect Lechuza::getBounds() const
{
    return Lechuza::getBounds();
}

// M�todo para cargar la textura del Dragon
bool Lechuza::cargarTextura(const string& archivo)
{
    if (!_LechuzaTexture.loadFromFile(archivo))
    {
        return false;
    }
    getSprite().setTexture(_LechuzaTexture);
    return true;
}
//bufalont
Bufalont::Bufalont(float vida, float danio, float defensa, string texturaArchivo) : Monstruo(vida, danio, defensa,texturaArchivo)
{
    if (!cargarTextura(texturaArchivo))
    {
        cout<<"Error al cargar la textura del bufalont"<<endl;
    }
}


// Sobrescribir la funci�n draw
void Bufalont::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Llamar a la funci�n draw de la clase base
    Monstruo::draw(target, states);
    // Aqu� podr�as a�adir c�digo para dibujar elementos espec�ficos del sprite
}

// Sobrescribir la funci�n getBounds
sf::FloatRect Bufalont::getBounds() const
{
    return Bufalont::getBounds();
}

// M�todo para cargar la textura del Dragon
bool Bufalont::cargarTextura(const string& archivo)
{
    if (!_BufalontTexture.loadFromFile(archivo))
    {
        return false;
    }
    getSprite().setTexture(_BufalontTexture);
    return true;
}
//Lobizon
Lobizon::Lobizon(float vida, float danio, float defensa,string texturaArchivo) : Monstruo(vida, danio, defensa,texturaArchivo)
{
    if (!cargarTextura(texturaArchivo))
    {
        cout<<"Error al cargar la textura del lobizon"<<endl;
    }
}
void Lobizon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Llamar a la funci�n draw de la clase base
    Monstruo::draw(target, states);
    // Aqu� podr�as a�adir c�digo para dibujar elementos espec�ficos del sprite
}

// Sobrescribir la funci�n getBounds
sf::FloatRect Lobizon::getBounds() const
{
    return Lobizon::getBounds();
}

// M�todo para cargar la textura del Dragon
bool Lobizon::cargarTextura(const string& archivo)
{
    if (!_LobizonTexture.loadFromFile(archivo))
    {
        return false;
    }
    getSprite().setTexture(_LobizonTexture);
    return true;
}
