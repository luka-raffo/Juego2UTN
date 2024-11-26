#ifndef ESCENARIO2_H
#define ESCENARIO2_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"
#include "escenario1.h"

using namespace std;
class escenario : public EscenarioBase {
public:
    Escenario() {
        inicializar();
    }

    void cargarTextura() override {
        if (!_texture.loadFromFile("Tileset/nuevo.JPG")) {
            std::cerr << "Error cargando la textura de Escenario" << std::endl;
        }
    }
};

class BattleBackground : public EscenarioBase {
public:
    BattleBackground() {
        inicializar();
        _sprite.setScale(5, 5); // Escalado específico
    }

    void cargarTextura() override {
        if (!_texture.loadFromFile("Battle Backgrounds/With Textboxes/BattleBackground.png")) {
            std::cerr << "Error cargando la textura de BattleBackground" << std::endl;
        }
    }
};

class bush : public ObjetoEscenario {
public:
    bush() {
        _texture.loadFromFile("arbustos4x4.PNG");
        _sprite.setTexture(_texture);
    }
};
class bush6x4 : public ObjetoEscenario {
public:
    bush6x4() {
        _texture.loadFromFile("arbustos4x4.PNG");
        _sprite.setTexture(_texture);
    }
};
class piso : public ObjetoEscenario {
public:
    piso() {
        _texture.loadFromFile("tileset/piso.png");
        _sprite.setTexture(_texture);
    }
};
class arboles : public ObjetoEscenario {
public:
    arboles() {
        _texture.loadFromFile("tileset/arboles.png");
        _sprite.setTexture(_texture);
    }
};




#endif // ESCENARIO2_H
