
#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <string>
#include <fstream>
#include <iostream>

class Timer {
public:
    // Inicia el temporizador, asignando el tiempo actual a la variable `inicio`
    static void iniciarTemporizador(time_t &inicio) {
        inicio = std::time(nullptr);
    }

    // Detiene el temporizador y calcula el tiempo transcurrido en segundos
    static double detenerTemporizador(const time_t &inicio) {
        return std::difftime(std::time(nullptr), inicio);
    }

    // Guarda el resultado en un archivo de clasificación
    static void guardarResultado(const std::string &nombreJugador, double tiempo) {
        std::ofstream archivo("clasificacion.txt", std::ios::app); // Abre en modo append
        if (archivo.is_open()) {
            archivo << nombreJugador << " " << tiempo << " segundos\n";
            archivo.close();
        } else {
            std::cerr << "Error al abrir el archivo de clasificación." << std::endl;
        }
    }
};

#endif // TIME_H
