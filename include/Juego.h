#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <Monstruo.h>

using namespace std;

class Juego {
private:
    Monstruo** monstruos; // Puntero a un arreglo dinámico de punteros a Monstruo
    int capacidad;        // Capacidad actual del arreglo
    int cantidad;         // Número actual de monstruos
    int indiceActual;     // Índice del monstruo actual

    void redimensionar(int nuevaCapacidad) {
        Monstruo** nuevoArreglo = new Monstruo*[nuevaCapacidad];
        for (int i = 0; i < cantidad; i++) {
            nuevoArreglo[i] = monstruos[i];
        }
        delete[] monstruos;
        monstruos = nuevoArreglo;
        capacidad = nuevaCapacidad;
    }

public:
    Juego() : monstruos(nullptr), capacidad(0), cantidad(0), indiceActual(0) {}

    ~Juego() {
        for (int i = 0; i < cantidad; i++) {
            delete monstruos[i];
        }
        delete[] monstruos;
    }

    void agregarMonstruo(Monstruo* m) {
        if (cantidad == capacidad) {
            int nuevaCapacidad = (capacidad == 0) ? 1 : capacidad * 2;
            redimensionar(nuevaCapacidad);
        }
        monstruos[cantidad++] = m;
    }

    void verificarVida(float vida) {
        if (!monstruos[indiceActual]->estaVivo(vida) && indiceActual < cantidad - 1) {
            indiceActual++;
            std::cout << "El siguiente monstruo ha aparecido." << std::endl;
        }
    }

    void dibujar(sf::RenderWindow& ventana) {
        if (indiceActual < cantidad) {
            ventana.draw(monstruos[indiceActual]->_sprite);
        }
    }

    bool pasarAlSiguienteMonstruo() {
        if (indiceActual < cantidad - 1) {
            indiceActual++;
            std::cout << "El siguiente monstruo ha aparecido: " << indiceActual << std::endl;
            return true;
        } else {
            std::cout << "No hay más monstruos." << std::endl;
            return false;
        }
    }

    // Métodos para el monstruo actual
    void setVidaMonstruoActual(float nuevaVida) {
        if (indiceActual < cantidad) {
            monstruos[indiceActual]->setVida(nuevaVida);
        }
    }

    void sumarVidaMonstruoActual(float vida) {
        if (indiceActual < cantidad) {
            monstruos[indiceActual]->Sumarvida(vida);
        }
    }

    float getVidaMonstruoActual() const {
        if (indiceActual < cantidad) {
            return monstruos[indiceActual]->getVida();
        }
        return 0.0f;
    }

    void setAtaqueMonstruoActual(float danio) {
        if (indiceActual < cantidad) {
            monstruos[indiceActual]->setAtaque(danio);
        }
    }

    void sumarAtaqueMonstruoActual(float danio) {
        if (indiceActual < cantidad) {
            monstruos[indiceActual]->Sumarataque(danio);
        }
    }

    float getDanioMonstruoActual() const {
        if (indiceActual < cantidad) {
            return monstruos[indiceActual]->getDanio();
        }
        return 0.0f;
    }

    void setDefensaMonstruoActual(float defensa) {
        if (indiceActual < cantidad) {
            monstruos[indiceActual]->setDefensa(defensa);
        }
    }

    float getDefensaMonstruoActual() const {
        if (indiceActual < cantidad) {
            return monstruos[indiceActual]->getDefensa();
        }
        return 0.0f;
    }

    int getNivelMonstruoActual() const {
        if (indiceActual < cantidad) {
            return monstruos[indiceActual]->getNivel();
        }
        return 0;
    }

    float getExperienciaMonstruoActual() const {
        if (indiceActual < cantidad) {
            return monstruos[indiceActual]->getExperiencia();
        }
        return 0.0f;
    }

    void ganarExperienciaMonstruoActual(float exp) {
        if (indiceActual < cantidad) {
            monstruos[indiceActual]->ganarExperiencia(exp);
        }
    }

    // Métodos para posición y escala
    void setPosition(float x, float y) {
        if (indiceActual < cantidad) {
            monstruos[indiceActual]->setPosition(x, y);
        }
    }

    void setScale(float x, float y) {
        if (indiceActual < cantidad) {
            monstruos[indiceActual]->setScale(x, y);
        }
    }

    void setPositionTodosMonstruos(float x, float y) {
        for (int i = 0; i < cantidad; i++) {
            monstruos[i]->setPosition(x, y);
        }
    }
};


#endif // JUEGO_H
