#ifndef FUNCIONSTARTGAME_H_INCLUDED
#define FUNCIONSTARTGAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Personaje.h>
#include <iostream>
#include "menu.h"
#include <ctime>
#include <stdlib.h>
#include "escenario1.h"
#include "Monstruo.h"
#include "Escenario2.h"
#include "escenario3.h"
#include "Juego.h"


using namespace std;
void manejarCombate();
void escenarioPelea();
////sonidosss
class Sonido {
private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
    std::string archivo;

public:
    Sonido(const string& archivoSonido) : archivo(archivoSonido) {
        if (!buffer.loadFromFile(archivo)) {
            cout << "Error al cargar " << archivo << endl;
        } else {
            sound.setBuffer(buffer);
        }
    }

    virtual ~Sonido() = default;

    void reproducir() {
        sound.play();
    }

    void detener() {
        sound.stop();
    }

    void setVolumen(float volumen) {
        sound.setVolume(volumen);
    }

    virtual void informacion() const {
        cout << "Sonido base cargado desde: " << archivo << endl;
    }
};
class SonidoAtaque : public Sonido {
public:
    SonidoAtaque() : Sonido("Sonidos/pew.wav") {}
    void informacion() const override {
        cout << "Sonido de ataque: pew.wav" << endl;
    }
};

class SonidoDefensa : public Sonido {
public:
    SonidoDefensa() : Sonido("Sonidos/bueeeee.wav") {}
    void informacion() const override {
       cout << "Sonido de defensa: bueeeee.wav" << endl;
    }
};

class SonidoPelea : public Sonido {
public:
    SonidoPelea() : Sonido("Sonidos/omg-esto-va-a-ser-epico-papus.wav") {}
    void informacion() const override {
        cout << "Sonido de pelea épica: omg-esto-va-a-ser-epico-papus.wav" << endl;
    }
};

class SonidoVictoria : public Sonido {
public:
    SonidoVictoria() : Sonido("Sonidos/bokita.wav") {}
    void informacion() const override {
        cout << "Sonido de victoria: bokita.wav" << endl;
    }
};

class SonidoDerrota : public Sonido {
public:
    SonidoDerrota() : Sonido("Sonidos/estoy-cansado-jefe.wav") {}
    void informacion() const override {
       cout << "Sonido de derrota: estoy-cansado-jefe.wav" << endl;
    }
};

class SonidoExp : public Sonido {
public:
    SonidoExp() : Sonido("Sonidos/orb.wav") {}
    void informacion() const override {
        std::cout << "Sonido de experiencia: orb.wav" << std::endl;
    }
};


#endif // FUNCIONSTARTGAME_H_INCLUDED
