#include "FuncionesRanking.h"
/*
void EscenarioPelea::inicializarVentana() {
    window.create(sf::VideoMode(800, 600), "Inicia la pelea");
    window.setFramerateLimit(60);
}

void EscenarioPelea::inicializarMenuTexto() {
    font.loadFromFile("include/Pokemon.ttf");
    menuTexto.setFont(font);
    menuTexto.setString("1) Atacar  2) Defender");
    menuTexto.setCharacterSize(24);
    menuTexto.setFillColor(sf::Color::Black);
    menuTexto.setPosition(350, 400);
}


void EscenarioPelea::generarMonstruosJugador() {
    monstruoJugador.agregarMonstruo(new Velom(150.0f, 50.0f, 30.0f, "include/velom.PNG"));
    monstruoJugador.agregarMonstruo(new Bufalont(150.0f, 50.0f, 30.0f, "include/bufalont.PNG"));
    monstruoJugador.agregarMonstruo(new Tukin(150.0f, 50.0f, 30.0f, "include/tukin.PNG"));
    monstruoJugador.agregarMonstruo(new Lechuza(150.0f, 50.0f, 30.0f, "include/FuckingLechuza.PNG"));
    monstruoJugador.setPositionTodosMonstruos(50, 500);
    monstruoJugador.setScale(2, 2);
}

void EscenarioPelea::seleccionarMonstruoEnemigo() {
    int probabilidad = std::rand() % 100;
    if (probabilidad < 20) {
        monstruoEnemigo.agregarMonstruo(new Tukin(150.0f, 50.0f, 30.0f, "include/tukin.PNG"));
    } else if (probabilidad < 40) {
        monstruoEnemigo.agregarMonstruo(new Velom(150.0f, 50.0f, 30.0f, "include/velom.PNG"));
    } else {
        monstruoEnemigo.agregarMonstruo(new Bufalont(150.0f, 50.0f, 30.0f, "include/bufalont.PNG"));
    }
    monstruoEnemigo.setScale(2, 2);
    monstruoEnemigo.setPosition(570, 160);
}

void EscenarioPelea::procesarTurnoJugador(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Num1) {
            combate.realizarAtaque(monstruoJugador, monstruoEnemigo);
            sonidoAtaque.reproducir();
            turnoJugador = false;
        } else if (event.key.code == sf::Keyboard::Num2) {
            combate.realizarDefensa(monstruoJugador);
            sonidoDefensa.reproducir();
            turnoJugador = false;
        }
    }
}

void EscenarioPelea::procesarTurnoEnemigo() {
    combate.realizarAtaque(monstruoEnemigo, monstruoJugador);
    turnoJugador = true;
}

EscenarioPelea::EscenarioPelea(): turnoJugador(true), peleaActiva(true) {
    inicializarVentana();
    inicializarMenuTexto();
    generarMonstruosJugador();
    seleccionarMonstruoEnemigo();
}

void EscenarioPelea::iniciarPelea() {
    while (window.isOpen() && peleaActiva) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
            if (turnoJugador) {
                procesarTurnoJugador(event);
            }
        }
        if (!turnoJugador) {
            procesarTurnoEnemigo();
        }

        window.clear();
        window.draw(fondo);
        monstruoJugador.dibujar(window);
        monstruoEnemigo.dibujar(window);
        window.draw(menuTexto);
        window.display();
    }
    }*/
//////////////////////////////////////////
////////////////////////////

// Inicializa los elementos del juego
void EscenarioPelea::inicializarJuego() {
    // Configurar monstruos del jugador
    monstruoJugador.agregarMonstruo(new Velom(150.0f, 50.0f, 30.0f, "include/velom.PNG"));
    monstruoJugador.agregarMonstruo(new Bufalont(150.0f, 50.0f, 30.0f, "include/bufalont.PNG"));
    monstruoJugador.agregarMonstruo(new Tukin(150.0f, 50.0f, 30.0f, "include/tukin.PNG"));
    monstruoJugador.agregarMonstruo(new Lechuza(150.0f, 50.0f, 30.0f, "include/FuckingLechuza.PNG"));
    monstruoJugador.agregarMonstruo(new Peluchin(150.0f, 50.0f, 30.0f, "include/pelucin.PNG"));
    monstruoJugador.agregarMonstruo(new balleton(150.0f, 50.0f, 30.0f, "include/balleton.PNG"));

    monstruoJugador.setPositionTodosMonstruos(50, 500);
    monstruoJugador.setScale(2, 2);

    // Inicializar fondo de batalla
   fondo.inicializar("backgrounds/battle_background.png");

    // Configurar animaciones
    ataqueJugador.setRutaPNG("Animations/zoonami_player_vice_grip_animation.PNG");
    ataqueEnemigo.setRutaPNG("Animations/zoonami_enemy_aqua_jet_animation.PNG");
}

// Bucle principal del escenario de pelea
void EscenarioPelea::ejecutar() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Simulación de acciones
        if (turnoJugador) {
            realizarAtaqueJugador();
            turnoJugador = false;
        } else {
            realizarAtaqueEnemigo();
            turnoJugador = true;
        }

        // Renderizar
        window.clear();
       fondo.draw(window, sf::RenderStates::Default);

        monstruoJugador.dibujar(window);
        monstruoEnemigo.dibujar(window);
        // Dibujar monstruos, animaciones, etc.
        window.display();
    }
}

// Acción de ataque del jugador
void EscenarioPelea::realizarAtaqueJugador() {
    std::cout << "El jugador realiza un ataque." << std::endl;
    sonidoAtaque.reproducir();
    // Simular animación de ataque del jugador
    ataqueJugador.startAnimation();
}

// Acción de ataque del enemigo
void EscenarioPelea::realizarAtaqueEnemigo() {
    std::cout << "El enemigo realiza un ataque." << std::endl;
    sonidoDefensa.reproducir();
    // Simular animación de ataque del enemigo
    ataqueEnemigo.startAnimation();

}
