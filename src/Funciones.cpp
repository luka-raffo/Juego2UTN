#include "Funciones.h"
#include "inventory.h"
#include "reloj.h"

#include "Personaje.h"
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include "AnimacionAtaque.h"
#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "PedirNombre.h"
#include "PedirNombre.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "NombreJugador.h"

#include "Escenario.h"
#include "FuncionesRanking.h"


using namespace std;
float getRandomStat(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}






bool grabarRegitroRanking(NombreJugador jugador){
FILE *pRanking;
//sf::Clock clock=rel.getReloj();
//sf::Time tiempoTranscurrido = clock.getElapsedTime();
//float segundos = tiempoTranscurrido.asSeconds();

//cout<<"Holaaaaaaaaaaaaaaaaaaaa" << segundos<<endl;

pRanking=fopen("Ranking.dat","ab");
if(pRanking==nullptr) return false;
int escribio=fwrite(&jugador,sizeof(jugador),1,pRanking);
fclose(pRanking);
return escribio;
}





// Implementación de pedirNombre() modificada (sin el reinicio de reloj)
std::string pedirNombre(sf::RenderWindow& window, sf::Font& font, bool usar) {
    sf::Text textoPrompt("Ingrese su nombre:", font, 24);
    textoPrompt.setPosition(100, 100);
    textoPrompt.setFillColor(sf::Color::White);

    std::string nombreJugador;
    sf::Text nombreText("", font, 24);
    nombreText.setPosition(100, 150);
    nombreText.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return "";
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode == '\b' && !nombreJugador.empty()) {
                        nombreJugador.pop_back();
                    } else if (event.text.unicode == '\r' || event.text.unicode == '\n') {
                        return nombreJugador;
                    } else if (event.text.unicode != '\b') {
                        nombreJugador += static_cast<char>(event.text.unicode);
                    }
                }
            }
        }
        nombreText.setString(nombreJugador);
        window.clear();
        window.draw(textoPrompt);
        window.draw(nombreText);
        window.display();
    }
    return nombreJugador;
}


void llegadaisla(sf::Clock clock)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia Juego");


    NombreJugador jugador;

    window.setFramerateLimit(60);

    reloj rel;
    rel.setReloj(clock);

    grabarRegitroRanking(jugador);



    // Crear el personaje y definir su posición inicial
    Personaje rojo;
    rojo.setPosition(400, 200);
    // Crear fondo y otros objetos
    pasto suelo;
    suelo.setPosition(400, 155);
    EscenarioLlegada Fondo;

    // Crear varias barreras
    Barrera casa;
    casa.setPosition(450, 150);
    Barrera casa2;
    casa2.setPosition(630, 150);
    Barrera casa3;
    casa3.setPosition(225, 300);
    Barrera casa4;
    casa4.setPosition(645, 305);
    // Crear bar
    Barcito bar;
    bar.setPosition(0, 150);
    Barcito bar2;
    bar2.setPosition(197, 150);
    Barcito bar3;
    bar3.setPosition(450, 305);
    Barcito bar4;
    bar4.setPosition(0, 470);
    //crear flores
    Flores Flor;
    Flor.setPosition(190, 470);
    Flores Flor2;
    Flor2.setPosition(0, 300);
    Flores Flor3;
    Flor3.setPosition(620, 480);
    //Crear vallas
    Cerco valla;
    valla.setPosition(430, 550);


    // Agregar las barreras a un vector de objetos colisionables
    std::vector<Colisionable*> colisionables = { &casa, &bar, &Flor,&valla,&casa2,&bar2,&Flor2,&bar3,&bar4,&casa3,&casa4,&Flor3 };

    sf::Clock collisionCooldown;
    float cooldownTime = 1;  // Cooldown de 2 segundos


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        rel.actualizar();



        // Guardar la posición actual del personaje antes de moverlo
        sf::Vector2f previousPosition = rojo.getPosition();

        // Actualizar el personaje
        rojo.update();

        // Verificar colisiones con cada barrera/////////////////////////////
        for (const auto& colisionable : colisionables)
        {
            if (rojo.isCollision(*colisionable))
            {
                // Si hay colisión, revertir a la posición anterior
                rojo.setPosition(previousPosition.x, previousPosition.y);
                break;
            }
        }
