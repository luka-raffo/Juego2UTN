#ifndef ESCENARIO2_H
#define ESCENARIO2_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"

using namespace std;
class escenario : public sf::Drawable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:

    escenario();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
};

class bush : public sf::Drawable, public Colisionable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    bush();


     void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};

class bush6x4 : public sf::Drawable, public Colisionable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    bush6x4();



     void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};
class BattleBackground : public sf::Drawable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:

    BattleBackground();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(_sprite, states);
    }
};


class piso : public sf::Drawable, public Colisionable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    piso();


     void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};
class arboles : public sf::Drawable, public Colisionable {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    arboles();


     void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;


};


#endif // ESCENARIO2_H
