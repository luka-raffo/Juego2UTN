#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include <iostream>
#include "menu.h"
#include <ctime>
#include <stdlib.h>
#include <SFML/Audio.hpp>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
#include "escenario1.h"
#include "Funciones.H"
#include "escenario2.h"
#include "escenario3.h"
#include <time.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "PedirNombre.h"


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

using namespace std;


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "pedirNombre.h"  // Asegúrate de incluir este archivo correctamente
#include "Menu.h"         // Asegúrate de incluir la implementación de la clase Menu
// Función para solicitar el nombre del jugador

std::string IngresarNombre() {
    sf::RenderWindow windowNombre(sf::VideoMode(800, 600), "Ingrese Nombre");

    sf::Font font;
    if (!font.loadFromFile("include/Pokemon.ttf")) {
        std::cerr << "Error cargando la fuente\n";
        return "";
    }

    // Llama a la función pedirNombre pasando tanto la ventana como la fuente
    std::string nombreJugador = pedirNombre(windowNombre, font);

    windowNombre.close();

    std::cout << "Bienvenido, " << nombreJugador << "!" << std::endl;
    return nombreJugador;
}


int main() {

    // Crear la ventana principal para el menú solo después de cerrar la ventana de ingreso de nombre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu de Pokemon");

    // Música de fondo
    sf::Music music;
    if (!music.openFromFile("musica.wav")) {
        std::cerr << "Error al cargar el archivo de música" << std::endl;
        return -1;
    }
    music.setLoop(true);
    music.setVolume(5);
    music.play();

    // Cargar imagen de fondo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("include/file.jpg")) {
        std::cerr << "Error al cargar la imagen de fondo!" << std::endl;
        return -1;
    }
    sf::Sprite background(backgroundTexture);

    // Crear el menú
    Menu menu(window.getSize().x, window.getSize().y);

    // Bucle principal del menú
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
                 if (event.key.code == sf::Keyboard::Return)
                {
                    int selected = menu.GetPressedItem();
                    if (selected == 0)
                    {
                        std::cout << "Nuevo Juego seleccionado" << std::endl;
                        // Lógica para iniciar un nuevo juego
                        window.close();// Cierra el menú para comenzar el juego

                        IngresarNombre(); // Se pone el nombre

                        startGame();     // Llama a la función que inicia el juego


                    }
                    else if (selected == 1)
                    {
                        std::cout << "Creditos Juego seleccionado" << std::endl;

                        // Lógica para cargar el juego
                    }
                    else if (selected == 2)
                    {
                        window.close();
                    }
                }
            }
            // Manejar la selección con el ratón
            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                menu.HandleMouseInput(mousePos);
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int selected = menu.GetPressedItem();
                    if (selected == 0) {
                        std::cout << "Nuevo Juego seleccionado con ratón" << std::endl;





                        window.close();

                    // Lógica para iniciar el juego...
                        startGame();



                    } else if (selected == 1) {
                        std::cout << "Creditos Juego seleccionado con ratón" << std::endl;
                        // Lógica para cargar el juego
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

        // Mostrar un título o imagen
        sf::Sprite titulo;
        sf::Texture titulo_text;
        if (titulo_text.loadFromFile("include/campusmon.png")) {
            titulo.setTexture(titulo_text);
            titulo.setPosition(700, 100);
            window.draw(titulo);
        }

        window.display();
    }

    return 0;
}

