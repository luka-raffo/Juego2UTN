#include "Personaje.h"

Personaje::Personaje()
{
    inventory inventario(100);

    //Asignacion para la textura
    _texture.loadFromFile("Characters/character 4.png");

    //Asignacion de la textura del Personaje
    _sprite.setTexture(_texture);

    ///Toman partes de la hoja de sprites (varios dibujos) para solo tomar un objeto (o varios) y luego esto se setea en el sprite que lo dibuja
    ///El vector esta para las animaciones[caminar]
    downRect[0] = sf::IntRect(18, 0, 14, 20);
    downRect[1] = sf::IntRect(0, 0, 14, 20);
    downRect[2] = sf::IntRect(50, 0, 14, 20);

    leftRect[0] = sf::IntRect(18, 40, 14, 20);
    leftRect[1] = sf::IntRect(0, 40, 14, 20);
    leftRect[2] = sf::IntRect(50, 40, 14, 20);

    rightRect[0] = sf::IntRect(18, 60, 14, 20);
    rightRect[1] = sf::IntRect(0, 60, 14, 20);
    rightRect[2] = sf::IntRect(50, 60, 14, 20);

    upRect[0] = sf::IntRect(18, 20, 14, 20);
    upRect[1] = sf::IntRect(0, 20, 14, 20);
    upRect[2] = sf::IntRect(50, 20, 14, 20);



    // Inicializar los frames de reposo
    idleDownRect = sf::IntRect(0, 0, 15, 20);
    idleLeftRect = sf::IntRect(0, 40, 14, 20);
    idleRightRect = sf::IntRect(0, 60, 14, 20);
    idleUpRect = sf::IntRect(0, 20, 15, 20);

    _currentIdleRect = &idleDownRect; // Inicialmente en reposo mirando hacia abajo
    _sprite.setTextureRect(*_currentIdleRect);




}



void Personaje::update(){

    sf::Time frameTime = sf::seconds(0.1f);
     _isMoving = false; // Asumir que no se está moviendo

//mapeo de las teclas
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
           if (_animationClock.getElapsedTime() > frameTime) {
             _currentFrame = (_currentFrame + 1) % 3;

            ///setea la textura del sprite mirando a arriba
            _sprite.setTextureRect(upRect[_currentFrame]);

            _animationClock.restart();

            }

            _sprite.move(0,-_velocity);

            _isMoving = true;
            _currentIdleRect = &idleUpRect;

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if (_animationClock.getElapsedTime() > frameTime) {
            _currentFrame = (_currentFrame + 1) % 3;
            ///setea la textura del sprite mirando a abajo
            _sprite.setTextureRect(downRect[_currentFrame]);

            _animationClock.restart();


            }

            ///movimiento del sprite
            _sprite.move(0,_velocity);

            _isMoving = true;
            _currentIdleRect = &idleDownRect;

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            if (_animationClock.getElapsedTime() > frameTime) {
            _currentFrame = (_currentFrame + 1) % 3;
            ///setea la textura del sprite mirando a la izquierda
            _sprite.setTextureRect(leftRect[_currentFrame]);

            _animationClock.restart();


            }
            _sprite.move(-_velocity,0);

            _isMoving = true;
            _currentIdleRect = &idleLeftRect;

        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (_animationClock.getElapsedTime() > frameTime) {

            _currentFrame = (_currentFrame + 1) % 3;
            ///setea la textura del sprite mirando a la derecha

            _sprite.setTextureRect(rightRect[_currentFrame]);

            _animationClock.restart();


            }
            _sprite.move(_velocity,0);

            _isMoving = true;
            _currentIdleRect = &idleRightRect;
        }

        if(!_isMoving){
        _sprite.setTextureRect(*_currentIdleRect);
    }






        //Validaciones para que el personaje no salga de la pantalla
        if(_sprite.getPosition().x <0){
            _sprite.setPosition(0,_sprite.getPosition().y);
        }

        if(_sprite.getPosition().y <0){
            _sprite.setPosition(_sprite.getPosition().x,0);
        }

        if(_sprite.getPosition().x+_sprite.getGlobalBounds().width >800){
            _sprite.setPosition(800-_sprite.getGlobalBounds().width,_sprite.getPosition().y);
        }

        if(_sprite.getPosition().y+_sprite.getGlobalBounds().height >600){
            _sprite.setPosition(_sprite.getPosition().x,600-_sprite.getGlobalBounds().height);
        }
}

    void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    target.draw(_sprite, states);
    }

    sf::FloatRect Personaje::getBounds()const{
    return _sprite.getGlobalBounds();
    }
