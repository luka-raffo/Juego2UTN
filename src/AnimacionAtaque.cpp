#include "AnimacionAtaque.h"

AnimacionAtaque::AnimacionAtaque()
{



    Ataque[0] = sf::IntRect(0, 0, 159,159 );
    Ataque[1] = sf::IntRect(0, 159, 159, 159);

    _currentIdleRect = &idleVacio; // Inicialmente en reposo mirando hacia abajo

    _spriteAtaque.setTextureRect(*_currentIdleRect);

    _animacionEnCurso = false;

    _spriteAtaque.setScale(2.50f, 2.50f);
    _spriteAtaque.setPosition(320, 130);
}

void AnimacionAtaque::setRutaPNG(const std::string& rutaPNG)
{
    if (_textureAtaque.loadFromFile(rutaPNG)) {
        _spriteAtaque.setTexture(_textureAtaque);
        _spriteAtaque.setTextureRect(*_currentIdleRect);
    } else {
        // Manejar el error de carga
    }
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
////////////////////////////////////////////////////////
AnimacionDefensa::AnimacionDefensa()
{

    _textureDefensa.loadFromFile("Animations/zoonami_enemy_smog_animation.PNG");
    _spriteDefensa.setTexture(_textureDefensa);

    Defensa[0] = sf::IntRect(0, 0, 159,159 );
    Defensa[1] = sf::IntRect(0, 159, 159, 159);

    _currentIdleRect = &idleVacio; // Inicialmente en reposo mirando hacia abajo

    _spriteDefensa.setTextureRect(*_currentIdleRect);

    _animacionEnCurso = false;

    _spriteDefensa.setScale(2.50f, 2.50f);
    _spriteDefensa.setPosition(320, 130);
}


void AnimacionDefensa::startAnimation()
{
    if (!_animacionEnCurso)
    {
        _animacionEnCurso = true;
        _animationClockDefensa.restart();
        _currentFrameDefensa = 0;
    }
}

void AnimacionDefensa::update(){
    sf::Time frameTime = sf::seconds(0.5f); // Duración de cada frame


    if (_animacionEnCurso)
    {
        if (_animationClockDefensa.getElapsedTime() > frameTime)
        {

            if (_currentFrameDefensa < 2)
            {
                _spriteDefensa.setTextureRect(Defensa[_currentFrameDefensa]);
                _animationClockDefensa.restart();
            _currentFrameDefensa++;
            }
            else
            {
                _animacionEnCurso = false;
                _spriteDefensa.setTextureRect(*_currentIdleRect); // Volver al estado idle
            }


        }
    }
}

void AnimacionDefensa::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    if (_animacionEnCurso)
    {
        target.draw(_spriteDefensa, states);
    }
    }

AnimacionDefensa::~AnimacionDefensa()
{
    //dtor
}
////////////////////////////////////////////////////////
