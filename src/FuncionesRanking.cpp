#include "FuncionesRanking.h"
using namespace std;

EscenarioPelea::EscenarioPelea()
    : window(sf::VideoMode(800, 600), "Inicia la pelea")
{
    window.setFramerateLimit(60);
    srand(static_cast<unsigned>(time(0)));

    configurarSonidos();
    configurarTexto();
    configurarFondo();
    inicializarMonstruos();
}

void EscenarioPelea::configurarSonidos() {
    if (!bufferAtaque.loadFromFile("Sonidos/pew.wav") ||
        !bufferDefensa.loadFromFile("Sonidos/bueeeee.wav") ||
        !bufferPelea.loadFromFile("Sonidos/omg-esto-va-a-ser-epico-papus.wav") ||
        !bufferVictoria.loadFromFile("Sonidos/bokita.wav") ||
        !bufferDerrota.loadFromFile("Sonidos/estoy-cansado-jefe.wav") ||
        !bufferExp.loadFromFile("Sonidos/orb.wav")) {
        cerr << "Error al cargar los sonidos" << endl;
    }
    animacionAtaqueJugador.setRutaPNG("Animations/zoonami_player_vice_grip_animation.PNG");
    animacionDefensa.setRutaPNG("Animations/zoonami_enemy_smog_animation.PNG");
    animacionAtaqueEnemigo.setRutaPNG("Animations/zoonami_player_vice_grip_animation.PNG");

    sonidoAtaque.setBuffer(bufferAtaque);
    sonidoDefensa.setBuffer(bufferDefensa);
    sonidoPelea.setBuffer(bufferPelea);
    sonidoVictoria.setBuffer(bufferVictoria);
    sonidoDerrota.setBuffer(bufferDerrota);
    sonidoExp.setBuffer(bufferExp);
}

void EscenarioPelea::configurarTexto() {
    if (!font.loadFromFile("include/Pokemon.ttf")) {
        cerr << "Error al cargar la fuente" << endl;
    }
    menuTexto.setString("1) Atacar  2) Defender");
    menuTexto.setFont(font);
    menuTexto.setCharacterSize(24);
    menuTexto.setFillColor(sf::Color::Black);
    menuTexto.setPosition(350, 400);


}

void EscenarioPelea::configurarFondo() {
    // Configuración de fondo si es necesario

}

void EscenarioPelea::inicializarMonstruos() {
   monstruoJugador.agregarMonstruo(new Velom(150.0f, 50.0f, 30.0f, "include/velom.PNG"));
    monstruoJugador.agregarMonstruo(new Bufalont (150.0f, 50.0f, 30.0f, "include/bufalont.PNG"));
    monstruoJugador.agregarMonstruo(new Tukin(150.0f, 50.0f, 30.0f, "include/tukin.PNG"));
    monstruoJugador.agregarMonstruo(new Lechuza(150.0f, 50.0f, 30.0f, "include/FuckingLechuza.PNG"));
    monstruoJugador.agregarMonstruo(new Peluchin(150.0f, 50.0f, 30.0f, "include/pelucin.PNG"));
    monstruoJugador.agregarMonstruo(new balleton(150.0f, 50.0f, 30.0f, "include/balleton.PNG"));
    // Agregar más monstruos según sea necesario...

    monstruoJugador.setPositionTodosMonstruos(70, 475);
    monstruoJugador.setScale(2, 2);

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

void EscenarioPelea::logicaTurnoJugador(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1) {
        cout << "Atacas al enemigo!" << endl;
        sonidoAtaque.play();
        animacionAtaqueJugador.startAnimation();

                    b_ataqueJugador=true;

                    if (monstruoEnemigo.getDefensaMonstruoActual() > monstruoJugador.getDanioMonstruoActual())
                    {
                        cout << "El enemigo ah bloqueado tu ataque!" << endl;
                        cout << "La vida del enemigo es: "<< monstruoEnemigo.getVidaMonstruoActual()<<endl;

                        monstruoEnemigo.setDefensaMonstruoActual(monstruoEnemigo.getDefensaMonstruoActual()-monstruoJugador.getDanioMonstruoActual());
                    }
                    else if(monstruoJugador.getDefensaMonstruoActual()<=monstruoEnemigo.getDanioMonstruoActual())
                    {

                        cout << "Tu Monstruo ah hecho " << monstruoJugador.getDanioMonstruoActual()<<" de daño" << endl;


                        monstruoEnemigo.setVidaMonstruoActual(monstruoEnemigo.getVidaMonstruoActual()+monstruoEnemigo.getDefensaMonstruoActual()-monstruoJugador.getDanioMonstruoActual());

                        cout << "La vida del enemigo es: "<< monstruoEnemigo.getVidaMonstruoActual() << endl;

                        monstruoEnemigo.setDefensaMonstruoActual(0);
                    }
        turnoJugador = false;
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2) {
        cout << "Te defiendes!" << endl;
        sonidoDefensa.play();
        animacionDefensa.startAnimation();
        monstruoJugador.setDefensaMonstruoActual( rand() % 100 + 1);
        cout<<"defensa mi monstruo aumento = "<<monstruoJugador.getDefensaMonstruoActual()<<endl;
        turnoJugador=false;
        cout<<"La vida de tu monstruo es : "<<monstruoJugador.getVidaMonstruoActual()<< endl;
    }

    if (monstruoJugador.getVidaMonstruoActual() <= 0) {
        monstruoJugador.pasarAlSiguienteMonstruo();
    }
}

