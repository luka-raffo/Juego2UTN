#include "AnimacionAtaque.h"

AnimacionAtaque::AnimacionAtaque()
{

    _textureAtaque.loadFromFile("Animations/zoonami_enemy_aqua_jet_animation.PNG");
    _spriteAtaque.setTexture(_textureAtaque);

    Ataque[0] = sf::IntRect(0, 0, 159,159 );
    Ataque[1] = sf::IntRect(0, 159, 159, 159);

    _currentIdleRect = &idleVacio; // Inicialmente en reposo mirando hacia abajo

    _spriteAtaque.setTextureRect(*_currentIdleRect);

    _animacionEnCurso = false;

    _spriteAtaque.setScale(2.50f, 2.50f);
    _spriteAtaque.setPosition(320, 130);
}


void AnimacionAtaque::startAnimation()
{
    if (!_animacionEnCurso)
    {
        _animacionEnCurso = true;
        _animationClockAtaque.restart();
        _currentFrameAtaque = 0;
    }
}

void AnimacionAtaque::update(){
    sf::Time frameTime = sf::seconds(0.5f); // Duración de cada frame


    if (_animacionEnCurso)
    {
        if (_animationClockAtaque.getElapsedTime() > frameTime)
        {

            if (_currentFrameAtaque < 2)
            {
                _spriteAtaque.setTextureRect(Ataque[_currentFrameAtaque]);
                _animationClockAtaque.restart();
            _currentFrameAtaque++;
            }
            else
            {
                _animacionEnCurso = false;
                _spriteAtaque.setTextureRect(*_currentIdleRect); // Volver al estado idle
            }


        }
    }
}

void AnimacionAtaque::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    if (_animacionEnCurso)
    {
        target.draw(_spriteAtaque, states);
    }
    }

AnimacionAtaque::~AnimacionAtaque()
{
    //dtor
}
