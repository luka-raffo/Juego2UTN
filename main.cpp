#include "reloj.h"
#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include <iostream>
#include "menu.h"
#include <ctime>
#include <SFML/Audio.hpp>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
#include "escenario1.h"
#include "Funciones.H"
#include "escenario2.h"
#include "escenario3.h"
#include "PedirNombre.h"
#include "NombreJugador.h"

using namespace std;


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "pedirNombre.h"  // Aseg�rate de incluir este archivo correctamente
#include "Menu.h"         // Aseg�rate de incluir la implementaci�n de la clase Menu
// Funci�n para solicitar el nombre del jugador








int main() {

    // Crear la ventana principal para el men� solo despu�s de cerrar la ventana de ingreso de nombre
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu de Pokemon");


    sf::Clock clock;





    // M�sica de fondo
    sf::Music music;
    if (!music.openFromFile("musica.wav")) {
        std::cerr << "Error al cargar el archivo de m�sica" << std::endl;
        return -1;
    }
    music.setLoop(true);
    music.setVolume(3);
    music.play();

    // Cargar imagen de fondo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("include/PantallaTitulo.jpg")) {
        std::cerr << "Error al cargar la imagen de fondo!" << std::endl;
        return -1;
    }
    sf::Sprite background(backgroundTexture);

    // Crear el men�
    Menu menu(window.getSize().x, window.getSize().y);

    // Bucle principal del men�
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    menu.MoveUp();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    menu.MoveDown();
                }
                if (event.key.code == sf::Keyboard::Return) {
                    int selected = menu.GetPressedItem();
                    if (selected == 0) {
                        std::cout << "Nuevo Juego seleccionado" << std::endl;
                        NombreJugador ingresarNombre;
                        window.close(); // Cierra el men� para comenzar el juego
                        llegadaisla(clock);  // Llama a la funci�n que inicia el juego
                    } else if (selected == 1) {
                        std::cout << "Mostrar Ranking" << std::endl;

                    } else if (selected == 2) {
                        window.close();
                    }
                }
            }

            // Manejar la selecci�n con el rat�n
            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                menu.HandleMouseInput(mousePos);
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int selected = menu.GetPressedItem();
                    if (selected == 0) {
                        std::cout << "Nuevo Juego seleccionado con rat�n" << std::endl;
                        window.close();

                    } else if (selected == 1) {
                        std::cout << "Mostrar Ranking con rat�n" << std::endl;

                    } else if (selected == 2) {
                        window.close();
                    }
                }
            }
        }

        // Dibujar todo
        window.clear();
        window.draw(background);
        menu.draw(window);

        // Mostrar un t�tulo o imagen
        sf::Sprite titulo;
        sf::Texture titulo_text;
        if (titulo_text.loadFromFile("include/campusmon.png")) {
            titulo.setTexture(titulo_text);
            titulo.setPosition(600, 50);
            titulo.setScale(1.5,1.5);
            window.draw(titulo);
        }

        window.display();
    }

    return 0;
}



