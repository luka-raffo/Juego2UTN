#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class Item
{
   private:

       string nombre;

    public:
    Item(const string& nombre);

    string getNombre();


};

#endif // ITEM_H
