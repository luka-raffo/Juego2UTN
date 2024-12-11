#ifndef NOMBREJUGADOR_H
#define NOMBREJUGADOR_H
#include "string"
#include "iostream"
#include <SFML/Graphics.hpp>
#include "Funciones.h"


using namespace std;

class NombreJugador
{
    private:
        string nombreJugador;

    public:
        NombreJugador();
        virtual ~NombreJugador();

        string IngresarNombre();

    protected:


};

#endif // NOMBREJUGADOR_H
