#include <SFML/Graphics.hpp>
#include <Personaje.h>
#include <iostream>
#include "menu.h"
#include <ctime>
#include <stdlib.h>
#include "escenario1.h"
using namespace std;



void startGame()
{
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia Juego"/*, sf::Style::Fullscreen*/);

    // Establecer el límite de FPS
    window.setFramerateLimit(60);

    // Crear un personaje
    Personaje rojo;

    //crear bushes

    //Lista de bush
    vector<bush6x4> listaBushes;

    // Agregar objetos a la lista
    bush6x4 b1, b2, b3;
    b1.setPosition(150, 200);
    b2.setPosition(300, 400);
    b3.setPosition(450, 200);

    //lleva los objetos atras de la Lista
    listaBushes.push_back(b1);
    listaBushes.push_back(b2);
    listaBushes.push_back(b3);

    //crear fondo
    escenario Fondo;

    // GameLoop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Actualizar el personaje
        rojo.update();

        // Verificar colisiones con cada objeto en la lista
        for (const bush6x4& b : listaBushes)
        {
            if (rojo.isCollision(b))
            {
                cout << "colision" << endl;
            }
        }


        // Dibujar todo
        window.clear();


        /************ Los window.draw se dibujan segun su orden creando Capas **************/

        window.draw(Fondo);


        //Un for each para recorrer la lista y dibujar los bush
        for (const bush6x4& b : listaBushes)
        {
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
