#include "FuncionStartgame.h"
#include "inventory.h"
#include "Personaje.h"
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include "AnimacionAtaque.h"
#include "Juego.h"
void manejarCombate(Monstruo& enemigo, Juego& monstruoJugador, sf::Text& menuTexto, sf::RenderWindow& window) {
    srand(static_cast<unsigned>(time(0)));


     AnimacionAtaque ataque;
    ataque.setRutaPNG("Animations/zoonami_enemy_aqua_jet_animation.PNG");

    AnimacionAtaque ataque2;
    ataque.setRutaPNG("Animations/zoonami_player_vice_grip_animation.PNG");

    AnimacionDefensa Defensa;


    // Variables de pelea
    bool turnoJugador = true;  // Variable para alternar los turnos

    bool peleaActiva = true;



    //PROBANDO cosas del CARTEL DE VICTORIA
    sf::Clock WinCooldown;


    // Crear buffer para el sonido de ataque
    sf::SoundBuffer bufferAtaque;
    if (!bufferAtaque.loadFromFile("Sonidos/pew.wav"))
    {
        std::cout << "Error al cargar pew.wav" << std::endl;
    }
    sf::Sound sonidoAtaque;
    sonidoAtaque.setBuffer(bufferAtaque);
    ///////////////////////////////////
    /////////////////////////////////////////
  sf::SoundBuffer bufferDefensa;
    if (!bufferDefensa.loadFromFile("Sonidos/bueeeee.wav"))
    {
        std::cout << "Error al cargar paaraaaaa.wav" << std::endl;
    }
    sf::Sound sonidoDefensa;
    sonidoDefensa.setBuffer(bufferDefensa);
    /////////////////////////////////////
    sf::SoundBuffer bufferPelea;
    if (!bufferPelea.loadFromFile("Sonidos/omg-esto-va-a-ser-epico-papus.wav"))
    {
        std::cout << "Error al cargar omg-esto-va-a-ser-epico-papus.wav" << std::endl;
    }
    sf::Sound sonidoPelea;
    sonidoPelea.setBuffer(bufferPelea);
///////////////////////////////////////////
  sf::SoundBuffer bufferDerrota;
    if (!bufferDerrota.loadFromFile("Sonidos/estoy-cansado-jefe.wav"))
    {
        std::cout << "Error al cargar estoy-cansado-jefe.wav" << std::endl;
    }
    sf::Sound sonidoDerrota;
    sonidoDerrota.setBuffer(bufferDerrota);
    //////////////////////////////////////
      sf::SoundBuffer bufferVictoria;
    if (!bufferVictoria.loadFromFile("Sonidos/bokita.wav"))
    {
        std::cout << "Error al cargar bokita.wav" << std::endl;
    }
    sf::Sound sonidoVictoria;
    sonidoVictoria.setBuffer(bufferVictoria);
    ///////////////////////////////////
      sf::SoundBuffer bufferExp;
    if (!bufferExp.loadFromFile("Sonidos/orb.wav"))
    {
        std::cout << "Error al cargar orb.wav" << std::endl;
    }
    sf::Sound sonidoExp;
    sonidoExp.setBuffer(bufferExp);

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


    if (turnoJugador) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1) {  // Atacar
            cout << "Atacas al enemigo!" << endl;
            ataque.startAnimation();
            sonidoAtaque.play();

            if (enemigo.getDefensa() > monstruoJugador.getDanioMonstruoActual()) {
                cout << "El enemigo ha bloqueado tu ataque!" << endl;
                enemigo.setDefensa(enemigo.getDefensa() - monstruoJugador.getDanioMonstruoActual());
            } else {
                float danio = monstruoJugador.getDanioMonstruoActual() - enemigo.getDefensa();
                enemigo.setVida(enemigo.getVida() - danio);
                enemigo.setDefensa(0);
                cout << "Has hecho " << danio << " de daño. Vida del enemigo: " << enemigo.getVida() << endl;
            }

            turnoJugador = false;
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2) {  // Defender
            cout << "Te defiendes!" << endl;
            monstruoJugador.setDefensaMonstruoActual(rand() % 100 + 1);
            sonidoDefensa.play();
            Defensa.startAnimation();
            turnoJugador = false;
        }
    } else {
        // Turno del enemigo
        cout << "El enemigo ataca!" << endl;
        int probabilidadCura = rand() % 100;
        if (probabilidadCura < 20) {
            float curacion = 40.0f;
            enemigo.setVida(enemigo.getVida() + curacion);
            cout << "El enemigo se ha curado " << curacion << " puntos de vida." << endl;
        } else {
            if (monstruoJugador.getDefensaMonstruoActual() > enemigo.getDanio()) {
                cout << "El ataque fue bloqueado con éxito!" << endl;
                monstruoJugador.setDefensaMonstruoActual(monstruoJugador.getDefensaMonstruoActual() - enemigo.getDanio());
            } else {
                float danio = enemigo.getDanio() - monstruoJugador.getDefensaMonstruoActual();
                monstruoJugador.setVidaMonstruoActual(monstruoJugador.getVidaMonstruoActual() - danio);
                monstruoJugador.setDefensaMonstruoActual(0);
                cout << "El enemigo ha hecho " << danio << " de daño. Vida de tu monstruo: " << monstruoJugador.getVidaMonstruoActual() << endl;
            }
        }
        turnoJugador = true;
    }

    if (enemigo.getVida() <= 0) {
        menuTexto.setString("Eres el vencedor");
        menuTexto.setCharacterSize(60);
        menuTexto.setFillColor(sf::Color::Black);
        menuTexto.setPosition(150, 170);
        sonidoExp.play();
        sonidoVictoria.play();

        sf::Clock clock;
        while (clock.getElapsedTime().asSeconds() < 3.0f) {
            window.clear();

            window.draw(menuTexto);
            window.display();
        }
        window.close();

        int expGanada = 30;
        monstruoJugador.ganarExperienciaMonstruoActual(expGanada);
        cout << "Ganaste " << expGanada << " puntos de experiencia!" << endl;
        peleaActiva = false;
    }

    if (monstruoJugador.getVidaMonstruoActual() <= 0) {
        monstruoJugador.pasarAlSiguienteMonstruo();
    }
}
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
    //Velom monstruoJugador(100.0f, 50.0f, 30.0f,"include/velom.PNG");


    Juego monstruoJugador;

    monstruoJugador.agregarMonstruo(new Velom(150.0f, 50.0f, 30.0f, "include/velom.PNG"));
    monstruoJugador.agregarMonstruo(new Bufalont (150.0f, 50.0f, 30.0f, "include/bufalont.PNG"));
    monstruoJugador.agregarMonstruo(new Tukin(150.0f, 50.0f, 30.0f, "include/tukin.PNG"));
    monstruoJugador.agregarMonstruo(new Lechuza(150.0f, 50.0f, 30.0f, "include/FuckingLechuza.PNG"));
    monstruoJugador.agregarMonstruo(new Peluchin(150.0f, 50.0f, 30.0f, "include/pelucin.PNG"));
    monstruoJugador.agregarMonstruo(new Peluchin(150.0f, 50.0f, 30.0f, "include/balleton.PNG"));


    monstruoJugador.setPositionTodosMonstruos(50, 500);
    monstruoJugador.setScale(2,2);



    Juego monstruoEnemigo;











    AnimacionAtaque ataque;
    ataque.setRutaPNG("Animations/zoonami_enemy_aqua_jet_animation.PNG");

    AnimacionAtaque ataque2;
    ataque.setRutaPNG("Animations/zoonami_player_vice_grip_animation.PNG");

    AnimacionDefensa Defensa;


    // Variables de pelea
    bool turnoJugador = true;  // Variable para alternar los turnos

    bool peleaActiva = true;
    bool opcionSeleccionada = false;


    //PROBANDO cosas del CARTEL DE VICTORIA
    sf::Clock WinCooldown;
    float cooldownTime = 15;

    // Crear buffer para el sonido de ataque
    sf::SoundBuffer bufferAtaque;
    if (!bufferAtaque.loadFromFile("Sonidos/pew.wav"))
    {
        std::cout << "Error al cargar pew.wav" << std::endl;
    }
    sf::Sound sonidoAtaque;
    sonidoAtaque.setBuffer(bufferAtaque);
    ///////////////////////////////////
    /////////////////////////////////////////
  sf::SoundBuffer bufferDefensa;
    if (!bufferDefensa.loadFromFile("Sonidos/bueeeee.wav"))
    {
        std::cout << "Error al cargar paaraaaaa.wav" << std::endl;
    }
    sf::Sound sonidoDefensa;
    sonidoDefensa.setBuffer(bufferDefensa);
    /////////////////////////////////////
    sf::SoundBuffer bufferPelea;
    if (!bufferPelea.loadFromFile("Sonidos/omg-esto-va-a-ser-epico-papus.wav"))
    {
        std::cout << "Error al cargar omg-esto-va-a-ser-epico-papus.wav" << std::endl;
    }
    sf::Sound sonidoPelea;
    sonidoPelea.setBuffer(bufferPelea);
