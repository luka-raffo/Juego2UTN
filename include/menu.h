#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
// Clase para manejar el men�
class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    void HandleMouseInput(sf::Vector2i mousePos);  // Nueva funci�n para manejar la entrada del rat�n

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[3];
};

#endif // MENU_H
