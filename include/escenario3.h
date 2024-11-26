#ifndef ESCENARIO3_H
#define ESCENARIO3_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"
#include <SFML/Audio.hpp>
#include "escenario1.h"

using namespace std;


class EscenarioJefe : public EscenarioBase {
public:
    EscenarioJefe() {
        inicializar();
    }

    void cargarTextura() override {
        if (!_texture.loadFromFile("Tileset/SInVALLAS.jpg")) {
            std::cerr << "Error cargando la textura de EscenarioJefe" << std::endl;
        }
    }
};

class CavernaBattleBackground : public EscenarioBase {
public:
    CavernaBattleBackground() {
        inicializar();
        _sprite.setScale(5, 5); // Escalado específico
    }

    void cargarTextura() override {
        if (!_texture.loadFromFile("tileset/cueva2.png")) {
            std::cerr << "Error cargando la textura de CavernaBattleBackground" << std::endl;
        }
    }
};
class caverna : public ObjetoEscenario {
public:
    caverna() {
        _texture.loadFromFile("tileset/Cueva.png");
        _sprite.setTexture(_texture);
    }
};

class vallas : public ObjetoEscenario {
public:
    vallas() {
        _texture.loadFromFile("tileset/Vallas.sprite.jpg");
        _sprite.setTexture(_texture);
    }
};

class suelo : public ObjetoEscenario {
public:
    suelo () {
        _texture.loadFromFile("tileset/suelo.png");
        _sprite.setTexture(_texture);
    }
};


#endif // ESCENARIO3_H