////////////////////////////////////////////////////////////////////////////
        if (collisionCooldown.getElapsedTime().asSeconds() >= cooldownTime)
        {
            if(rojo.isCollision(suelo))
            {
                startGame(rel.getReloj());
                rojo.guardarPosicion();
                cout << "colision" << endl;
                collisionCooldown.restart();
                window.close();

            }
        }

        // Dibujar todo
        window.clear();
        window.draw(Fondo);
        ////////
        window.draw(suelo);
        window.draw(casa);
        window.draw(casa2);
        window.draw(casa3);
        window.draw(casa4);
        /////////
        window.draw(bar);
        window.draw(bar2);
        window.draw(bar3);
        window.draw(bar4);
        //////////
        window.draw(Flor);
        window.draw(Flor2);
        window.draw(Flor3);
        ///////////
        window.draw(valla);

        //////////
        window.draw(rojo);
        window.display();
    }
    }



void startGame(sf::Clock clock)
{
    // Crear una ventana
     sf::RenderWindow window(sf::VideoMode(800, 600), "Arbustos");
    // Establecer el límite de FPS
    window.setFramerateLimit(60);



    reloj rel;
    rel.setReloj(clock);



    // Crear un personaje
    Personaje rojo;
    int Banderaposicion = 0; // Inicializamos la bandera en 0


    // Ajustar posición inicial según la bandera antes del bucle de juego
    if (Banderaposicion == 1) {
        rojo.setPosition(650, 0);  // Posición para piso 1
    } else {
        rojo.setPosition(300,580);  // Posición para piso 2
    }

    // Crear lista de bush
    vector<bush6x4> listaBushes;
    bush6x4 b1, b2, b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15;
    b1.setPosition(500, 160);
    b2.setPosition(500, 20);
    b3.setPosition(500, 230);
    b4.setPosition(0, 550);
    b5.setPosition(100,210 );
    b6.setPosition(200,210);
    b7.setPosition(300, 210);
    b8.setPosition(100, 270);
    b9.setPosition(200, 270);
    b10.setPosition(300, 270);
    b11.setPosition(500, 90);
    b12.setPosition(500, 300);
    b13.setPosition(500, 530);
    b14.setPosition(600, 530);
    b15.setPosition(700, 530);
    listaBushes.push_back(b1);
    listaBushes.push_back(b2);
    listaBushes.push_back(b3);
    listaBushes.push_back(b4);
    listaBushes.push_back(b5);
    listaBushes.push_back(b6);
    listaBushes.push_back(b7);
    listaBushes.push_back(b8);
    listaBushes.push_back(b9);
    listaBushes.push_back(b10);
    listaBushes.push_back(b11);
    listaBushes.push_back(b12);
    listaBushes.push_back(b13);
    listaBushes.push_back(b14);
    listaBushes.push_back(b15);



    // Crear pisos
    piso suelo;
    suelo.setPosition(650, 0);
    piso suelo2;
    suelo2.setPosition(300,580);
    //crear arboles
    arboles arbol;
    arbol.setPosition(100,0);
    arboles arbol2;
    arbol2.setPosition(100,100);

    arboles arbol3;
    arbol3.setPosition(10,450);

    arboles arbol4;
    arbol4.setPosition(200,0);
    arboles arbol5;
    arbol5.setPosition(200,100);

    arboles arbol6;
    arbol6.setPosition(300,0);
    arboles arbol7;
    arbol7.setPosition(300,100);

    arboles arbol8;
    arbol8.setPosition(10,0);
    arboles arbol9;
    arbol9.setPosition(10,100);

     arboles arbol10;
    arbol10.setPosition(10,200);
    arboles arbol11;
    arbol11.setPosition(10,300);

     arboles arbol12;
    arbol12.setPosition(400,0);
    arboles arbol13;
    arbol13.setPosition(400,100);

    arboles arbol14;
    arbol14.setPosition(400,200);
    arboles arbol15;
    arbol15.setPosition(400,300);

     arboles arbol16;
    arbol15.setPosition(400,500);
    arboles arbol17;
    arbol17.setPosition(400,300);




    // Crear fondo
    Escenario Fondo("Tileset/nuevo.JPG");


    // Agregar un reloj para el cooldown de colisiones
    sf::Clock collisionCooldown;
    float cooldownTime = 1;  // Cooldown de 1 segundo

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
         // Guardar la posición actual del personaje antes de moverlo
        sf::Vector2f previousPosition = rojo.getPosition();



        //mostrar reloj x consola
        rel.actualizar();



        // Vector de colisionables
        std::vector<Colisionable*> colisionables = {&arbol,&arbol2,&arbol3,&arbol4,&arbol5,&arbol6,&arbol7,&arbol8,&arbol9,&arbol10,&arbol11,&arbol12,&arbol13,&arbol14,&arbol15,&arbol16,&arbol17};


        // Actualizar el personaje
        rojo.update();

        // Verificar si el cooldown ha pasado
        if (collisionCooldown.getElapsedTime().asSeconds() >= cooldownTime)
        {
            int EventoPokemon = 2;

            // Verificar colisiones con cada objeto en la lista
            for (const bush6x4& b : listaBushes)
            {
                if (rojo.isCollision(b))
                {
                    EventoPokemon = std::rand() % 2000;
                    if (EventoPokemon <= 2000)
                    {
                         EscenarioPelea pelea;
                         pelea.iniciar();

                        collisionCooldown.restart();
                    }

                    cout << "colision" << endl;
                    break;  // Evitar múltiples colisiones en un mismo frame
                }
            }

            // Colisión con el suelo 1
            if (rojo.isCollision(suelo))
            {
                starthistoria(rel.getReloj());
                Banderaposicion = 0;
                rojo.setPosition(650, 0);  // Reposicionar al colisionar con suelo 1
                collisionCooldown.restart();
                window.close();
            }

            // Colisión con el suelo 2
            if (rojo.isCollision(suelo2))
            {
                llegadaisla(rel.getReloj());
                Banderaposicion = 1;
                rojo.setPosition(0, 235);  // Reposicionar al colisionar con suelo 2
                collisionCooldown.restart();
                window.close();
            }
        }
              for (const auto& colisionable : colisionables)
        {
            if (rojo.isCollision(*colisionable))
            {
                // Si hay colisión, revertir a la posición anterior
                rojo.setPosition(previousPosition.x, previousPosition.y);
                break;
            }
        }

        // Dibujar todo
        window.clear();

        window.draw(Fondo);
        // Dibujar bush y demás objetos
        for (const bush6x4& b : listaBushes)
        {
            window.draw(b);
        }
         window.draw(arbol);
         window.draw(arbol2);
         window.draw(arbol3);
           window.draw(arbol4);
         window.draw(arbol5);
         window.draw(arbol6);
           window.draw(arbol7);
            window.draw(arbol8);
           window.draw(arbol9);
           window.draw(arbol10);
           window.draw(arbol11);
           window.draw(arbol12);
           window.draw(arbol13);
           window.draw(arbol14);
           window.draw(arbol15);
           window.draw(arbol16);
           window.draw(arbol17);

        window.draw(suelo);
        window.draw(suelo2);
        window.draw(rojo);
        window.display();
    }
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void batallacueva(sf::Clock clock)  // Crear una ventana
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia la pelea");


    reloj rel;
    rel.setReloj(clock);



    // Establecer el límite de FPS
    window.setFramerateLimit(60);

    inventory inventario(100);
     bool b_ataqueJugador=false;

    //crear monstruo jugador
        //crear monstruo jugador

    Juego monstruoJugador;

    monstruoJugador.agregarMonstruo(new Velom(190.0f, 50.0f, 40.0f, "include/velom.PNG"));
    monstruoJugador.agregarMonstruo(new Bufalont (150.0f, 50.0f, 40.0f, "include/bufalont.PNG"));
    monstruoJugador.agregarMonstruo(new Tukin(150.0f, 50.0f, 40.0f, "include/tukin.PNG"));
    monstruoJugador.agregarMonstruo(new Lechuza(150.0f, 50.0f, 40.0f, "include/FuckingLechuza.PNG"));
    monstruoJugador.agregarMonstruo(new balleton(150.0f, 50.0f, 40.0f, "include/balleton.PNG"));
    monstruoJugador.agregarMonstruo(new Peluchin(150.0f, 50.0f, 40.0f, "include/pelucin.PNG"));
    monstruoJugador.setPositionTodosMonstruos(70, 470);
    monstruoJugador.setScale(2,2);

    // Crear los monstruos

    //Pelucin pelu;
    //Tukin tuki;
    Lobizon lobo(500.0f, 60.0f, 50.0f,"include/Lobizon.PNG");
    Velom vel(100.0f, 50.0f, 30.0f,"include/velom.PNG");
    //Lechuza lechu;
    //Balleton ballena;
    //Bufalont bufalo;
    AnimacionAtaque ataque;
    ataque.setRutaPNG("Animations/zoonami_player_vice_grip_animation.PNG");
     AnimacionDefensa Defensa;

    // Variables de pelea
    bool turnoJugador = true;
    bool peleaActiva = true;
    bool opcionSeleccionada = false;


    //PROBANDO  CARTEL DE VICTORIA
    sf::Clock WinCooldown;
    float cooldownTime = 2;


     // Crear buffer para el sonido de ataque
    sf::SoundBuffer bufferAtaque;
    if (!bufferAtaque.loadFromFile("Sonidos/pew.wav"))
    {
        std::cout << "Error al cargar mamahuevo.wav" << std::endl;
    }
    sf::Sound sonidoAtaque;
    sonidoAtaque.setBuffer(bufferAtaque);
 /////////////////////////////////////////
  sf::SoundBuffer bufferDefensa;
    if (!bufferDefensa.loadFromFile("Sonidos/bueeeee.wav"))
    {
        std::cout << "Error al cargar bueeeee.wav" << std::endl;
    }
    sf::Sound sonidoDefensa;
    sonidoDefensa.setBuffer(bufferDefensa);
    /////////////////////////////////////
    sf::SoundBuffer bufferPelea;
    if (!bufferPelea.loadFromFile("Sonidos/dificil.wav"))
    {
        std::cout << "Error al cargar dificil.wav" << std::endl;
    }
    sf::Sound sonidoPelea;
    sonidoPelea.setBuffer(bufferPelea);
    ///////////////////////////////////////////
          sf::SoundBuffer bufferVictoria;
    if (!bufferVictoria.loadFromFile("Sonidos/bokita.wav"))
    {
        std::cout << "Error al cargar bokita.wav" << std::endl;
    }
    sf::Sound sonidoVictoria;
    sonidoVictoria.setBuffer(bufferVictoria);





    // crear el fondo
    CavernaBattleBackground fondo;

    // Crear elementos del menú en pantalla
    sf::Font font;
    font.loadFromFile("include/Pokemon.ttf");

    sf::Text menuTexto;
    menuTexto.setFont(font);
    menuTexto.setString("1) Atacar  2) Defender");
    menuTexto.setCharacterSize(24);
    menuTexto.setFillColor(sf::Color::Black);
    menuTexto.setPosition(500, 500);

    bool usar=true;
    bool ganaste=false;

    //elementos monstruo jugador
    //monstruoJugador.setPosition(30, 350);  // Jugador a la izquierda
   // monstruoJugador.setScale(4,4);
    float defensaTotal;

    //cartel opciones pelea
    // Submenú para que el jugador elija la acción: atacar, defender, capturar (si es posible)
    cout << "Elige una acción: 1) Atacar 2) Defender"<<endl;



    cout<<"la vida de tu pokemon es: "<<monstruoJugador.getVidaMonstruoActual()<<endl;
    cout<<"el daño de tu pokemon es: "<<monstruoJugador.getDanioMonstruoActual()<<endl;
    cout<<"La defensa de tu pokemon es: "<<monstruoJugador.getDefensaMonstruoActual()<<endl;




    // Seleccionar un monstruo aleatorio con probabilidades distintas
    int probabilidad = std::rand() % 100;  // Generar un número entre 0 y 99 (100 posibles valores)
    sf::Drawable* monstruoSeleccionado = nullptr;

    // Asignar monstruo según probabilidad


     if (probabilidad < 100)    // 10% de probabilidad para Velom (60 + 10 = 70)
    {
        lobo.setPosition(520, 100);

        cout<<"hola"<<endl;

        lobo.setScale(2,2);
        cout<<"la vida del enemigo es: " << lobo.getVida()<<endl;
        cout<<"el daño del enemigo es: " << lobo.getDanio()<<endl;
        cout<<"La defensa del enemigo es: " << lobo.getDefensa()<<endl;
        sonidoPelea.play();

    }



    // Bucle del juego

    while (window.isOpen() && peleaActiva)
    {
        sf::Event event;




        while (window.pollEvent(event))
        {

            rel.actualizar();



            if (event.type == sf::Event::Closed)
                window.close();

            // Salir del escenario al presionar ESC
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            // Lógica de pelea por turnos

            if (turnoJugador)
            {

                //opciones de pelea
                if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::Num1)    // Atacar
                {
                    cout << "Atacas al enemigo!" << endl;

                    ataque.startAnimation();

                    sonidoAtaque.play(); // Reproducir sonido de ataque

                    b_ataqueJugador=true;
                    sonidoAtaque.play();

                    if (lobo.getDefensa() > monstruoJugador.getDanioMonstruoActual())
                    {
                        cout << "El enemigo ah bloqueado tu ataque!" << endl;
                        lobo.setDefensa(lobo.getDefensa()-monstruoJugador.getDanioMonstruoActual());
                    }
                    else if(monstruoJugador.getDefensaMonstruoActual()<=lobo.getDanio())
                    {

                        cout << "Tu Monstruo ah hecho " << monstruoJugador.getDanioMonstruoActual()<<" de daño" << endl;

                        lobo.setVida(lobo.getVida()+lobo.getDefensa()-monstruoJugador.getDanioMonstruoActual());

                        cout << "La vida del enemigo es: "<< lobo.getVida() << endl;

                        lobo.setDefensa(0);

                    }

                    turnoJugador=false;

                }
                else if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::Num2)      // Defender
                {
                    cout << "Te defiendes!" << endl;

                    monstruoJugador.setDefensaMonstruoActual( rand() % 60 + 1);
                    cout<<"defensa mi monstruo aumento = "<<monstruoJugador.getDefensaMonstruoActual()<<endl;
                    sonidoDefensa.play(); // Reproducir sonido de ataque
                    Defensa.startAnimation();
                    turnoJugador=false;
                }

            }
           else {
    // Turno del enemigo
    cout << "El enemigo ataca!" << endl;

    // Probabilidad de curación para el enemigo
    int probabilidadCura = rand() % 100;
    if (probabilidadCura < 40) {  // 20% de probabilidad de curación
        float curacion = 40.0f;
        lobo.setVida(lobo.getVida() + curacion);  // 'vel' representa al monstruo enemigo
        cout << "El enemigo se ha curado " << curacion << " puntos de vida." << endl;

        // Cambiar turno al jugador después de curarse
        turnoJugador = true;
    } else {
        // Lógica de ataque del enemigo
        if (monstruoJugador.getDefensaMonstruoActual() > lobo.getDefensa()) {
            cout << "El ataque fue bloqueado con éxito!" << endl;
            monstruoJugador.setDefensaMonstruoActual(monstruoJugador.getDefensaMonstruoActual() - lobo.getDanio());

            // Cambiar turno al jugador
            turnoJugador = true;
        } else if (monstruoJugador.getDefensaMonstruoActual() <= lobo.getDanio()) {
            cout << "El enemigo ha hecho: " << lobo.getDanio() << endl;

            monstruoJugador.setVidaMonstruoActual(monstruoJugador.getVidaMonstruoActual() + monstruoJugador.getDefensaMonstruoActual() - lobo.getDanio());
            cout << "La vida de tu monstruo es: " << monstruoJugador.getVidaMonstruoActual() << endl;

            monstruoJugador.setDefensaMonstruoActual(0);

            // Cambiar turno al jugador
            turnoJugador = true;
        }
        cout << "Defensa de mi monstruo = " << monstruoJugador.getDefensaMonstruoActual() << endl;
    }
}


