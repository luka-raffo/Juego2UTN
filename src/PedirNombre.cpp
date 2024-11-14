#include "PedirNombre.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

std::string pedirNombre(sf::RenderWindow &window, sf::Font &font) {
    sf::Text textoPrompt("Ingrese su nombre:", font, 24);
    textoPrompt.setPosition(100, 100);
    textoPrompt.setFillColor(sf::Color::White);

    std::string nombreJugador;
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

        // Renderiza el prompt y el nombre ingresado
        window.clear();
        window.draw(textoPrompt);
        window.draw(nombreText);
        window.display();
    }

    return nombreJugador;
}
