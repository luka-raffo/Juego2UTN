#include "Funciones.h"
#include "inventory.h"
#include "Personaje.h"
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include "AnimacionAtaque.h"


using namespace std;
void startGame()
{
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia Juego");

    // Establecer el límite de FPS
    window.setFramerateLimit(60);

    // Crear un personaje
    Personaje rojo;
    int Banderaposicion;
    rojo.cargarPosicion();



    // Crear lista de bush
    vector<bush6x4> listaBushes;
    bush6x4 b1, b2, b3;
    b1.setPosition(0, 0);
    b2.setPosition(0, 64);
    b3.setPosition(450, 200);
    listaBushes.push_back(b1);
    listaBushes.push_back(b2);
    listaBushes.push_back(b3);
    piso suelo;
    suelo.setPosition(650,0);
    piso suelo2;
    suelo2.setPosition(0,235);

    // Crear fondo
    escenario Fondo;
    // Agregar un reloj para el cooldown de colisiones
    sf::Clock collisionCooldown;
    float cooldownTime = 1;  // Cooldown de 2 segundos

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

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
                        escenarioPelea();
                        // Reiniciar el reloj del cooldown al activar la pelea
                        collisionCooldown.restart();
                    }

                    cout << "colision" << endl;
                    break;  // Evitar múltiples colisiones en un mismo frame
                }
            }
        }
        if (collisionCooldown.getElapsedTime().asSeconds() >= cooldownTime)
        {
            if (rojo.isCollision(suelo))
            {
                starthistoria();
                Banderaposicion=1;
                collisionCooldown.restart();
                rojo.guardarPosicion();
                window.close();
            }
        }
        if (collisionCooldown.getElapsedTime().asSeconds() >= cooldownTime)
        {
            if (rojo.isCollision(suelo2))
            {
                llegadaisla();
                Banderaposicion=0;
                rojo.guardarPosicion();
                collisionCooldown.restart();
                window.close();
            }
        }

        // Dibujar todo
        window.clear();

        /************ Los window.draw se dibujan según su orden creando capas **************/
        window.draw(Fondo);

        // Recorrer la lista y dibujar los bush
        for (const bush6x4& b : listaBushes)
        {
            window.draw(b);
        }
        window.draw(suelo);
        window.draw(suelo2);
        window.draw(rojo);
        window.display();
    }
}