void EscenarioPelea::logicaTurnoEnemigo() {
    cout << "El enemigo ataca!" << endl;
    // Probabilidad de curación para el enemigo
    int probabilidadCura = rand() % 100;
    if (probabilidadCura < 20) {  // 20% de probabilidad de curación
        float curacion = 60.0f;
        monstruoEnemigo.setVidaMonstruoActual(monstruoEnemigo.getVidaMonstruoActual() + curacion);
        cout << "El enemigo se ha curado " << curacion << " puntos de vida." << endl;
        // Cambiar turno al jugador después de curarse
        turnoJugador = true;
        cout <<" su vida es : "<< monstruoEnemigo.getVidaMonstruoActual() << " puntos de vida. "<< endl;
    } else {
        // Lógica de ataque del enemigo
        if (monstruoJugador.getDefensaMonstruoActual() > monstruoEnemigo.getDefensaMonstruoActual()) {
            cout << "El ataque fue bloqueado con éxito!" << endl;
            monstruoJugador.setDefensaMonstruoActual(monstruoJugador.getDefensaMonstruoActual() - monstruoEnemigo.getDanioMonstruoActual());
                    animacionAtaqueEnemigo.startAnimation();
            turnoJugador = true;
        } else if (monstruoJugador.getDefensaMonstruoActual() <= monstruoEnemigo.getDanioMonstruoActual()) {
            cout << "El enemigo ha hecho: " << monstruoEnemigo.getDanioMonstruoActual() << endl;

            monstruoJugador.setVidaMonstruoActual(monstruoJugador.getVidaMonstruoActual() + monstruoJugador.getDefensaMonstruoActual() - monstruoEnemigo.getDanioMonstruoActual());
            cout << "La vida de tu monstruo es: " << monstruoJugador.getVidaMonstruoActual() << endl;

            monstruoJugador.setDefensaMonstruoActual(0);

            // Cambiar turno al jugador
            turnoJugador = true;
        }
        cout << "Defensa de mi monstruo = " << monstruoJugador.getDefensaMonstruoActual() << endl;
    }
    turnoJugador = true;
}

void EscenarioPelea::mostrarMensajeFinal(const string& mensaje) {
    menuTexto.setString(mensaje);
    menuTexto.setCharacterSize(60);
    menuTexto.setFillColor(sf::Color::Black);
    menuTexto.setPosition(150, 170);

    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 3.0f) {
        window.clear();
        window.draw(fondo);
        window.draw(menuTexto);
        window.display();
    }
}

