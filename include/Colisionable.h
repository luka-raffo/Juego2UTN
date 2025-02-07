#ifndef COLISIONABLE_H_INCLUDED
#define COLISIONABLE_H_INCLUDED
#include <SFML/Graphics.hpp>
class Colisionable{


public:
 // Método virtual puro para obtener los límites del objeto
    virtual sf::FloatRect getBounds() const = 0;

    // Método para detectar colisiones entre dos objetos colisionables
    bool isCollision(const Colisionable& obj) const;

};

#endif // COLISIONABLE_H_INCLUDED