void escenarioPelea()
{
    // Inicializa la semilla del generador de números aleatorios
    srand(static_cast<unsigned>(time(0)));

    bool b_ataqueJugador=false;

    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Inicia la pelea");

    // Establecer el límite de FPS
    window.setFramerateLimit(60);

    inventory inventario(100);



    //crear monstruo jugador
    Velom monstruoJugador(100.0f, 50.0f, 30.0f,"include/velom.PNG");

    // Crear los monstruos
    Velom monstruo(100.0f, 50.0f, 30.0f,"include/velom.PNG");

    Velom vel (1000.0f, 50.0f, 30.0f, "include/velom.PNG");
    //Pelucin pelu;
    //Peluchin pelu(100.0f, 50.0f, 30.0f,"include/peluchin.PNG");
    //Tukin tuki;
    Tukin tuka(100.0f, 50.0f, 30.0f,"include/tukin.PNG");
    //Lechuza lechu;
    Lechuza lechu(100.0f, 50.0f, 30.0f,"include/FuckingLechuza.PNG");
    //Balleton ballena;
    balleton ballena(100.0f, 50.0f, 30.0f,"include/balleton.PNG");
    //Bufalont bufalo;
    Bufalont bufalo(100.0f, 50.0f, 30.0f,"include/bufalont.PNG");



    AnimacionAtaque ataque;


    // Variables de pelea
    bool turnoJugador = true;  // Variable para alternar los turnos
    bool capturable = false;   // Indica si el monstruo puede ser capturado
    bool peleaActiva = true;
    bool opcionSeleccionada = false;


    //PROBANDO cosas del CARTEL DE VICTORIA
    sf::Clock WinCooldown;
    float cooldownTime = 5;

     // Crear buffer para el sonido de ataque
    sf::SoundBuffer bufferAtaque;
    if (!bufferAtaque.loadFromFile("mamahuevo.wav")) {
        std::cout << "Error al cargar mamahuevo.wav" << std::endl;
    }
    sf::Sound sonidoAtaque;
    sonidoAtaque.setBuffer(bufferAtaque);

    // crear el fondo
    BattleBackground fondo;


    // Crear elementos del menú en pantalla
    sf::Font font;
    font.loadFromFile("include/Pokemon.ttf");
   sf::Text menuTexto;

    menuTexto.setFont(font);
    menuTexto.setString("1) Atacar  2) Defender");
    menuTexto.setCharacterSize(24);
    menuTexto.setFillColor(sf::Color::Black);
    menuTexto.setPosition(350, 400);

    //elementos monstruo jugador
    monstruoJugador.setPosition(30, 350);  // Jugador a la izquierda
    monstruoJugador.setScale(4,4);
    float defensaTotal;

    //cartel opciones pelea
    // Submenú para que el jugador elija la acción: atacar, defender, capturar (si es posible)
    cout << "Elige una acción: 1) Atacar 2) Defender"<<endl;


    cout<<"la vida de tu pokemon es: "<<monstruoJugador.getVida()<<endl;
    cout<<"el daño de tu pokemon es: "<<monstruoJugador.getDanio()<<endl;
    cout<<"La defensa de tu pokemon es: "<<monstruoJugador.getDefensa()<<endl;




    // Seleccionar un monstruo aleatorio con probabilidades distintas
    int probabilidad = std::rand() % 100;  // Generar un número entre 0 y 99 (100 posibles valores)
    sf::Drawable* monstruoSeleccionado = nullptr;

    // Asignar monstruo según probabilidad
    if (probabilidad < 0)    // 20% de probabilidad para Hornerot
    {
        vel.setPosition(570, 160);


        monstruoSeleccionado = &monstruo;
        cout<<"entro al if"<<endl;
    }


    /*else if (probabilidad < 35) {  // 15% de probabilidad para Pelucin (20 + 15 = 35)
        pelu.setPosition(570, 160);
        monstruoSeleccionado = &pelu;
    }*/


    /*else if (probabilidad < 60) {  // 25% de probabilidad para Tukin (35 + 25 = 60)
        tuki.setPosition(570, 160);
        monstruoSeleccionado = &tuki;
    }*/


    else if (probabilidad < 100)    // 10% de probabilidad para Velom (60 + 10 = 70)
    {
        vel.setPosition(570, 160);
        monstruoSeleccionado = &vel;
        cout<<"hola"<<endl;
        inventario.agregarItem(vel);
        inventario.mostrarInventario();
        vel.setScale(2,2);
        cout<<"la vida del enemigo es: " << vel.getVida()<<endl;
        cout<<"el daño del enemigo es: " << vel.getDanio()<<endl;
        cout<<"La defensa del enemigo es: " << vel.getDefensa()<<endl;
        if (capturable)
        {
            cout << " 3) Capturar" << endl;
        }

    }


    /*else if (probabilidad < 80) {  // 10% de probabilidad para Lechuza (70 + 10 = 80)
        lechu.setPosition(570, 160);
        monstruoSeleccionado = &lechu;
    }*/


    /*else if (probabilidad < 90) {  // 10% de probabilidad para Balleton (80 + 10 = 90)
        ballena.setPosition(570, 160);
        monstruoSeleccionado = &ballena;
    }*/


    /*else {  // 10% de probabilidad para Bufalont (90 a 99)
        bufalo.setPosition(570, 160);
        monstruoSeleccionado = &bufalo;
    }*/





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

                    //sonidoAtaque.play(); // Reproducir sonido de ataque


                    b_ataqueJugador=true;






                    if (vel.getDefensa() > monstruoJugador.getDanio())
                    {
                        cout << "El enemigo ah bloqueado tu ataque!" << endl;
                        vel.setDefensa(vel.getDefensa()-monstruoJugador.getDanio());
                    }
                    else if(monstruoJugador.getDefensa()<=vel.getDanio())
                    {

                        cout << "Tu Monstruo ah hecho " << monstruoJugador.getDanio()<<" de daño" << endl;

                        vel.setVida(vel.getVida()+vel.getDefensa()-monstruoJugador.getDanio());

                        cout << "La vida del enemigo es: "<< vel.getVida() << endl;

                        vel.setDefensa(0);



                    }





                    turnoJugador=false;

                }
                else if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::Num2)      // Defender
                {
                    cout << "Te defiendes!" << endl;

                    monstruoJugador.setDefensa( rand() % 100 + 1);
                    cout<<"defensa mi monstruo aumento = "<<monstruoJugador.getDefensa()<<endl;


                    turnoJugador=false;


                }

                /* else if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::Num3 && capturable)    // Capturar
                 {
                     cout << "Intentas capturar al enemigo!" << endl;
                     int probCaptura = rand() % 100;
                     if (probCaptura < 50)    // Supongamos una chance de 50%
                     {
                         cout << "Capturaste al enemigo!" << endl;
                         // inventario.agregarItem(enemigo);
                         peleaActiva = false;
                     }
                     else
                     {
                         cout << "El intento de captura falló." << endl;
                     }
                     turnoJugador=false;
                 }*/


            }
            else
            {
                // Turno del enemigo
                cout << "El enemigo ataca!" << endl;



                if (monstruoJugador.getDefensa() > vel.getDanio())
                {
                    cout << "El ataque fue bloqueado con exito!" << endl;
                    monstruoJugador.setDefensa(monstruoJugador.getDefensa()-vel.getDanio());
                    // Cambiar turno al jugador
                    turnoJugador = true;
                }
                else if(monstruoJugador.getDefensa()<=vel.getDanio())
                {

                    cout << "El enemigo ah hecho: "<< vel.getDanio() << endl;

                    monstruoJugador.setVida(monstruoJugador.getVida()+monstruoJugador.getDefensa()-vel.getDanio());

                    cout << "La vida de tu pokemon es: "<< monstruoJugador.getVida() << endl;

                    monstruoJugador.setDefensa(0);
                    // Cambiar turno al jugador
                    turnoJugador = true;

                }
                cout<<"defensa mi monstruo= "<<monstruoJugador.getDefensa()<<endl;




            }} /*else
        {
            // Probabilidad de curación para el enemigo
            int probabilidadCura = rand() % 100;
            if (probabilidadCura < 20)  // 20% de probabilidad de curación
            {
                float curacion = 20.0f;
                vel.setVida(vel.getVida() + curacion);
                std::cout << "El enemigo se ha curado " << curacion << " puntos de vida." << std::endl;
                turnoJugador = true;  // Pierde el turno al curarse
            }}*/


            ataque.update();

            // Limpiar la pantalla
            window.clear();

            // Verificar si el enemigo es capturable
            if (vel.getVida() <= vel.getVida() * 0.25)
            {
                capturable = true;
            }
            if(vel.getVida()<=0)
            {
                //cout<<"FELICIDADES GANASTE"<<endl;
                menuTexto.setString("Eres el vencedor");
                menuTexto.setCharacterSize(60);
                menuTexto.setFillColor(sf::Color::Black);
                menuTexto.setPosition(150, 170);
                window.draw(menuTexto);
                if (WinCooldown.getElapsedTime().asSeconds() >= cooldownTime)
                {
                    window.close();

                }
                // *Distribución de experiencia al ganar*
                int expGanada = 30; // Ajusta este valor a tu preferencia
                monstruoJugador.ganarExperiencia(expGanada); // Agregar exp al monstruo del jugador
                cout << "Ganaste " << expGanada << " puntos de experiencia!" << endl;

                peleaActiva = false;

            }
            else if(monstruoJugador.getVida()<=0)
            {

                menuTexto.setString("Perdiste");
                menuTexto.setCharacterSize(60);
                menuTexto.setFillColor(sf::Color::Black);
                menuTexto.setPosition(150, 170);
                window.draw(menuTexto);
                if (WinCooldown.getElapsedTime().asSeconds() >= cooldownTime)
                {
                    window.close();
                }
            }






            // Mostrar lo dibujado

            // Dibujar el fondo
            window.draw(fondo);

            // Dibujar el monstruo seleccionado
            if (monstruoSeleccionado != nullptr)
            {
                window.draw(*monstruoSeleccionado);
            }
            else
            {
                cout<<"mamahuevo"<<endl;
            }

            //dibujar monstruo jugador
            window.draw(monstruoJugador);
             // Dibujar opciones de pelea siempre en pantalla
               window.draw(menuTexto);



            window.draw(ataque);

            //dibujar las opciones de la pelea


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

    //crear monstruo jugador
    Velom monstruoJugador(100.0f, 50.0f, 30.0f,"include/velom.PNG");

    // Crear los monstruos
    Velom monstruo(100.0f, 50.0f, 30.0f,"include/velom.PNG");
    //Pelucin pelu;
    //Tukin tuki;
    Lobizon lobo(100.0f, 50.0f, 30.0f,"include/Lobizon.PNG");
    Velom vel(100.0f, 50.0f, 30.0f,"include/velom.PNG");
    //Lechuza lechu;
    //Balleton ballena;
    //Bufalont bufalo;


    // Variables de pelea
    bool turnoJugador = true;
    bool peleaActiva = true;
    bool opcionSeleccionada = false;
    ;

    //PROBANDO GILADAS CARTEL DE VICTORIA
    sf::Clock WinCooldown;
    float cooldownTime = 2;

    // sonido, funca si podes configurar el codeblocks
      sf::SoundBuffer buffer;
       buffer.loadFromFile("include/mamahuevo.wav");

       sf::Sound sound;
       sound.setBuffer(buffer);




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
    menuTexto.setPosition(95, 360);

    //elementos monstruo jugador
    monstruoJugador.setPosition(30, 350);  // Jugador a la izquierda
    monstruoJugador.setScale(4,4);
    float defensaTotal;

    //cartel opciones pelea
    // Submenú para que el jugador elija la acción: atacar, defender, capturar (si es posible)
    cout << "Elige una acción: 1) Atacar 2) Defender"<<endl;


    cout<<"la vida de tu pokemon es: "<<monstruoJugador.getVida()<<endl;
    cout<<"el daño de tu pokemon es: "<<monstruoJugador.getDanio()<<endl;
    cout<<"La defensa de tu pokemon es: "<<monstruoJugador.getDefensa()<<endl;



    // Seleccionar un monstruo aleatorio con probabilidades distintas
    int probabilidad = std::rand() % 100;  // Generar un número entre 0 y 99 (100 posibles valores)
    sf::Drawable* monstruoSeleccionado = nullptr;

    // Asignar monstruo según probabilidad
    if (probabilidad < 0)    // 20% de probabilidad para Hornerot
    {
        lobo.setPosition(600, 160);


        monstruoSeleccionado = &monstruo;
        cout<<"entro al if"<<endl;
    }




    else if (probabilidad < 100)
    {
        lobo.setPosition(550, 100);
        monstruoSeleccionado = &lobo;
        cout<<"hola"<<endl;
        inventario.agregarItem(vel);
        inventario.mostrarInventario();
        lobo.setScale(2,2);
        cout<<"la vida del enemigo es: " << lobo.getVida()<<endl;
        cout<<"el daño del enemigo es: " << lobo.getDanio()<<endl;
        cout<<"La defensa del enemigo es: " << lobo.getDefensa()<<endl;


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





                // Dibujar el fondo
                window.draw(fondo);

                // Dibujar el monstruo seleccionado
                if (monstruoSeleccionado != nullptr)
                {
                    window.draw(*monstruoSeleccionado);
                }
                else
                {
                    cout<<"mamahuevo"<<endl;
                }




                // Lógica de pelea por turnos
                if (turnoJugador)
                {



                    //opciones de pelea
                    if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::Num1)    // Atacar
                    {


                        cout << "Atacas al enemigo!" << endl;
                        lobo.setVida(lobo.getVida()-monstruoJugador.getDanio());
                        cout << "Tu Monstruo ah hecho " << monstruoJugador.getDanio()<<" de daño" << endl;

                        cout << "La vida del enemigo! es " << lobo.getVida() << endl;

                        //sound.play();

                        turnoJugador=false;

                    }

                    else if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::Num2)      // Defender
                    {
                        cout << "Te defiendes!" << endl;
                        defensaTotal = monstruoJugador.getDefensa();
                        turnoJugador=false;

                        if (defensaTotal > lobo.getDanio())
                        {
                            cout << "El ataque fue bloqueado con exito!" << endl;
                        }
                        else
                        {

                            float danioRecibido = lobo.getDanio() - defensaTotal;

                            monstruoJugador.Sumarvida(-danioRecibido);
                            cout << "Recibiste " << danioRecibido << " de daño." << endl;

                        }
                    }
                }
                else
                {
                    // Turno del enemigo
                    cout << "El enemigo ataca!" << endl;
                    monstruoJugador.Sumarvida(-lobo.getDanio());

                    // Cambiar turno al jugador
                    turnoJugador = true;
                }


                if(lobo.getVida()<=0)
                {
                    //cout<<"FELICIDADES GANASTE"<<endl;
                    menuTexto.setString("Eres el vencedor");
                    menuTexto.setCharacterSize(60);
                    menuTexto.setFillColor(sf::Color::Black);
                    menuTexto.setPosition(150, 170);
                    if (WinCooldown.getElapsedTime().asSeconds() >= cooldownTime)
                    {
                        window.close();
                    }
                }
                if(monstruoJugador.getVida()<=0)
                {
                    //cout<<"FELICIDADES GANASTE"<<endl;
                    menuTexto.setString("Perdiste pipi");
                    menuTexto.setCharacterSize(60);
                    menuTexto.setFillColor(sf::Color::Black);
                    menuTexto.setPosition(150, 170);
                    if (WinCooldown.getElapsedTime().asSeconds() >= cooldownTime)
                    {
                        window.close();
                    }
                }



                // Limpiar la pantalla
                window.clear();

                //dibujar las opciones de la pelea
                window.draw(menuTexto);

                // Mostrar lo dibujado
                window.display();

            }
        }
    }
}

