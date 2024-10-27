#include "Funciones.h"
#include "inventory.h"
#include "Personaje.h"

using namespace std;
void escenarioPelea()
{
    // Crear una ventana
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
    Velom vel(100.0f, 50.0f, 30.0f,"include/velom.PNG");
    //Lechuza lechu;
    //Balleton ballena;
    //Bufalont bufalo;


    // Variables de pelea
    bool turnoJugador = true;  // Variable para alternar los turnos
    bool capturable = false;   // Indica si el monstruo puede ser capturado
    bool peleaActiva = true;
    bool opcionSeleccionada = false;
    ;





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



        // Limpiar la pantalla
        window.clear();

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


        // Lógica de pelea por turnos
        if (turnoJugador)
        {



            //opciones de pelea
            if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::Num1)    // Atacar
            {


                cout << "Atacas al enemigo!" << endl;
                vel.setVida(vel.getVida()-monstruoJugador.getDanio());
                cout << "Tu Monstruo ah hecho " << monstruoJugador.getDanio()<<" de daño" << endl;

                cout << "La videdel enemigo! es " << vel.getVida() << endl;

                turnoJugador=false;

            }

            else if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::Num2)      // Defender
            {
                cout << "Te defiendes!" << endl;
                defensaTotal = monstruoJugador.getDefensa();
                turnoJugador=false;

                if (defensaTotal > vel.getDanio())
                {
                    cout << "El ataque fue bloqueado!" << endl;
                }
                else
                {

                    float danioRecibido = vel.getDanio() - defensaTotal;

                    monstruoJugador.Sumarvida(-danioRecibido);
                    cout << "Recibiste " << danioRecibido << " de daño." << endl;

                }
            }

            else if (event.type == sf::Event::KeyPressed && event.key.code ==  sf::Keyboard::Num3 && capturable)    // Capturar
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
            }


        }
        else
        {
            // Turno del enemigo
            cout << "El enemigo ataca!" << endl;
            monstruoJugador.Sumarvida(-vel.getDanio());

            // Cambiar turno al jugador
            turnoJugador = true;
        }

        // Verificar si el enemigo es capturable
        if (vel.getVida() <= vel.getVida() * 0.25)
        {
            capturable = true;
        }









        //dibujar las opciones de la pelea
        window.draw(menuTexto);

        // Mostrar lo dibujado
        window.display();

        }
    }
}



