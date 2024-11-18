#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <Monstruo.h>

using namespace std;

class Juego
{
    private:
        vector<Monstruo*> monstruos;
        int indiceActual;

    public:
        Juego();
        ~Juego(); // Destructor para liberar memoria

        void agregarMonstruo(Monstruo *m);
        void verificarVida(float vida);
        void dibujar(sf::RenderWindow& ventana);

        // Método para pasar al siguiente monstruo
        bool pasarAlSiguienteMonstruo();

        // Métodos para el monstruo actual
        void setVidaMonstruoActual(float nuevaVida);
        void sumarVidaMonstruoActual(float vida);
        float getVidaMonstruoActual() const;

        void setAtaqueMonstruoActual(float danio);
        void sumarAtaqueMonstruoActual(float danio);
        float getDanioMonstruoActual() const;

        void setDefensaMonstruoActual(float defensa);
        float getDefensaMonstruoActual() const;

        int getNivelMonstruoActual() const;
        float getExperienciaMonstruoActual() const;
        void ganarExperienciaMonstruoActual(float exp);

        // Métodos para posición y escala
        void setPosition(float x, float y);
        void setScale(float x, float y);

        // Método para establecer la posición de todos los monstruos
        void setPositionTodosMonstruos(float x, float y);
};

#endif // JUEGO_H
