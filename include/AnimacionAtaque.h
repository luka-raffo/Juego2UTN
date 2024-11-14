#ifndef ANIMACIONATAQUE_H
#define ANIMACIONATAQUE_H
#include <SFML/Graphics.hpp>
#include<string>

using namespace std;

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

    void setRutaPNG(const std::string& rutaPNG);

    void update();

    void startAnimation();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    virtual ~AnimacionAtaque();
};
class AnimacionDefensa: public sf::Drawable
{
    private:

    protected:

    sf::IntRect Defensa[2]; // Tres frames para la animación de ataque
    sf::Sprite _spriteDefensa;
    sf::Texture _textureDefensa;
    sf::Clock _animationClockDefensa; // Reloj para controlar la animación
    int _currentFrameDefensa = 0;
    bool _animacionEnCurso;
    sf::IntRect idleVacio;
    bool _isMoving;
    sf::IntRect* _currentIdleRect; // Frame de reposo actual
    public:
    AnimacionDefensa();

    void update();

    void startAnimation();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    virtual ~AnimacionDefensa();
};

#endif // ANIMACIONATAQUE_H
