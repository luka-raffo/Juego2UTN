#ifndef ESCENARIO3_H
#define ESCENARIO3_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"
#include <SFML/Audio.hpp>

using namespace std;

class Escenariojefe : public sf::Drawable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:

    Escenariojefe();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
};

class caverna : public sf::Drawable, public Colisionable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    caverna();


     void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};
class CavernaBattleBackground : public sf::Drawable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:

    CavernaBattleBackground();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
};

class vallas : public sf::Drawable, public Colisionable {
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    vallas();

  void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};
class suelo : public sf::Drawable, public Colisionable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    suelo();


     void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};

#endif // ESCENARIO3_H
