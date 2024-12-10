#ifndef ANIMACIONATAQUE_H
#define ANIMACIONATAQUE_H
#include <SFML/Graphics.hpp>
#include <string>

class Animacion : public sf::Drawable {
protected:
    sf::IntRect* _frames; // Puntero a los frames de animación
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Clock _animationClock; // Reloj para controlar la animación
    int _currentFrame = 0;
    bool _animacionEnCurso = false;
    sf::IntRect idleVacio; // Frame de reposo
    sf::IntRect* _currentIdleRect; // Frame de reposo actual
    int _numFrames; // Número de frames en la animación

public:
    Animacion(int numFrames)
        : _numFrames(numFrames) {
        _frames = new sf::IntRect[numFrames];
        _currentIdleRect = &idleVacio;
    }

    virtual void setRutaPNG(const std::string& rutaPNG) {
        if (_texture.loadFromFile(rutaPNG)) {
            _sprite.setTexture(_texture);
            _sprite.setTextureRect(*_currentIdleRect);
        } else {
            // Manejar el error de carga
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
                if (_currentFrame < _numFrames) {
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

    virtual ~Animacion() {
        delete[] _frames;
    }

    void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    }

    void setScale(float scaleX, float scaleY) {
        _sprite.setScale(scaleX, scaleY);
    }

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        if (_animacionEnCurso) {
            target.draw(_sprite, states);
        }
    }
};

class AnimacionAtaque : public Animacion {
public:
    AnimacionAtaque()
        : Animacion(2) { // Inicializamos con 2 frames
        _frames[0] = sf::IntRect(0, 0, 159, 159);
        _frames[1] = sf::IntRect(0, 159, 159, 159);
        _sprite.setScale(2.50f, 2.50f);
        _sprite.setPosition(320, 130);
    }
};

class AnimacionDefensa : public Animacion {
public:
    AnimacionDefensa()
        : Animacion(2) { // Inicializamos con 2 frames
        _frames[0] = sf::IntRect(0, 0, 159, 159);
        _frames[1] = sf::IntRect(0, 159, 159, 159);
        _sprite.setScale(2.50f, 2.50f);
        _sprite.setPosition(320, 130);
    }
};


#endif // ANIMACIONATAQUE_H
