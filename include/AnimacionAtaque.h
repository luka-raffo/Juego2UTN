#ifndef ANIMACIONATAQUE_H
#define ANIMACIONATAQUE_H
#include <SFML/Graphics.hpp>
#include<string>

using namespace std;
class Animacion : public sf::Drawable {
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Clock _animationClock;
    sf::IntRect* _currentIdleRect = nullptr;
    sf::IntRect idleVacio; // Frame de reposo

    sf::IntRect* _frames = nullptr; // Puntero dinámico a los frames
    int _frameCount = 0; // Número de frames
    int _currentFrame = 0;
    bool _animacionEnCurso = false;
    bool _isMoving = false;

public:
    Animacion() {}

    virtual ~Animacion() {
        delete[] _frames; // Liberar memoria dinámica
    }

    // Métodos comunes para todas las animaciones
    virtual void setRutaPNG(const string& rutaPNG) {
        if (_texture.loadFromFile(rutaPNG)) {
            _sprite.setTexture(_texture);
            _sprite.setTextureRect(*_currentIdleRect);
        }
    }

    // Configurar frames de animación
    virtual void setFrames(sf::IntRect* frames, int count) {
        delete[] _frames; // Limpiar cualquier frame previo
        _frameCount = count;
        _frames = new sf::IntRect[_frameCount];
        for (int i = 0; i < _frameCount; ++i) {
            _frames[i] = frames[i];
        }
    }

    virtual void startAnimation() {
        if (!_animacionEnCurso) {
            _animacionEnCurso = true;
            _animationClock.restart();
            _currentFrame = 0;
        }
    }

    virtual void update() {
        sf::Time frameTime = sf::seconds(0.5f); // Duración de cada frame

        if (_animacionEnCurso) {
            if (_animationClock.getElapsedTime() > frameTime) {
                if (_currentFrame < _frameCount) {
                    _sprite.setTextureRect(_frames[_currentFrame]);
                    _animationClock.restart();
                    _currentFrame++;
                } else {
                    _animacionEnCurso = false;
                    _sprite.setTextureRect(*_currentIdleRect); // Volver al estado idle
                }
            }
        }
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        if (_animacionEnCurso) {
            target.draw(_sprite, states);
        }
    }
};

// Clase derivada para la animación de ataque
class AnimacionAtaque : public Animacion {
public:
    AnimacionAtaque() {
        sf::IntRect frames[] = {
            sf::IntRect(0, 0, 159, 159),
            sf::IntRect(0, 159, 159, 159)
        };

        setFrames(frames, 2);

        idleVacio = sf::IntRect(0, 0, 159, 159);
        _currentIdleRect = &idleVacio;

        _sprite.setTextureRect(*_currentIdleRect);
        _sprite.setScale(2.50f, 2.50f);
        _sprite.setPosition(320, 130);
    }
};

// Clase derivada para la animación de defensa
class AnimacionDefensa : public Animacion {
public:
    AnimacionDefensa() {
        sf::IntRect frames[] = {
            sf::IntRect(0, 0, 159, 159),
            sf::IntRect(0, 159, 159, 159)
        };

        setFrames(frames, 2);

        idleVacio = sf::IntRect(0, 0, 159, 159);
        _currentIdleRect = &idleVacio;

        _sprite.setTextureRect(*_currentIdleRect);
        _sprite.setScale(2.50f, 2.50f);
        _sprite.setPosition(320, 130);
    }
};

#endif // ANIMACIONATAQUE_H