if (lobo.getVida() <= 0) {
    menuTexto.setString("Eres el vencedor");
    menuTexto.setCharacterSize(60);
    menuTexto.setFillColor(sf::Color::Black);
    menuTexto.setPosition(150, 170);

    window.draw(fondo);
    window.draw(lobo);
    window.draw(menuTexto);
    monstruoJugador.dibujar(window);
    window.display();


}
if(monstruoJugador.getVidaMonstruoActual()<=0){
  monstruoJugador.pasarAlSiguienteMonstruo();
}


}

        // Mostrar lo dibujado
        ataque.update();
        Defensa.update();

        // Dibujar el fondo
        window.draw(fondo);



        //dibujar monstruo jugador
        window.draw(lobo);
        // Dibujar opciones de pelea siempre en pantalla
        window.draw(menuTexto);



        window.draw(ataque);
        window.draw(Defensa);

        //dibujar las opciones de la pelea

        monstruoJugador.dibujar(window);
        window.display();

    }
}


void starthistoria(sf::Clock clock)
{
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Escenario final Juego");



    reloj rel;

    rel.setReloj(clock);





    // Establecer el límite de FPS
    window.setFramerateLimit(60);

    // Crear un personaje y cargar su posición
    Personaje rojo;
    bool BanderaPos= true;
    if(BanderaPos= true)
    {
     rojo.setPosition(450, 570);
    }

    // Crear objetos colisionables
    suelo piso;
    piso.setPosition(450, 580);
    caverna cueva;
    cueva.setPosition(250, 100);
    vallas valla;
    valla.setPosition(0, 445);
    vallas valla2;
    valla2.setPosition(150, 445);
    vallas valla3;
    valla3.setPosition(450, 445);
    vallas valla4;
    valla4.setPosition(600, 445);
    vallas valla5;
    valla5.setPosition(750, 445);

    // Crear fondo
    EscenarioJefe fondo1;



    // Agregar un reloj para el cooldown de colisiones
    sf::Clock collisionCooldown;
    float cooldownTime = 1.0f;  // Cooldown de 1 segundo

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                rojo.guardarPosicion();
                window.close();
            }
        }



        rel.actualizar();




        // Guardar la posición actual del personaje antes de moverlo
        sf::Vector2f previousPosition = rojo.getPosition();

        // Vector de colisionables
        std::vector<Colisionable*> colisionables = {&valla, &valla2, &valla3, &valla4,&valla5};

        // Actualizar el personaje
        rojo.update();

        // Verificar colisiones después de actualizar la posición del personaje
        if (collisionCooldown.getElapsedTime().asSeconds() >= cooldownTime)
        {
            // Colisión con el suelo
            if (rojo.isCollision(piso))
            {
                std::cout << "Colisión con el suelo" << std::endl;
                collisionCooldown.restart();
                rojo.guardarPosicion();
                window.close();
                startGame(rel.getReloj());
            }

            // Colisión con la cueva
            if (rojo.isCollision(cueva))
            {

                std::cout << "Colisión con la cueva" << std::endl;
                Batallacaverna batalla;
               batalla.iniciar(rel.getReloj());
               batalla.finReloj(rel.getReloj());
               collisionCooldown.restart();

            }

            // Colisión con las vallas
            for (const auto& colisionable : colisionables)
        {
            if (rojo.isCollision(*colisionable))
            {
                // Si hay colisión, revertir a la posición anterior
                rojo.setPosition(previousPosition.x, previousPosition.y);
                break;
            }
        }
        }

        // Dibujar todo
        window.clear();

        // Dibujar en el orden correcto
        window.draw(fondo1);
        window.draw(piso);
        window.draw(cueva);
        window.draw(valla);
        window.draw(valla2);
        window.draw(valla3);
        window.draw(valla4);
        window.draw(valla5);
        window.draw(rojo);

        window.display();
    }
}

