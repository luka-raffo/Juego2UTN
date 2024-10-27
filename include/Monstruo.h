#ifndef MONSTRUO_H
#define MONSTRUO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"

using namespace std;

class Monstruo :public sf::Drawable, public Colisionable
{
private:
    string nombre;
    float _vida;
    float _danio;
    float _defensa;
    sf::Sprite _sprite;
    sf::Texture _texture;

protected:
    sf::Sprite& getSprite();

public:
        Monstruo();  // Constructor por defecto
        Monstruo(float vida, float danio, float defensa);

        bool cargarTextura(const string& archivo);


        // Métodos para vida
        float getVida() const;
        void Sumarvida(float vida);
        void setVida(float vida);

        // Métodos para daño
        float getDanio() const;
        void Sumarataque(float danio);
        void setAtaque(float danio);

        // Métodos para defensa
        float getDefensa() const;
        void setDefensa(float defensa);

        // Métodos para posición y escala
        void setPosition(float x, float y);
        void setScale(float x, float y);

        // Métodos para obtener el sprite y el nombre
        const sf::Sprite& getSprite() const;
        std::string getNombre() const;
        void setNombre(const std::string& nombre);

        // Sobrecarga del operador ==
        bool operator==(const Monstruo& other) const;

        // Funciones virtuales puras
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
        virtual sf::FloatRect getBounds() const override = 0;
};

/*class Hornerot :public sf::Drawable, public Colisionable
{
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
    void setPosition(float x, float y)
    {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const
    {
        return _sprite;
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};

*/


/*class Pelucin : public sf::Drawable,public Colisionable
{
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
    void setPosition(float x, float y)
    {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const
    {
        return _sprite;
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};*/
/*class Balleton : public sf::Drawable,public Colisionable
{
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
    void setPosition(float x, float y)
    {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const
    {
        return _sprite;
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};*/



class Velom : public Monstruo
{
private:
    sf::Texture _velomTexture; // Textura específica del Velom



public:
    Velom();
    Velom(float vida, float danio, float defensa, const string& texturaArchivo);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

     bool cargarTextura(const string& archivo);
};



/*
class Tukin : public sf::Drawable,public Colisionable
{
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
    void setPosition(float x, float y)
    {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const
    {
        return _sprite;
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};

/*


/*class Lechuza : public sf::Drawable,public Colisionable
{
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
    void setPosition(float x, float y)
    {
        _sprite.setPosition(x, y);
    };



    const sf::Sprite& getSprite() const
    {
        return _sprite;
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};

*/
/*
class Bufalont : public sf::Drawable,public Colisionable
{
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
    void setPosition(float x, float y)
    {
        _sprite.setPosition(x, y);
    };
    const sf::Sprite& getSprite() const
    {
        return _sprite;
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;
};

*/
#endif // MONSTRUO_H
