#include <SFML/Graphics.hpp>
#include <Personaje.h>

using namespace std;
int main()
{

    //Ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Totemon");
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
