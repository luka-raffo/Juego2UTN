#ifndef COLISIONABLE_H_INCLUDED
#define COLISIONABLE_H_INCLUDED
#include <SFML/Graphics.hpp>
class Colisionable{


public:
 // M�todo virtual puro para obtener los l�mites del objeto
    virtual sf::FloatRect getBounds() const = 0;

    // M�todo para detectar colisiones entre dos objetos colisionables
    bool isCollision(const Colisionable& obj) const;

};

#endif // COLISIONABLE_H_INCLUDED
