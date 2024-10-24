#include "Funciones.h"
#include "inventory.h"
#include "Personaje.h"

using namespace std;

void escenarioPelea() {
        // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia la pelea");

    // Establecer el l�mite de FPS
    window.setFramerateLimit(60);

    inventory inventario(100);

    // Crear los monstruos
    Hornerot monstruo;
    Pelucin pelu;
    Tukin tuki;
    Velom vel("vilom");
    Lechuza lechu;
    Balleton ballena;
    Bufalont bufalo;

    // Dibujar el fondo
    BattleBackground fondo;

    // Seleccionar un monstruo aleatorio con probabilidades distintas
    int probabilidad = std::rand() % 100;  // Generar un n�mero entre 0 y 99 (100 posibles valores)
    sf::Drawable* monstruoSeleccionado = nullptr;

    // Asignar monstruo seg�n probabilidad
    if (probabilidad < 0) {  // 20% de probabilidad para Hornerot
        monstruo.setPosition(570, 160);
        monstruoSeleccionado = &monstruo;
        cout<<"entro al if"<<endl;
    }


    else if (probabilidad < 35) {  // 15% de probabilidad para Pelucin (20 + 15 = 35)
        pelu.setPosition(570, 160);
        monstruoSeleccionado = &pelu;
    }


    else if (probabilidad < 60) {  // 25% de probabilidad para Tukin (35 + 25 = 60)
        tuki.setPosition(570, 160);
        monstruoSeleccionado = &tuki;
    }


    else if (probabilidad < 100) {  // 10% de probabilidad para Velom (60 + 10 = 70)
        vel.setPosition(570, 160);
        monstruoSeleccionado = &vel;
        cout<<"hola"<<endl;
        inventario.agregarItem(vel);
        inventario.mostrarInventario();
    }


    else if (probabilidad < 80) {  // 10% de probabilidad para Lechuza (70 + 10 = 80)
        lechu.setPosition(570, 160);
        monstruoSeleccionado = &lechu;
    }


    else if (probabilidad < 90) {  // 10% de probabilidad para Balleton (80 + 10 = 90)
        ballena.setPosition(570, 160);
        monstruoSeleccionado = &ballena;
    }


    else {  // 10% de probabilidad para Bufalont (90 a 99)
        bufalo.setPosition(570, 160);
        monstruoSeleccionado = &bufalo;
    }

    // Bucle del juego
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Salir del escenario al presionar ESC
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Limpiar la pantalla
        window.clear();

        // Dibujar el fondo
        window.draw(fondo);

        // Dibujar el monstruo seleccionado
        if (monstruoSeleccionado != nullptr) {
            window.draw(*monstruoSeleccionado);
        }else{cout<<"mamahuevo"<<endl;}

        // Mostrar lo dibujado
        window.display();
    }
}
/*
void escenarioPelea() {
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia la pelea");
    window.setFramerateLimit(60);

    inventory inventario(100);

    // Crear los monstruos
    Hornerot monstruoJugador;  // Monstruo controlado por el jugador
    Pelucin enemigo;           // Monstruo enemigo

    // Dibujar el fondo
    BattleBackground fondo;

    // Variables de pelea
    bool turnoJugador = true;  // Variable para alternar los turnos
    bool capturable = false;   // Indica si el monstruo puede ser capturado
    bool peleaActiva = true;

    // Bucle del juego
    while (window.isOpen() && peleaActiva) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Salir del escenario al presionar ESC
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Limpiar la pantalla
        window.clear();

        // Dibujar el fondo
        window.draw(fondo);

        // Dibujar los monstruos
        window.draw(monstruoJugador);
        window.draw(enemigo);

        // L�gica de pelea por turnos
        if (turnoJugador) {
            // Submen� para que el jugador elija la acci�n: atacar, defender, capturar (si es posible)
            cout << "Elige una acci�n: 1) Atacar 2) Defender";
            if (capturable) {
                cout << " 3) Capturar" << endl;
            } else {
                cout << endl;
            }

            int opcion;
            cin >> opcion;

            if (opcion == 1) {  // Atacar
                cout << "Atacas al enemigo!" << endl;
                enemigo.Sumarvida(-monstruoJugador.getDanio());
            } else if (opcion == 2) {  // Defender
                cout << "Te defiendes!" << endl;
                float defensaTotal = monstruoJugador.getDefensa();
                if (defensaTotal > enemigo.getDanio()) {
                    cout << "El ataque fue bloqueado!" << endl;
                } else {
                    float danioRecibido = enemigo.getDanio() - defensaTotal;
                    monstruoJugador.Sumarvida(-danioRecibido);
                    cout << "Recibiste " << danioRecibido << " de da�o." << endl;
                }
            } else if (opcion == 3 && capturable) {  // Capturar
                cout << "Intentas capturar al enemigo!" << endl;
                int probCaptura = rand() % 100;
                if (probCaptura < 50) {  // Supongamos una chance de 50%
                    cout << "Capturaste al enemigo!" << endl;
                   // inventario.agregarItem(enemigo);
                    peleaActiva = false;
                } else {
                    cout << "El intento de captura fall�." << endl;
                }
            }

            // Verificar si el enemigo es capturable
            if (enemigo.getVida() <= enemigo.getVida() * 0.25) {
                capturable = true;
            }

            // Cambiar turno al enemigo
            turnoJugador = false;
        } else {
            // Turno del enemigo
            cout << "El enemigo ataca!" << endl;
            monstruoJugador.Sumarvida(-enemigo.getDanio());

            // Cambiar turno al jugador
            turnoJugador = true;
        }

        // Comprobar si la pelea ha terminado
        if (monstruoJugador.getVida() <= 0) {
            cout << "Has perdido la pelea!" << endl;
            peleaActiva = false;
        } else if (enemigo.getVida() <= 0) {
            cout << "Has ganado la pelea!" << endl;
            peleaActiva = false;
        }

        // Mostrar lo dibujado
        window.display();
    }
}
*/


