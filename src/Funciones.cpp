#include "Funciones.h"
#include "inventory.h"
#include "Personaje.h"

using namespace std;
void escenarioPelea() {
        // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia la pelea");

    // Establecer el límite de FPS
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
    int probabilidad = std::rand() % 100;  // Generar un número entre 0 y 99 (100 posibles valores)
    sf::Drawable* monstruoSeleccionado = nullptr;

    // Asignar monstruo según probabilidad
    if (probabilidad < 0) {  // 20% de probabilidad para Hornerot
        monstruo.setPosition(570, 160);
        monstruoSeleccionado = &monstruo;
        cout<<"entro al if"<<endl;
    }


    /*else if (probabilidad < 35) {  // 15% de probabilidad para Pelucin (20 + 15 = 35)
        pelu.setPosition(570, 160);
        monstruoSeleccionado = &pelu;
    }*/


    /*else if (probabilidad < 60) {  // 25% de probabilidad para Tukin (35 + 25 = 60)
        tuki.setPosition(570, 160);
        monstruoSeleccionado = &tuki;
    }*/


    else if (probabilidad < 100) {  // 10% de probabilidad para Velom (60 + 10 = 70)
        vel.setPosition(570, 160);
        monstruoSeleccionado = &vel;
        cout<<"hola"<<endl;
        inventario.agregarItem(vel);
        inventario.mostrarInventario();
    }


    /*else if (probabilidad < 80) {  // 10% de probabilidad para Lechuza (70 + 10 = 80)
        lechu.setPosition(570, 160);
        monstruoSeleccionado = &lechu;
    }*/


    /*else if (probabilidad < 90) {  // 10% de probabilidad para Balleton (80 + 10 = 90)
        ballena.setPosition(570, 160);
        monstruoSeleccionado = &ballena;
    }*/


    /*else {  // 10% de probabilidad para Bufalont (90 a 99)
        bufalo.setPosition(570, 160);
        monstruoSeleccionado = &bufalo;
    }*/

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



