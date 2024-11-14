#include "PedirNombre.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

std::string nombreJugador;
sf::Clock reloje;


void cerrarPrograma() {
    std::exit(0);  // Termina el programa inmediatamente
}

// Función para iniciar el reloj
sf::Clock iniciarReloj() {
    sf::Clock reloje;
    return reloje;
}



// Función para detener el reloj y guardar el tiempo
void detenerRelojYGuardarTiempo(bool usar) {
    if(usar){
    sf::Time tiempoTranscurrido = reloje.getElapsedTime();
    std::ofstream archivo("scores.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << nombreJugador << " - " << tiempoTranscurrido.asSeconds() << " segundos\n";
        archivo.close();
    }
    cerrarPrograma();
    }
}


