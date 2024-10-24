#ifndef MONSTRUO_H
#define MONSTRUO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colisionable.h"

using namespace std;

class Monstruo : public sf::Drawable, public Colisionable {
    protected:
       float _vida;
       float _danio;
       float _defensa;
       sf::Sprite _sprite;
       sf::Texture _texture;

    public:
        Monstruo();  // Constructor por defecto
        Monstruo(float vida, float danio, float defensa);

        // Métodos para vida
        float getVida() const;
        void Sumarvida(float vida);

        // Métodos para daño
        float getDanio() const;
        void Sumarataque(float danio);

        // Métodos para defensa
        float getDefensa() const;
        void setDefensa(float defensa);

        // Funciones virtuales puras
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
        virtual sf::FloatRect getBounds() const override = 0;
};

// Declaración de las clases derivadas
class Hornerot : public Monstruo {
    public:
        Hornerot();
        void setPosition(float x, float y);
        const sf::Sprite& getSprite() const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
};

class Pelucin : public Monstruo {
    public:
        Pelucin();
        void setPosition(float x, float y);
        const sf::Sprite& getSprite() const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
};

class Balleton : public Monstruo {
    public:
        Balleton();
        void setPosition(float x, float y);
        const sf::Sprite& getSprite() const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
};

class Velom : public Monstruo {
    private:
        string nombre;

    public:
        Velom();
        Velom(const string& nombre);
        string getNombre() const;
        bool operator==(const Velom& other) const;
        void setPosition(float x, float y);
        const sf::Sprite& getSprite() const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
};

class Tukin : public Monstruo {
    public:
        Tukin();
        void setPosition(float x, float y);
        const sf::Sprite& getSprite() const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
};

class Lechuza : public Monstruo {
    public:
        Lechuza();
        void setPosition(float x, float y);
        const sf::Sprite& getSprite() const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
};

class Bufalont : public Monstruo {
    public:
        Bufalont();
        void setPosition(float x, float y);
        const sf::Sprite& getSprite() const;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
};

#endif // MONSTRUO_H
