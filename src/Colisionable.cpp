#include "Colisionable.h"
 bool Colisionable::isCollision(const Colisionable& obj) const {
    return getBounds().intersects(obj.getBounds());
}
