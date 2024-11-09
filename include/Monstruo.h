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

    //nuevos atributos
    int _nivel;
    float _experiencia; // Nueva experiencia



public:
        Monstruo();  // Constructor por defecto
        Monstruo(float vida, float danio, float defensa);

        bool cargarTextura(const string& archivo);

        const sf::Sprite& getSpriteAtaque() const;

        void iniciarAnimacionAtaque();

        void reiniciarAnimacion();

        void actualizarAnimacionAtaque();

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

        // Métodos para nivel y experiencia
    int getNivel() const;
    float getExperiencia() const;
    void ganarExperiencia(float exp);

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
//hornerot
class Hornerot : public Monstruo
{
private:
    sf::Texture _HornerotTexture; // Textura específica del Velom

   //nuevos atributos
    int _nivel;
    float _experiencia; // Nueva experiencia


public:
    Hornerot();
    Hornerot(float vida, float danio, float defensa, const string& texturaArchivo);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

     bool cargarTextura(const string& archivo);
};
//peluchin

class Peluchin : public Monstruo
{
private:
    sf::Texture _PeluchinTexture; // Textura específica del Velom
    //nuevos atributos
    int _nivel;
    float _experiencia; // Nueva experiencia


public:
    Peluchin();
    Peluchin(float vida, float danio, float defensa, const string& texturaArchivo);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

     bool cargarTextura(const string& archivo);
};
class balleton : public Monstruo
{
private:
    sf::Texture _BalletonTexture; // Textura específica del Velom
   //nuevos atributos
    int _nivel;
    float _experiencia; // Nueva experiencia



public:
    balleton();
    balleton(float vida, float danio, float defensa, const string& texturaArchivo);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

     bool cargarTextura(const string& archivo);
};



class Velom : public Monstruo
{
private:
    sf::Texture _velomTexture; // Textura específica del Velom

//nuevos atributos
    int _nivel;
    float _experiencia; // Nueva experiencia





public:
    Velom();
    Velom(float vida, float danio, float defensa, const string& texturaArchivo);


    void actualizar();


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

     bool cargarTextura(const string& archivo);
};


//tukin
class Tukin : public Monstruo
{
private:
    sf::Texture _TukinTexture; // Textura específica del Velom

  //nuevos atributos
    int _nivel;
    float _experiencia; // Nueva experiencia


public:
    Tukin();
    Tukin(float vida, float danio, float defensa, const string& texturaArchivo);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

     bool cargarTextura(const string& archivo);
};
//lechuza
class Lechuza : public Monstruo
{
private:
    sf::Texture _LechuzaTexture; // Textura específica del Velom

    //nuevos atributos
    int _nivel;
    float _experiencia; // Nueva experiencia


public:
    Lechuza();
    Lechuza(float vida, float danio, float defensa, const string& texturaArchivo);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

     bool cargarTextura(const string& archivo);
};
//bufalont
class Bufalont : public Monstruo
{
private:
    sf::Texture _BufalontTexture; // Textura específica del Velom

  //nuevos atributos
    int _nivel;
    float _experiencia; // Nueva experiencia


public:
    Bufalont();
    Bufalont(float vida, float danio, float defensa, const string& texturaArchivo);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

     bool cargarTextura(const string& archivo);
};
//lechuza
class Lobizon : public Monstruo
{
private:
    sf::Texture _LobizonTexture; // Textura específica del Velom

//nuevos atributos
    int _nivel;
    float _experiencia; // Nueva experiencia


public:
    Lobizon();
    Lobizon(float vida, float danio, float defensa, const string& texturaArchivo);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

     bool cargarTextura(const string& archivo);
};
#endif // MONSTRUO_H
