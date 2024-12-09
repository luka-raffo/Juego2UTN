#include "reloj.h"
#include <SFML/Graphics.hpp>

reloj::reloj()
{
    rel.restart();
}

void reloj::actualizar() {
        if (usar) {
            // Obtener el tiempo transcurrido
            sf::Time tiempoTranscurrido = rel.getElapsedTime();
            float segundos = tiempoTranscurrido.asSeconds();
            std::cout << "Segundos transcurridos: " << segundos << std::endl;
        }
    }

void reloj::reiniciarReloj() {
        // Reiniciar el reloj
        rel.restart();
    }

    // Getter para el reloj
    sf::Clock reloj::getReloj() {
        return rel;
    }

    // Setter para el reloj
void reloj::setReloj(sf::Clock& nuevoReloj) {
        rel = nuevoReloj;
    }

reloj::~reloj()
{
    //dtor
}
