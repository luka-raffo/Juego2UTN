#ifndef ANIMACIONATAQUE_H
#define ANIMACIONATAQUE_H
#include <SFML/Graphics.hpp>

class AnimacionAtaque: public sf::Drawable
{
    private:

    protected:

    sf::IntRect Ataque[2]; // Tres frames para la animación de ataque
    sf::Sprite _spriteAtaque;
    sf::Texture _textureAtaque;
    sf::Clock _animationClockAtaque; // Reloj para controlar la animación
    int _currentFrameAtaque = 0;
    bool _animacionEnCurso;
    sf::IntRect idleVacio;
    bool _isMoving;
    sf::IntRect* _currentIdleRect; // Frame de reposo actual
    public:
    AnimacionAtaque();

    void update();

    void startAnimation();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    virtual ~AnimacionAtaque();
};

#endif // ANIMACIONATAQUE_H
