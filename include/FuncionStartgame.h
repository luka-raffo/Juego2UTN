#ifndef FUNCIONSTARTGAME_H_INCLUDED
#define FUNCIONSTARTGAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Personaje.h>
#include <iostream>
#include "menu.h"
#include <ctime>
#include <fstream>  // Para leer y escribir archivos
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
    Sonido(const std::string& archivoSonido) : archivo(archivoSonido) {
        if (!buffer.loadFromFile(archivo)) {
            std::cerr << "Error al cargar " << archivo << std::endl;
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
        std::cout << "Sonido base cargado desde: " << archivo << std::endl;
    }
};
class SonidoAtaque : public Sonido {
public:
    SonidoAtaque() : Sonido("Sonidos/pew.wav") {}
    void informacion() const override {
        std::cout << "Sonido de ataque: pew.wav" << std::endl;
    }
};

class SonidoDefensa : public Sonido {
public:
    SonidoDefensa() : Sonido("Sonidos/bueeeee.wav") {}
    void informacion() const override {
        std::cout << "Sonido de defensa: bueeeee.wav" << std::endl;
    }
};

class SonidoPelea : public Sonido {
public:
    SonidoPelea() : Sonido("Sonidos/omg-esto-va-a-ser-epico-papus.wav") {}
    void informacion() const override {
        std::cout << "Sonido de pelea épica: omg-esto-va-a-ser-epico-papus.wav" << std::endl;
    }
};

class SonidoVictoria : public Sonido {
public:
    SonidoVictoria() : Sonido("Sonidos/bokita.wav") {}
    void informacion() const override {
        std::cout << "Sonido de victoria: bokita.wav" << std::endl;
    }
};

class SonidoDerrota : public Sonido {
public:
    SonidoDerrota() : Sonido("Sonidos/estoy-cansado-jefe.wav") {}
    void informacion() const override {
        std::cout << "Sonido de derrota: estoy-cansado-jefe.wav" << std::endl;
    }
};

class SonidoExp : public Sonido {
public:
    SonidoExp() : Sonido("Sonidos/orb.wav") {}
    void informacion() const override {
        std::cout << "Sonido de experiencia: orb.wav" << std::endl;
    }
};
/*
class Combate {
protected:
    Monstruo& enemigo;
    Juego& monstruoJugador;
    sf::RenderWindow& ventana;
    sf::Text menuTexto;

    // Animaciones
    AnimacionAtaque animacionAtaqueJugador;
    AnimacionAtaque animacionAtaqueEnemigo;
    AnimacionDefensa animacionDefensa;

    // Sonidos (polimórficos)
    SonidoAtaque sonidoAtaque;
    SonidoDefensa sonidoDefensa;
    SonidoVictoria sonidoVictoria;
    SonidoDerrota sonidoDerrota;
    SonidoPelea sonidoPelea;
    SonidoExp sonidoExp;

    // Variables
    bool turnoJugador;
    bool peleaActiva;

public:
    Combate(Monstruo& enemigo, Juego& monstruoJugador, sf::RenderWindow& ventana, sf::Text& menuTexto);
    virtual ~Combate() = default;

    virtual void iniciar();
    virtual void turnoDelJugador(sf::Event& event);
    virtual void turnoDelEnemigo();
    virtual void verificarEstado();
    void reproducirSonido(Sonido& sonido);
};

class CombateConAnimaciones : public Combate {
public:
    CombateConAnimaciones(Monstruo& enemigo, Juego& monstruoJugador, sf::RenderWindow& ventana, sf::Text& menuTexto);
    void iniciar() override;
    void turnoDelJugador(sf::Event& event) override;
    void turnoDelEnemigo() override;
    void verificarEstado() override;
};
*/

#endif // FUNCIONSTARTGAME_H_INCLUDED
