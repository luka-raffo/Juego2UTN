#ifndef ESCENARIO1_H_INCLUDED
#define ESCENARIO1_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"
#include <SFML/Audio.hpp>

using namespace std;




class escenariollegada : public sf::Drawable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:

    escenariollegada();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
};

class Barrera : public sf::Drawable, public Colisionable {
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    Barrera();

  void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};
class Barcito : public sf::Drawable, public Colisionable {
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    Barcito();

  void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};
class Flores : public sf::Drawable, public Colisionable {
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    Flores();

  void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};
class Cerco : public sf::Drawable, public Colisionable {
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    Cerco();

  void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};
class pasto : public sf::Drawable, public Colisionable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    pasto();


     void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};
#endif // ESCENARIO1_H_INCLUDED
