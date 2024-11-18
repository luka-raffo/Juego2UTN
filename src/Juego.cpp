#include "Juego.h"

Juego::Juego() : indiceActual(0) {}

// Destructor
Juego::~Juego() {
    for (Monstruo* m : monstruos) {
        delete m; // Liberar memoria de cada monstruo
    }
    monstruos.clear(); // Limpiar el vector
}

void Juego::agregarMonstruo(Monstruo *m) {
    monstruos.push_back(m);
}

void Juego::verificarVida(float vida) {
    if (!monstruos[indiceActual]->estaVivo(vida) && indiceActual < monstruos.size() - 1) {
        indiceActual++;
        std::cout << "El siguiente monstruo ha aparecido." << std::endl;
    }
}

void Juego::dibujar(sf::RenderWindow& ventana) {
    if (indiceActual < monstruos.size()) {
        ventana.draw(monstruos[indiceActual]->_sprite);
    }
}

bool Juego::pasarAlSiguienteMonstruo() {
    if (indiceActual < monstruos.size() - 1) {
        indiceActual++;
        std::cout << "El siguiente monstruo ha aparecido: " << indiceActual << std::endl;
        return true;
    } else {
        std::cout << "No hay más monstruos." << std::endl;
        return false;
    }
}

// Métodos para el monstruo actual
void Juego::setVidaMonstruoActual(float nuevaVida) {
    if (indiceActual < monstruos.size()) {
        monstruos[indiceActual]->setVida(nuevaVida);
    }
}

void Juego::sumarVidaMonstruoActual(float vida) {
    if (indiceActual < monstruos.size()) {
        monstruos[indiceActual]->Sumarvida(vida);
    }
}

float Juego::getVidaMonstruoActual() const {
    if (indiceActual < monstruos.size()) {
        return monstruos[indiceActual]->getVida();
    }
    return 0.0f;
}

void Juego::setAtaqueMonstruoActual(float danio) {
    if (indiceActual < monstruos.size()) {
        monstruos[indiceActual]->setAtaque(danio);
    }
}

void Juego::sumarAtaqueMonstruoActual(float danio) {
    if (indiceActual < monstruos.size()) {
        monstruos[indiceActual]->Sumarataque(danio);
    }
}

float Juego::getDanioMonstruoActual() const {
    if (indiceActual < monstruos.size()) {
        return monstruos[indiceActual]->getDanio();
    }
    return 0.0f;
}

void Juego::setDefensaMonstruoActual(float defensa) {
    if (indiceActual < monstruos.size()) {
        monstruos[indiceActual]->setDefensa(defensa);
    }
}

float Juego::getDefensaMonstruoActual() const {
    if (indiceActual < monstruos.size()) {
        return monstruos[indiceActual]->getDefensa();
    }
    return 0.0f;
}

int Juego::getNivelMonstruoActual() const {
    if (indiceActual < monstruos.size()) {
        return monstruos[indiceActual]->getNivel();
    }
    return 0;
}

float Juego::getExperienciaMonstruoActual() const {
    if (indiceActual < monstruos.size()) {
        return monstruos[indiceActual]->getExperiencia();
    }
    return 0.0f;
}

void Juego::ganarExperienciaMonstruoActual(float exp) {
    if (indiceActual < monstruos.size()) {
        monstruos[indiceActual]->ganarExperiencia(exp);
    }
}

// Métodos para posición y escala
void Juego::setPosition(float x, float y) {
    if (indiceActual < monstruos.size()) {
        monstruos[indiceActual]->setPosition(x, y);
    }
}

void Juego::setScale(float x, float y) {
    if (indiceActual < monstruos.size()) {
        monstruos[indiceActual]->setScale(x, y);
    }
}

void Juego::setPositionTodosMonstruos(float x, float y) {
    for (Monstruo* m : monstruos) {
        m->setPosition(x, y);
    }
}
