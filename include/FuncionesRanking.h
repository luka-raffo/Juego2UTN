
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

/*
class EscenarioPelea {
private:
    sf::RenderWindow window;
    Juego monstruoJugador;
    Juego monstruoEnemigo;
     SonidoAtaque sonidoAtaque;
    SonidoDefensa sonidoDefensa;
    SonidoPelea sonidoPelea;
    SonidoVictoria sonidoVictoria;
    SonidoDerrota sonidoDerrota;
    SonidoExp sonidoExp;
    BattleBackground fondo;
    CombateConAnimaciones combate;
    sf::Text menuTexto;
    sf::Font font;
    bool turnoJugador;
    bool peleaActiva;

    // Métodos auxiliares
    void inicializarVentana();
    void inicializarMenuTexto();
    void generarMonstruosJugador();
    void seleccionarMonstruoEnemigo();
    void procesarTurnoJugador(sf::Event& event);
    void procesarTurnoEnemigo();
public:
     EscenarioPelea();
    void iniciarPelea();
};
*/
// Clase EscenarioPelea

    class EscenarioPelea {
    private:
         sf::RenderWindow& window;
        SonidoAtaque sonidoAtaque;
        SonidoDefensa sonidoDefensa;
        SonidoPelea sonidoPelea;
        SonidoVictoria sonidoVictoria;
        SonidoDerrota sonidoDerrota;
        SonidoExp sonidoExp;

        // Otros elementos del juego (monstruos, fondo, etc.)
        Juego monstruoJugador;
        Juego monstruoEnemigo;
        BattleBackground fondo;

        AnimacionAtaque ataqueJugador;
        AnimacionAtaque ataqueEnemigo;
        AnimacionDefensa defensa;

        bool turnoJugador;

    public:
        // Constructor
           EscenarioPelea(sf::RenderWindow& w) : window(w), turnoJugador(true) {
        window.setFramerateLimit(60);
    }
        // Inicializa los elementos del juego
        void inicializarJuego();

        // Bucle principal del escenario de pelea
        void ejecutar();

        // Acción de ataque del jugador
        void realizarAtaqueJugador();

        // Acción de ataque del enemigo
        void realizarAtaqueEnemigo();
    };