void starthistoria()
{

    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "escenario final Juego");

    // Establecer el límite de FPS
    window.setFramerateLimit(60);

    // Crear un personaje
    Personaje rojo;

    rojo.cargarPosicion();
    piso suelo;
    suelo.setPosition(405,580);
    caverna cueva;
    cueva.setPosition(250,100);
    vallas valla;
    valla.setPosition(0,445);
    vallas valla2;
    valla2.setPosition(170,445);
    vallas valla3;
    valla3.setPosition(450,445);
    vallas valla4;
    valla4.setPosition(630,445);

    // Crear fondo
    Escenariojefe fondo1;

    // Agregar un reloj para el cooldown de colisiones
    sf::Clock collisionCooldown;
    float cooldownTime = 1;  // Cooldown de 2 segundos

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

        std::vector<Colisionable*> colisionables = { &valla,&valla2,&valla3,&valla4 };
        // Actualizar el personaje
        rojo.update();

        if (collisionCooldown.getElapsedTime().asSeconds() >= cooldownTime)
        {
            if(rojo.isCollision(suelo))
            {

                cout << "colision" << endl;
                collisionCooldown.restart();
                rojo.guardarPosicion();
                window.close();
                startGame();

            }
        }
        if (collisionCooldown.getElapsedTime().asSeconds() >= cooldownTime)
        {
            if (rojo.isCollision(cueva))
            {
                batallacueva();
                collisionCooldown.restart();
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

            /************ Los window.draw se dibujan según su orden creando capas **************/
            window.draw(fondo1);
            window.draw(suelo);
            window.draw(cueva);
            ////////////////////////
            window.draw(valla);
            window.draw(valla2);
            window.draw(valla3);
            window.draw(valla4);
            //////////////////////
            window.draw(rojo);
            window.display();
        }

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