///////////////////////////////////////////
  sf::SoundBuffer bufferDerrota;
    if (!bufferDerrota.loadFromFile("Sonidos/estoy-cansado-jefe.wav"))
    {
        std::cout << "Error al cargar estoy-cansado-jefe.wav" << std::endl;
    }
    sf::Sound sonidoDerrota;
    sonidoDerrota.setBuffer(bufferDerrota);
    //////////////////////////////////////
      sf::SoundBuffer bufferVictoria;
    if (!bufferVictoria.loadFromFile("Sonidos/bokita.wav"))
    {
        std::cout << "Error al cargar bokita.wav" << std::endl;
    }
    sf::Sound sonidoVictoria;
    sonidoVictoria.setBuffer(bufferVictoria);
    ///////////////////////////////////
      sf::SoundBuffer bufferExp;
    if (!bufferExp.loadFromFile("Sonidos/orb.wav"))
    {
        std::cout << "Error al cargar orb.wav" << std::endl;
    }
    sf::Sound sonidoExp;
    sonidoExp.setBuffer(bufferExp);

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


    //cartel opciones pelea
    // Submenú para que el jugador elija la acción: atacar, defender, capturar (si es posible)
    cout << "Elige una acción: 1) Atacar 2) Defender"<<endl;


    cout<<"la vida de tu pokemon es: "<<monstruoJugador.getVidaMonstruoActual()<<endl;
    cout<<"el daño de tu pokemon es: "<<monstruoJugador.getDanioMonstruoActual()<<endl;
    cout<<"La defensa de tu pokemon es: "<<monstruoJugador.getDefensaMonstruoActual()<<endl;




    // Seleccionar un monstruo aleatorio con probabilidades distintas
    int probabilidad = std::rand() % 100;  // Generar un número entre 0 y 99 (100 posibles valores)


    // Asignar monstruo según probabilidad
    if (probabilidad < 0)    // 20% de probabilidad para Hornerot
    {


        cout<<"entro al if"<<endl;
    }




    else if (probabilidad < 15 && probabilidad>0) {  // 15% de probabilidad para Pelucin (20 + 15 = 35)

        monstruoEnemigo.agregarMonstruo(new Tukin(150.0f, 50.0f, 30.0f, "include/tukin.PNG"));

        sonidoPelea.play();

        cout<<"la vida del enemigo es: " << monstruoEnemigo.getVidaMonstruoActual()<<endl;
        cout<<"el daño del enemigo es: " << monstruoEnemigo.getDanioMonstruoActual()<<endl;
        cout<<"La defensa del enemigo es: " << monstruoEnemigo.getDefensaMonstruoActual()<<endl;
    }


    else if (probabilidad < 40 && probabilidad >15) {  // 25% de probabilidad para Tukin (35 + 25 = 60)
    monstruoEnemigo.agregarMonstruo(new Velom(150.0f, 50.0f, 30.0f, "include/velom.PNG"));

        sonidoPelea.play();

        cout<<"la vida del enemigo es: " << monstruoEnemigo.getVidaMonstruoActual()<<endl;
        cout<<"el daño del enemigo es: " << monstruoEnemigo.getDanioMonstruoActual()<<endl;
        cout<<"La defensa del enemigo es: " << monstruoEnemigo.getDefensaMonstruoActual()<<endl;
    }


    else if (probabilidad < 50 && probabilidad > 40)    // 10% de probabilidad para Velom (60 + 10 = 70)
    {
         monstruoEnemigo.agregarMonstruo(new Bufalont (150.0f, 50.0f, 30.0f, "include/bufalont.PNG"));

        sonidoPelea.play();

        cout<<"la vida del enemigo es: " << monstruoEnemigo.getVidaMonstruoActual()<<endl;
        cout<<"el daño del enemigo es: " << monstruoEnemigo.getDanioMonstruoActual()<<endl;
        cout<<"La defensa del enemigo es: " << monstruoEnemigo.getDefensaMonstruoActual()<<endl;
    }


    else if (probabilidad <65 && probabilidad> 50) {  // 10% de probabilidad para Lechuza (70 + 10 = 80)
    monstruoEnemigo.agregarMonstruo(new Peluchin(150.0f, 50.0f, 30.0f, "include/pelucin.PNG"));

        sonidoPelea.play();

        cout<<"la vida del enemigo es: " << monstruoEnemigo.getVidaMonstruoActual()<<endl;
        cout<<"el daño del enemigo es: " << monstruoEnemigo.getDanioMonstruoActual()<<endl;
        cout<<"La defensa del enemigo es: " << monstruoEnemigo.getDefensaMonstruoActual()<<endl;
    }


    else if (probabilidad < 75 && probabilidad> 65) {  // 10% de probabilidad para Balleton (80 + 10 = 90)
    monstruoEnemigo.agregarMonstruo(new Lechuza(150.0f, 50.0f, 30.0f, "include/FuckingLechuza.PNG"));

        sonidoPelea.play();

        cout<<"la vida del enemigo es: " << monstruoEnemigo.getVidaMonstruoActual()<<endl;
        cout<<"el daño del enemigo es: " << monstruoEnemigo.getDanioMonstruoActual()<<endl;
        cout<<"La defensa del enemigo es: " << monstruoEnemigo.getDefensaMonstruoActual()<<endl;
    }


    else {  // 10% de probabilidad para Bufalont (90 a 99)
    monstruoEnemigo.agregarMonstruo(new Peluchin(150.0f, 50.0f, 30.0f, "include/balleton.PNG"));

        sonidoPelea.play();

        cout<<"la vida del enemigo es: " << monstruoEnemigo.getVidaMonstruoActual()<<endl;
        cout<<"el daño del enemigo es: " << monstruoEnemigo.getDanioMonstruoActual()<<endl;
        cout<<"La defensa del enemigo es: " << monstruoEnemigo.getDefensaMonstruoActual()<<endl;
    }
    monstruoEnemigo.setScale(2,2);
    monstruoEnemigo.setPosition(570, 160);




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

                    ataque2.startAnimation();
                    sonidoAtaque.play(); // Reproducir sonido de ataque


                    b_ataqueJugador=true;
                    sonidoAtaque.play();






                    if (monstruoEnemigo.getDefensaMonstruoActual() > monstruoJugador.getDanioMonstruoActual())
                    {
                        cout << "El enemigo ah bloqueado tu ataque!" << endl;
                        monstruoEnemigo.setDefensaMonstruoActual(monstruoEnemigo.getDefensaMonstruoActual()-monstruoJugador.getDanioMonstruoActual());
                    }
                    else if(monstruoJugador.getDefensaMonstruoActual()<=monstruoEnemigo.getDanioMonstruoActual())
                    {

                        cout << "Tu Monstruo ah hecho " << monstruoJugador.getDanioMonstruoActual()<<" de daño" << endl;

                        monstruoEnemigo.setVidaMonstruoActual(monstruoEnemigo.getVidaMonstruoActual()+monstruoEnemigo.getDefensaMonstruoActual()-monstruoJugador.getDanioMonstruoActual());

                        cout << "La vida del enemigo es: "<< monstruoEnemigo.getVidaMonstruoActual() << endl;

                        monstruoEnemigo.setDefensaMonstruoActual(0);

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

            }//llave turno jugador
           else {
        // Turno del enemigo
       cout << "El enemigo ataca!" << endl;

    // Probabilidad de curación para el enemigo
    int probabilidadCura = rand() % 100;
    if (probabilidadCura < 20) {  // 20% de probabilidad de curación
        float curacion = 30.0f;
        monstruoEnemigo.setVidaMonstruoActual(monstruoJugador.getVidaMonstruoActual() + curacion);  // 'vel' representa al monstruo enemigo
        cout << "El enemigo se ha curado " << curacion << " puntos de vida." << endl;

        // Cambiar turno al jugador después de curarse
        turnoJugador = true;
    } else {
        // Lógica de ataque del enemigo
        if (monstruoJugador.getDefensaMonstruoActual() > monstruoEnemigo.getDefensaMonstruoActual()) {
            cout << "El ataque fue bloqueado con éxito!" << endl;
            monstruoJugador.setDefensaMonstruoActual(monstruoJugador.getDefensaMonstruoActual() - monstruoEnemigo.getDanioMonstruoActual());
                    ataque.startAnimation();

            // Cambiar turno al jugador
            turnoJugador = true;
        } else if (monstruoJugador.getDefensaMonstruoActual() <= monstruoEnemigo.getDanioMonstruoActual()) {
            cout << "El enemigo ha hecho: " << monstruoEnemigo.getDanioMonstruoActual() << endl;

            monstruoJugador.setVidaMonstruoActual(monstruoJugador.getVidaMonstruoActual() + monstruoJugador.getDefensaMonstruoActual() - monstruoEnemigo.getDanioMonstruoActual());
            cout << "La vida de tu monstruo es: " << monstruoJugador.getVidaMonstruoActual() << endl;

            monstruoJugador.setDefensaMonstruoActual(0);

            // Cambiar turno al jugador
            turnoJugador = true;
        }
        cout << "Defensa de mi monstruo = " << monstruoJugador.getDefensaMonstruoActual() << endl;
    }
}
   if(monstruoEnemigo.getVidaMonstruoActual()<=0)
            {
                 // Cambiar el mensaje a "Eres el vencedor"
             menuTexto.setString("Eres el vencedor");
             menuTexto.setCharacterSize(60);
              menuTexto.setFillColor(sf::Color::Black);
              menuTexto.setPosition(150, 170);
              sonidoExp.play();
              sonidoVictoria.play();


    // Mantener ventana abierta unos segundos más
    sf::Clock clock;
        while (clock.getElapsedTime().asSeconds() < 3.0f) {  // Mostrar el mensaje por 3 segundos
        window.clear();
        window.draw(fondo);
        window.draw(menuTexto);
        window.display();
        sonidoVictoria.play();


    }

    // Cerrar la ventana después de mostrar el mensaje
    window.close();

                // *Distribución de experiencia al ganar*
                int expGanada = 30; // Ajusta este valor a tu preferencia
                monstruoJugador.ganarExperienciaMonstruoActual(expGanada); // Agregar exp al monstruo del jugador
                cout << "Ganaste " << expGanada << " puntos de experiencia!" << endl;

                peleaActiva = false;
            }
        if(monstruoJugador.getVidaMonstruoActual()<=0)
        {
            monstruoJugador.pasarAlSiguienteMonstruo();}




        }//llave del while



        ataque.update();
        ataque2.update();
        Defensa.update();


        // Limpiar la pantalla
        window.clear();








        // Mostrar lo dibujado

        // Dibujar el fondo

        window.draw(fondo);



        //dibujar monstruo jugador
        //window.draw(monstruoJugador);
        // Dibujar opciones de pelea siempre en pantalla
        window.draw(menuTexto);
        monstruoJugador.dibujar(window);
        monstruoEnemigo.dibujar(window);




        window.draw(ataque);
        window.draw(ataque2);
        window.draw(Defensa);

        //dibujar las opciones de la pelea

        //juego.dibujar(window);
        window.display();



    }
}
