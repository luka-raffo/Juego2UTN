#ifndef ESCENARIO1_H_INCLUDED
#define ESCENARIO1_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"
#include <SFML/Audio.hpp>

using namespace std;

class EscenarioBase : public sf::Drawable {
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    EscenarioBase() {
        _sprite.setPosition(0, 0); // Posición común
    }

    virtual ~EscenarioBase() {}

    // Método virtual puro para cargar la textura específica de cada escenario
    virtual void cargarTextura() = 0;

   void inicializar() {
    cargarTextura(); // Usar el método virtual puro
    _sprite.setTexture(_texture);
}

 void inicializar(const string& rutaTextura) {
    if (!_texture.loadFromFile(rutaTextura)) {
        cout << "Error cargando la textura desde " << rutaTextura << endl;
    }
    _sprite.setTexture(_texture);
}
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
};


class EscenarioLlegada : public EscenarioBase {
public:
    EscenarioLlegada() {
        inicializar();
    }

    void cargarTextura() override {
        if (!_texture.loadFromFile("sprites/background/Lienzo3.JPG")) {
            cout << "Error cargando la textura de EscenarioLlegada" << endl;
        }
    }
};
class ObjetoEscenario : public sf::Drawable, public Colisionable {
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
   ObjetoEscenario() { cout << "Objeto creado.\n"; }
    virtual ~ObjetoEscenario() {cout << "Objeto destruido.\n"; }

    void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    }

    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }

    sf::FloatRect getBounds() const override {
        return _sprite.getGlobalBounds();
    }
};
class Barrera : public ObjetoEscenario {
public:
    Barrera() {
        // Carga textura y configuración inicial
        _texture.loadFromFile("Sprites/Edificio/Casa.png");
        _sprite.setTexture(_texture);
    }
};

class Barcito : public ObjetoEscenario {
public:
    Barcito() {
        _texture.loadFromFile("Sprites/Edificio/Barcito1.png");
        _sprite.setTexture(_texture);
    }
};

class Flores : public ObjetoEscenario {
public:
    Flores() {
        _texture.loadFromFile("Sprites/Edificio/Flores1.png");
        _sprite.setTexture(_texture);
    }
};
class Cerco : public ObjetoEscenario {
public:
    Cerco() {
        _texture.loadFromFile("Sprites/Edificio/Cerco1.png");
        _sprite.setTexture(_texture);
    }
};
class pasto : public ObjetoEscenario {
public:
    pasto() {
        _texture.loadFromFile("sprites/Edificio/piso1.png");
        _sprite.setTexture(_texture);
    }
};




#endif // ESCENARIO1_H_INCLUDED
