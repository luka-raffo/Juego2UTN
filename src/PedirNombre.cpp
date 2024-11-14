#include "PedirNombre.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

std::string nombreJugador;
sf::Clock reloj;

void cerrarPrograma() {
    std::exit(0);  // Termina el programa inmediatamente
}

// Función para iniciar el reloj
sf::Clock iniciarReloj() {
    sf::Clock reloj;
    return reloj;
}



// Función para detener el reloj y guardar el tiempo
void detenerRelojYGuardarTiempo(bool usar) {
    if(usar){
    sf::Time tiempoTranscurrido = reloj.getElapsedTime();
    std::ofstream archivo("scores.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << nombreJugador << " - " << tiempoTranscurrido.asSeconds() << " segundos\n";
        archivo.close();
    }
    cerrarPrograma();
    }
}



std::string pedirNombre(sf::RenderWindow &window, sf::Font &font, bool usar) {

    detenerRelojYGuardarTiempo(usar);
    sf::Text textoPrompt("Ingrese su nombre:", font, 24);
    textoPrompt.setPosition(100, 100);
    textoPrompt.setFillColor(sf::Color::White);



    sf::Clock clock;
    sf::Time elapsedTime;


    sf::Text nombreText("", font, 24);
    nombreText.setPosition(100, 150);
    nombreText.setFillColor(sf::Color::White);

    // Bucle de eventos para capturar la entrada del usuario
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return "";  // Devuelve una cadena vacía si se cierra la ventana
            }

            // Captura la entrada de texto
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode == '\b' && !nombreJugador.empty()) {
                        // Borra el último carácter si el usuario presiona la tecla de retroceso
                        nombreJugador.pop_back();
                    } else if (event.text.unicode == '\r' || event.text.unicode == '\n') {
                        // Confirma el nombre cuando se presiona Enter
                        return nombreJugador;
                    } else if (event.text.unicode != '\b') {
                        // Añade el carácter ingresado al nombre del jugador
                        nombreJugador += static_cast<char>(event.text.unicode);
                    }
                }
            }
        }

        // Actualiza el texto del nombre del jugador
        nombreText.setString(nombreJugador);
         iniciarReloj();

        // Renderiza el prompt y el nombre ingresado



        window.clear();
        window.draw(textoPrompt);
        window.draw(nombreText);
        window.display();
    }

    return nombreJugador;
}


