#ifndef RELOJ_H
#define RELOJ_H
#include <SFML/Graphics.hpp>
#include <iostream>
class reloj
{


     private:
    sf::Clock rel;  // Crear el reloj aquí
    bool usar = true;  // Condición de ejemplo para determinar si se debe guardar el tiempo


    protected:

    public:
    reloj();
    void actualizar();
    void reiniciarReloj();

    // Getter para el reloj
    sf::Clock getReloj();

    // Setter para el reloj
    void setReloj( sf::Clock& nuevoReloj);



    virtual ~reloj();
};

#endif // RELOJ_H
