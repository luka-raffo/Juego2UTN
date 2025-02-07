#include "NombreJugador.h"

NombreJugador::NombreJugador()
{
    nombreJugador=IngresarNombre();
}

NombreJugador::~NombreJugador()
{
    //dtor
}

std::string NombreJugador::IngresarNombre() {
    sf::RenderWindow windowNombre(sf::VideoMode(800, 600), "Ingrese Nombre");
    bool usar=false;
    sf::Font font;
    if (!font.loadFromFile("include/Pokemon.ttf")) {
        std::cerr << "Error cargando la fuente\n";
        return "";
    }

    // Llama a la función pedirNombre pasando tanto la ventana como la fuente
    std::string nombreJugador = pedirNombre(windowNombre, font,usar);

    windowNombre.close();

    std::cout << "Bienvenido, " << nombreJugador << "!" << std::endl;
    return nombreJugador;
}
