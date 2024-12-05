
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
#include "FuncionStartgame.h"
class EscenarioPelea {
private:
    sf::RenderWindow window;
    sf::Text menuTexto;
    sf::Font font;

    Juego monstruoJugador;
    Juego monstruoEnemigo;

    AnimacionAtaque animacionAtaqueJugador;
    AnimacionAtaque animacionAtaqueEnemigo;
    AnimacionDefensa animacionDefensa;

    sf::SoundBuffer bufferAtaque, bufferDefensa, bufferPelea, bufferVictoria, bufferDerrota, bufferExp;
    sf::Sound sonidoAtaque, sonidoDefensa, sonidoPelea, sonidoVictoria, sonidoDerrota, sonidoExp;

    BattleBackground fondo;

    bool turnoJugador = true;
    bool peleaActiva = true;
    bool b_ataqueJugador=true;
    void configurarSonidos();
    void configurarTexto();
    void configurarFondo();
    void inicializarMonstruos();
    void logicaTurnoJugador(sf::Event& event);
    void logicaTurnoEnemigo();
    void mostrarMensajeFinal(const std::string& mensaje);

public:
    EscenarioPelea();
    void iniciar();
};
class Batallacaverna {
private:
    sf::RenderWindow _window;
    CavernaBattleBackground _fondo;
    AnimacionAtaque _ataque;
    AnimacionDefensa _defensa;

    sf::SoundBuffer _bufferAtaque, _bufferDefensa, _bufferPelea, _bufferVictoria;
    sf::Sound _sonidoAtaque, _sonidoDefensa, _sonidoPelea, _sonidoVictoria;

    sf::Font _font;
    sf::Text _menuTexto;

    Juego _monstruoJugador;
    Lobizon _enemigo;

    bool _turnoJugador;
    bool _peleaActiva;
   bool b_ataqueJugador=true;
    void inicializarVentana();
    void inicializarSonidos();
    void inicializarMenu();
    void inicializarMonstruos();
    void manejarEventos();
    void actualizar();
    void dibujar();
    void logicaTurnoJugador(sf::Event& event);
    void logicaTurnoEnemigo();
    void manejarVictoria();

public:
    Batallacaverna();
    void iniciar();
};


