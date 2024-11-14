#include "menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Menu::Menu(float width, float height) {
    if (!font.loadFromFile("include/Pokemon.ttf")) {
        // Manejo de error
        std::cerr << "Error al cargar la fuente!" << std::endl;
    }

    // Configurando las opciones del menú
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Nuevo Juego");
    menu[0].setCharacterSize(130);
    menu[0].setPosition(100,300);


    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Ranking");
    menu[1].setCharacterSize(130);
    menu[1].setPosition(100,500);


    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Salir");
    menu[2].setCharacterSize(130);
    menu[2].setPosition(120,700);

    selectedItemIndex = 0;
}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow &window) {
    for (int i = 0; i < 3; i++) {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp() {
    if (selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown() {
    if (selectedItemIndex + 1 < 3) {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

// Función para manejar la entrada del ratón
void Menu::HandleMouseInput(sf::Vector2i mousePos) {
    for (int i = 0; i < 3; i++) {
        sf::FloatRect textBounds = menu[i].getGlobalBounds();
        if (textBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
            menu[selectedItemIndex].setFillColor(sf::Color::White);  // Desmarcar la opción anterior
            selectedItemIndex = i;
            menu[selectedItemIndex].setFillColor(sf::Color::Red);    // Marcar la nueva opción seleccionada
        }
    }
}