void EscenarioPelea::iniciar() {
    while (window.isOpen() && peleaActiva) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }

            if (turnoJugador) {
                logicaTurnoJugador(event);
            } else {
                logicaTurnoEnemigo();
            }
        }

        if (monstruoEnemigo.getVidaMonstruoActual() <= 0) {
            mostrarMensajeFinal("Eres el vencedor!");
            peleaActiva = false;
        }


        animacionAtaqueJugador.update();
        animacionDefensa.update();

        window.clear();
        window.draw(fondo);
        window.draw(menuTexto);
        monstruoJugador.dibujar(window);
        monstruoEnemigo.dibujar(window);
        window.draw(animacionAtaqueJugador);
        window.draw(animacionDefensa);

        window.display();
    }
}

Batallacaverna::Batallacaverna()
    : _window(sf::VideoMode(800, 600), "Inicia la pelea"),
      _turnoJugador(true),
      _peleaActiva(true),
      _enemigo(500.0f, 60.0f, 50.0f, "include/Lobizon.PNG") {
    _window.setFramerateLimit(60);
    inicializarVentana();
    inicializarSonidos();
    inicializarMenu();
    inicializarMonstruos();
}

void Batallacaverna::inicializarVentana() {
    _ataque.setRutaPNG("Animations/zoonami_player_vice_grip_animation.PNG");
}

void Batallacaverna::inicializarSonidos() {
    _bufferAtaque.loadFromFile("Sonidos/pew.wav");
    _bufferDefensa.loadFromFile("Sonidos/bueeeee.wav");
    _bufferPelea.loadFromFile("Sonidos/dificil.wav");
    _bufferVictoria.loadFromFile("Sonidos/bokita.wav");

    _sonidoAtaque.setBuffer(_bufferAtaque);
    _sonidoDefensa.setBuffer(_bufferDefensa);
    _sonidoPelea.setBuffer(_bufferPelea);
    _sonidoVictoria.setBuffer(_bufferVictoria);
}

void Batallacaverna::inicializarMenu() {
    _font.loadFromFile("include/Pokemon.ttf");
    _menuTexto.setFont(_font);
    _menuTexto.setString("1) Atacar  2) Defender");
    _menuTexto.setCharacterSize(24);
    _menuTexto.setFillColor(sf::Color::Black);
    _menuTexto.setPosition(500, 500);
}

void Batallacaverna::inicializarMonstruos() {
    _monstruoJugador.agregarMonstruo(new Velom(190.0f, 50.0f, 40.0f, "include/velom.PNG"));
    _monstruoJugador.agregarMonstruo(new Bufalont(150.0f, 50.0f, 40.0f, "include/bufalont.PNG"));
    _monstruoJugador.agregarMonstruo(new Tukin(150.0f, 50.0f, 40.0f, "include/tukin.PNG"));
    _monstruoJugador.agregarMonstruo(new Lechuza(150.0f, 50.0f, 40.0f, "include/FuckingLechuza.PNG"));
    _monstruoJugador.agregarMonstruo(new balleton(150.0f, 50.0f, 40.0f, "include/balleton.PNG"));
    _monstruoJugador.agregarMonstruo(new Peluchin(150.0f, 50.0f, 40.0f, "include/pelucin.PNG"));

    _monstruoJugador.setPositionTodosMonstruos(70, 470);
    _monstruoJugador.setScale(2, 2);

    _enemigo.setPosition(520, 100);
    _enemigo.setScale(2, 2);
}

void Batallacaverna::manejarEventos() {
      sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            _window.close();
        }

        if (_turnoJugador) {
            logicaTurnoJugador(event);
        } else {
            logicaTurnoEnemigo();
        }
    }
}

