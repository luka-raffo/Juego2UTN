
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
    bool usar=false;
    sf::Font font;
    if (!font.loadFromFile("include/Pokemon.ttf")) {
        std::cerr << "Error cargando la fuente\n";
        return "";
    }

    // Llama a la función pedirNombre pasando tanto la ventana como la fuente
    std::string nombreJugador = pedirNombre(windowNombre, font,usar);

    windowNombre.close();

    std::cout << "Bienvenido, " << nombreJugador << "!" << std::endl;
    return nombreJugador;
}
// Función para cargar el ranking desde score.txt
std::vector<std::string> cargarRanking(const std::string& nombreArchivo) {
    std::vector<std::string> ranking;
    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            ranking.push_back(linea);
        }
        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
    }

    return ranking;
}

// Función para mostrar el ranking en una nueva ventana
void mostrarRanking() {
    std::vector<std::string> ranking = cargarRanking("scores.txt");

    sf::RenderWindow rankingWindow(sf::VideoMode(600, 800), "Ranking");

    // Configurar la fuente
    sf::Font font;
    if (!font.loadFromFile("include/Pokemon.ttf")) {
        std::cerr << "No se pudo cargar la fuente." << std::endl;
        return;
    }

    // Configurar el título "Mejores Jugadores"
    sf::Text titulo("Mejores Jugadores", font, 30);
    titulo.setFillColor(sf::Color::Yellow);
    titulo.setPosition(150, 20);  // Centrar el título

    // Configurar texto del ranking
    std::vector<sf::Text> textos;
    for (size_t i = 0; i < ranking.size() && i < 10; ++i) { // Solo muestra los primeros 10
        sf::Text texto;
        texto.setFont(font);
        texto.setString(std::to_string(i + 1) + ". " + ranking[i]);
        texto.setCharacterSize(24);
        texto.setFillColor(sf::Color::White);
        texto.setPosition(50, 80 + i * 30);  // Ajusta la posición de cada línea debajo del título
        textos.push_back(texto);
    }

    // Bucle de la ventana de ranking
    while (rankingWindow.isOpen()) {
        sf::Event event;
        while (rankingWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                rankingWindow.close();
            }
        }

        rankingWindow.clear(sf::Color::Black);

        // Dibujar el título
        rankingWindow.draw(titulo);

        // Dibujar cada línea del ranking
        if (!textos.empty()) {
            for (const auto& texto : textos) {
                rankingWindow.draw(texto);
            }
        } else {
            // Si no hay texto, mostrar mensaje de error
            sf::Text errorMsg("No se encontraron datos en el ranking", font, 24);
            errorMsg.setFillColor(sf::Color::Red);
            errorMsg.setPosition(50, 80);
            rankingWindow.draw(errorMsg);
        }

        rankingWindow.display();
    }
}
int main() {

    // Crear la ventana principal para el menú solo después de cerrar la ventana de ingreso de nombre
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu de Pokemon");

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
    if (!backgroundTexture.loadFromFile("include/PantallaTitulo.jpg")) {
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
                if (event.key.code == sf::Keyboard::Return) {
                    int selected = menu.GetPressedItem();
                    if (selected == 0) {
                        std::cout << "Nuevo Juego seleccionado" << std::endl;
                        window.close(); // Cierra el menú para comenzar el juego
                        llegadaisla();  // Llama a la función que inicia el juego
                    } else if (selected == 1) {
                        std::cout << "Mostrar Ranking" << std::endl;
                        mostrarRanking();  // Muestra la ventana de ranking
                    } else if (selected == 2) {
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
                        startGame();
                    } else if (selected == 1) {
                        std::cout << "Mostrar Ranking con ratón" << std::endl;
                        mostrarRanking();  // Muestra la ventana de ranking
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
            titulo.setPosition(600, 50);
            titulo.setScale(1.5,1.5);
            window.draw(titulo);
        }

        window.display();
    }

    return 0;
}


