#include <SFML/Graphics.hpp>
#include <Personaje.h>
#include <iostream>
#include "menu.h"
using namespace std;
int main()
{
     // Crear una ventana
 sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu de Pokemon");

    // Cargar imagen de fondo
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("include/background.jpg")) {
        return -1;
    }
    sf::Sprite background(backgroundTexture);

    // Crear el menú
    Menu menu(window.getSize().x, window.getSize().y);

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
                        cout << "Nuevo Juego seleccionado" << endl;
                        // Lógica para iniciar un nuevo juego
                    } else if (selected == 1) {
                        cout << "Creditos" << endl;
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
        window.display();
    }
return 0;}
/*
    //Ventana
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Totemon");
    //settearFPS
    window.setFramerateLimit(60);


    Personaje rojo;





    //velocidad del Personaje



    //GameLoop
    while (window.isOpen())

    {

        //ReadInput
        sf::Event event;

        //Leer la cola de Mensajes
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        //Update
        rojo.update();


        //Draw
        window.draw(rojo);

        //Display-Flip
        window.display();

        window.clear();
    }


    //Liberacion del Juego


    return 0;
}
*/
