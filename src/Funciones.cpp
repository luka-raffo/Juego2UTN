#include "Funciones.h"
#include "inventory.h"
#include "Personaje.h"
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include "AnimacionAtaque.h"
#include "Juego.h"
#include <cstdio>
#include "PedirNombre.h"
#include <time.h>


using namespace std;

/*
std::string IngresarNombre() {
    sf::RenderWindow windowNombre(sf::VideoMode(800, 600), "Ingrese Nombre");
    std::string nombreJugador = pedirNombre(windowNombre);
    windowNombre.close();

        std::cout << "Bienvenido, " << nombreJugador << "!" << std::endl;


    return nombreJugador;
}
*/
void startGame() {


    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia Juego");

    // Establecer el límite de FPS
    window.setFramerateLimit(60);

    // Crear un personaje
    Personaje rojo;
    int Banderaposicion = 0; // Inicializamos la bandera en 0

    // Ajustar posición inicial según la bandera antes del bucle de juego
    if (Banderaposicion == 1) {
        rojo.setPosition(650, 0);  // Posición para piso 1
    } else {
        rojo.setPosition(0, 235);  // Posición para piso 2
    }

    // Crear lista de bush
    vector<bush6x4> listaBushes;
    bush6x4 b1, b2, b3;
    b1.setPosition(0, 0);
    b2.setPosition(0, 64);
    b3.setPosition(450, 200);
    listaBushes.push_back(b1);
    listaBushes.push_back(b2);
    listaBushes.push_back(b3);

    // Crear pisos
    piso suelo;
    suelo.setPosition(650, 0);
    piso suelo2;
    suelo2.setPosition(0, 235);

    // Crear fondo
    escenario Fondo;

    // Variables de cooldown
    sf::Clock collisionCooldown;  // Reloj para el tiempo de cooldown
    float cooldownTime = 2.0f;    // Tiempo de cooldown en segundos

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Actualizar el personaje
        rojo.update();

        // Verificar si el cooldown ha pasado
        if (collisionCooldown.getElapsedTime().asSeconds() >= cooldownTime) {
            int EventoPokemon = 2;

            // Verificar colisiones con cada objeto en la lista
            for (const bush6x4& b : listaBushes) {
                if (rojo.isCollision(b)) {
                    EventoPokemon = std::rand() % 2000;
                    if (EventoPokemon < 1000) {  // Umbral ajustable para activar el evento
                        escenarioPelea();
                        collisionCooldown.restart();
                    }

                    cout << "colision" << endl;
                    break;  // Evitar múltiples colisiones en un mismo frame
                }
            }

            // Colisión con el suelo 1
            if (rojo.isCollision(suelo)) {
                starthistoria();
                Banderaposicion = 0;
                rojo.setPosition(650, 0);  // Reposicionar al colisionar con suelo 1
                collisionCooldown.restart();
                rojo.guardarPosicion();
                window.close();
            }

            // Colisión con el suelo 2
            if (rojo.isCollision(suelo2)) {
                llegadaisla();
                Banderaposicion = 1;
                rojo.setPosition(0, 235);  // Reposicionar al colisionar con suelo 2
                collisionCooldown.restart();
                rojo.guardarPosicion();
                window.close();
            }
        }

        // Dibujar todo
        window.clear();
        window.draw(Fondo);

        // Dibujar bush y demás objetos
        for (const bush6x4& b : listaBushes) {
            window.draw(b);
        }
        window.draw(suelo);
        window.draw(suelo2);
        window.draw(rojo);
        window.display();
    }
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void batallacueva()  // Crear una ventana
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia la pelea");

    // Establecer el límite de FPS
    window.setFramerateLimit(60);

    inventory inventario(100);
     bool b_ataqueJugador=false;

    //crear monstruo jugador
        //crear monstruo jugador

    Juego monstruoJugador;

    monstruoJugador.agregarMonstruo(new Velom(20.0f, 50.0f, 30.0f, "include/velom.PNG"));
    monstruoJugador.agregarMonstruo(new Bufalont (10.0f, 50.0f, 30.0f, "include/bufalont.PNG"));
    monstruoJugador.agregarMonstruo(new Tukin(10.0f, 50.0f, 30.0f, "include/tukin.PNG"));
    monstruoJugador.agregarMonstruo(new Lechuza(10.0f, 50.0f, 30.0f, "include/FuckingLechuza.PNG"));
    monstruoJugador.agregarMonstruo(new balleton(10.0f, 50.0f, 30.0f, "include/balleton.PNG"));
    monstruoJugador.agregarMonstruo(new Peluchin(10.0f, 50.0f, 30.0f, "include/pelucin.PNG"));
    monstruoJugador.setPositionTodosMonstruos(70, 470);
    monstruoJugador.setScale(2,2);

    // Crear los monstruos

    //Pelucin pelu;
    //Tukin tuki;
    Lobizon lobo(100.0f, 50.0f, 30.0f,"include/Lobizon.PNG");
    Velom vel(100.0f, 50.0f, 30.0f,"include/velom.PNG");
    //Lechuza lechu;
    //Balleton ballena;
    //Bufalont bufalo;
     AnimacionAtaque ataque;
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
    if (!bufferAtaque.loadFromFile("mamahuevo.wav"))
    {
        std::cout << "Error al cargar mamahuevo.wav" << std::endl;
    }
    sf::Sound sonidoAtaque;
    sonidoAtaque.setBuffer(bufferAtaque);
 /////////////////////////////////////////
  sf::SoundBuffer bufferDefensa;
    if (!bufferDefensa.loadFromFile("Sonidos/paaraaaaa.wav"))
    {
        std::cout << "Error al cargar paaraaaaa.wav" << std::endl;
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

                    monstruoJugador.setDefensaMonstruoActual( rand() % 100 + 1);
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
    if (probabilidadCura < 100) {  // 20% de probabilidad de curación
        float curacion = 20.0f;
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
   if(lobo.getVida()<=0)
            {
              //double tiempoTotal = detenerTemporizador(inicioJuego); // Detener el cronómetro
              //guardarResultado(nombreJugador, tiempoTotal);           // Guardar el tiempo en la clasificación

    // Muestra el tiempo total al jugador (opcional)
    //std::cout << "¡Has completado el juego en " << tiempoTotal << " segundos!" << std::endl;
                 // Cambiar el mensaje a "Eres el vencedor"
              menuTexto.setString("Eres el vencedor");





              menuTexto.setCharacterSize(60);
              menuTexto.setFillColor(sf::Color::Black);
              menuTexto.setPosition(150, 170);

              // Dibujar el fondo
                window.draw(fondo);



            //dibujar monstruo jugador
            window.draw(lobo);
            // Dibujar opciones de pelea siempre en pantalla
            window.draw(menuTexto);
            monstruoJugador.dibujar(window);
            window.display();

              pedirNombre(window, font,usar);

}




}

        // Mostrar lo dibujado

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



void starthistoria()
{
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Escenario final Juego");

    // Establecer el límite de FPS
    window.setFramerateLimit(60);

    // Crear un personaje y cargar su posición
    Personaje rojo;
    bool BanderaPos= true;
    if(BanderaPos= true)
    {
        rojo.cargarPosicion();
    }

    // Crear objetos colisionables
    piso suelo;
    suelo.setPosition(405, 580);
    caverna cueva;
    cueva.setPosition(250, 100);
    vallas valla;
    valla.setPosition(0, 445);
    vallas valla2;
    valla2.setPosition(170, 445);
    vallas valla3;
    valla3.setPosition(450, 445);
    vallas valla4;
    valla4.setPosition(630, 445);

    // Crear fondo
    Escenariojefe fondo1;

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

        // Guardar la posición actual del personaje antes de moverlo
        sf::Vector2f previousPosition = rojo.getPosition();

        // Vector de colisionables
        std::vector<Colisionable*> colisionables = {&valla, &valla2, &valla3, &valla4};

        // Actualizar el personaje
        rojo.update();

        // Verificar colisiones después de actualizar la posición del personaje
        if (collisionCooldown.getElapsedTime().asSeconds() >= cooldownTime)
        {
            // Colisión con el suelo
            if (rojo.isCollision(suelo))
            {
                std::cout << "Colisión con el suelo" << std::endl;
                collisionCooldown.restart();
                rojo.guardarPosicion();
                window.close();
                startGame();
            }

            // Colisión con la cueva
            if (rojo.isCollision(cueva))
            {
                std::cout << "Colisión con la cueva" << std::endl;
                batallacueva();
                collisionCooldown.restart();
            }

            // Colisión con las vallas
            for (const auto& colisionable : colisionables)
            {
                if (rojo.isCollision(*colisionable))
                {
                    // Si hay colisión, revertir a la posición anterior
                    rojo.setPosition(previousPosition.x, previousPosition.y);
                    collisionCooldown.restart();
                    break;
                }
            }
        }

        // Dibujar todo
        window.clear();

        // Dibujar en el orden correcto
        window.draw(fondo1);
        window.draw(suelo);
        window.draw(cueva);
        window.draw(valla);
        window.draw(valla2);
        window.draw(valla3);
        window.draw(valla4);
        window.draw(rojo);

        window.display();
    }
}
void llegadaisla()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia Juego");

    window.setFramerateLimit(60);



    // Crear el personaje y definir su posición inicial
    Personaje rojo;
    rojo.cargarPosicion();
    // Crear fondo y otros objetos
    pasto suelo;
    suelo.setPosition(400, 155);
    escenariollegada Fondo;

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
                startGame();
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
