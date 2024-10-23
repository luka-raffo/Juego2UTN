#ifndef MONSTRUO_H
#define MONSTRUO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"

using namespace std;

class Monstruo :public sf::Drawable, public Colisionable{
    private:

       float _vida=100;
       float _danio=25;
       sf::Sprite _sprite;
       sf::Texture _texture;

};

class Hornerot :public sf::Drawable, public Colisionable{
    private:

       float _vida=100;
       float _danio=25;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Hornerot();
 void Sumarvida(float vida);
 void Sumarataque( float danio);
 void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }
 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  sf::FloatRect getBounds() const override;
};




class Pelucin : public sf::Drawable,public Colisionable{
    private:

       float _vida=150;
       float _danio=35;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Pelucin();
 void Sumarvida(float vida);
 void Sumarataque( float danio);
 void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }
 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  sf::FloatRect getBounds() const override;
};
class Balleton : public sf::Drawable,public Colisionable {
    private:

       float _vida=200;
       float _danio=40;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Balleton();
 void Sumarvida(float vida);
 void Sumarataque( float danio);
 void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }
 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  sf::FloatRect getBounds() const override;
};



class Velom : public sf::Drawable,public Colisionable {
    private:

       string nombre;

       float _vida=190;
       float _danio=70;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Velom();
        Velom(const string& nombre);

 void Sumarvida(float vida);
 void Sumarataque( float danio);
  void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }

    string getNombre() const;

    bool operator==(const Velom& other) const;

 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  sf::FloatRect getBounds() const override;
};




class Tukin : public sf::Drawable,public Colisionable{
    private:

       float _vida=200;
       float _danio=60;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Tukin();
 void Sumarvida(float vida);
 void Sumarataque( float danio);
 void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }
 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  sf::FloatRect getBounds() const override;
};




class Lechuza : public sf::Drawable,public Colisionable {
    private:

       float _vida=250;
       float _danio=50;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Lechuza();
 void Sumarvida(float vida);
 void Sumarataque( float danio);
  void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }
 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  sf::FloatRect getBounds() const override;
};



class Bufalont : public sf::Drawable,public Colisionable {
    private:

       float _vida=250;
       float _danio=50;
       sf::Sprite _sprite;
       sf::Texture _texture;
    //std::rand()%700+100
    public:
        Bufalont();
 void Sumarvida(float vida);
 void Sumarataque( float danio);
 void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const {
        return _sprite;
    }
 virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  sf::FloatRect getBounds() const override;
};


#endif // MONSTRUO_H
