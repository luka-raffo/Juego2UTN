#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include <iostream>
#include "menu.h"
#include <ctime>
#include <stdlib.h>
#include "escenario1.h"
#include "Funciones.H"
using namespace std;



void startGame() {
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia Juego");

    // Establecer el límite de FPS
    window.setFramerateLimit(60);

    // Crear un personaje
    Personaje rojo;

    // Crear lista de bush
    vector<bush6x4> listaBushes;
    bush6x4 b1, b2, b3;
    b1.setPosition(150, 200);
    b2.setPosition(300, 400);
    b3.setPosition(450, 200);
    listaBushes.push_back(b1);
    listaBushes.push_back(b2);
    listaBushes.push_back(b3);

    // Crear fondo
    escenario Fondo;

    // Agregar un reloj para el cooldown de colisiones
    sf::Clock collisionCooldown;
    float cooldownTime = 2.0f;  // Cooldown de 2 segundos

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Actualizar el personaje
        rojo.update();

        // Verificar si el cooldown ha pasado
        if (collisionCooldown.getElapsedTime().asSeconds() >= cooldownTime) {
            int EventoPokemon = 0;
            // Verificar colisiones con cada objeto en la lista
            for (const bush6x4& b : listaBushes) {
                if (rojo.isCollision(b)) {
                    EventoPokemon = std::rand() % 2000;
                    if (EventoPokemon <= 50) {
                        escenarioPelea();
                        // Reiniciar el reloj del cooldown al activar la pelea
                        collisionCooldown.restart();
                    }

                    cout << "colision" << endl;
                    break;  // Evitar múltiples colisiones en un mismo frame
                }
            }
        }

        // Dibujar todo
        window.clear();

        /************ Los window.draw se dibujan según su orden creando capas **************/
        window.draw(Fondo);

        // Recorrer la lista y dibujar los bush
        for (const bush6x4& b : listaBushes) {
            window.draw(b);
        }

        window.draw(rojo);
        window.display();
    }
}

int main()
{
    srand ((unsigned)time(0));
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu de Pokemon");

    // Cargar imagen de fondo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("include/file.jpg"))
    {
        std::cerr << "Error al cargar la imagen de fondo!" << std::endl;
        return -1;
    }
    sf::Sprite background(backgroundTexture);

    // Crear el menú
    Menu menu(window.getSize().x, window.getSize().y);
    //loop menu
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    menu.MoveUp();
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    menu.MoveDown();
                }
                if (event.key.code == sf::Keyboard::Return)
                {
                    int selected = menu.GetPressedItem();
                    if (selected == 0)
                    {
                        std::cout << "Nuevo Juego seleccionado" << std::endl;
                        // Lógica para iniciar un nuevo juego
                        window.close();  // Cierra el menú para comenzar el juego
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
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                menu.HandleMouseInput(mousePos);
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int selected = menu.GetPressedItem();
                    if (selected == 0)
                    {
                        std::cout << "Nuevo Juego seleccionado con ratón" << std::endl;
                        // Lógica para iniciar un nuevo juego
                    }
                    else if (selected == 1)
                    {
                        std::cout << "Creditos Juego seleccionado con ratón" << std::endl;
                        // Lógica para cargar el juego
                    }
                    else if (selected == 2)
                    {
                        window.close();
                    }
                }
            }
        }

        // Dibujar todo
        window.clear();
        window.draw(background);
        menu.draw(window);
        sf::Sprite titulo;
        sf::Texture titulo_text;
        titulo_text.loadFromFile("include/Titulo.jpeg");
        titulo.setTexture(titulo_text);
        titulo.setPosition(700,100);
        window.draw(titulo);
        window.display();

    }
    return 0;
}