void Batallacaverna::logicaTurnoJugador(sf::Event& event) {

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1) {
        std::cout << "Atacas al enemigo!" << std::endl;
        _sonidoAtaque.play();
        _ataque.startAnimation();

        if (_enemigo.getDefensa() > _monstruoJugador.getDanioMonstruoActual()) {
            std::cout << "El enemigo ha bloqueado tu ataque!" << std::endl;
            _enemigo.setDefensa(_enemigo.getDefensa() - _monstruoJugador.getDanioMonstruoActual());
        } else {
            std::cout << "Tu monstruo ha hecho " << _monstruoJugador.getDanioMonstruoActual() << " de daño." << std::endl;
            _enemigo.setVida(_enemigo.getVida() + _enemigo.getDefensa() - _monstruoJugador.getDanioMonstruoActual());
            _enemigo.setDefensa(0);
        }
        _turnoJugador = false;
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2) {
        std::cout << "Te defiendes!" << std::endl;
        _sonidoDefensa.play();
        _defensa.startAnimation();
        _monstruoJugador.setDefensaMonstruoActual(rand() % 100 + 1);
        std::cout << "Defensa de tu monstruo aumentó a: " << _monstruoJugador.getDefensaMonstruoActual() << std::endl;
        _turnoJugador = false;
    }

    if (_monstruoJugador.getVidaMonstruoActual() <= 0) {
        _monstruoJugador.pasarAlSiguienteMonstruo();
    }

}

void Batallacaverna::logicaTurnoEnemigo() {
    std::cout << "El enemigo ataca!" << std::endl;

    int probabilidadCura = rand() % 100;
    if (probabilidadCura < 20) {
        float curacion = 60.0f;
        _enemigo.setVida(_enemigo.getVida() + curacion);
        std::cout << "El enemigo se ha curado " << curacion << " puntos de vida." << std::endl;
    } else {
        if (_monstruoJugador.getDefensaMonstruoActual() > _enemigo.getDanio()) {
            std::cout << "El ataque fue bloqueado con éxito!" << std::endl;
            _monstruoJugador.setDefensaMonstruoActual(_monstruoJugador.getDefensaMonstruoActual() - _enemigo.getDanio());
            _ataque.startAnimation();
        } else {
            std::cout << "El enemigo ha hecho: " << _enemigo.getDanio() << std::endl;
            _monstruoJugador.setVidaMonstruoActual(_monstruoJugador.getVidaMonstruoActual() +
                                                   _monstruoJugador.getDefensaMonstruoActual() - _enemigo.getDanio());
            std::cout << "La vida de tu monstruo es: " << _monstruoJugador.getVidaMonstruoActual() << std::endl;
            _monstruoJugador.setDefensaMonstruoActual(0);
        }
    }
    _turnoJugador = true;
}

void Batallacaverna::actualizar() {
    _ataque.update();
    _defensa.update();

    if (_enemigo.getVida() <= 0) {
        manejarVictoria();
    }
}

void Batallacaverna::dibujar() {
    _window.clear();
    _window.draw(_fondo);
    _window.draw(_enemigo);
    _window.draw(_menuTexto);
    _window.draw(_ataque);
    _window.draw(_defensa);
    _monstruoJugador.dibujar(_window);
    _window.display();
}

void Batallacaverna::finReloj(sf::Clock clock){
    sf::Time tiempoTranscurrido = clock.getElapsedTime();
    float segundos = tiempoTranscurrido.asSeconds();
    cout<<"haz acabado el juego en: " << segundos<<endl;
}


void Batallacaverna::manejarVictoria() {
    _menuTexto.setString("Eres el vencedor");
    _menuTexto.setCharacterSize(60);

    _menuTexto.setPosition(150, 170);
    _sonidoVictoria.play();
    _peleaActiva = false;

}

void Batallacaverna::iniciar(sf::Clock clock) {
    while (_window.isOpen() && _peleaActiva) {

        manejarEventos();
        actualizar();
        dibujar();
        }

    }

