#ifndef INVENTORY_H
#define INVENTORY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <Monstruo.h>

using namespace std;


class inventory
{
    private:
    vector<Velom> veloms;
    int maxSize=100;

public:

    inventory(int size): maxSize(size){}
    bool agregarItem( Velom& velom);
    bool eliminarItem(const Velom& velom);
    void mostrarInventario() const;



};

#endif // INVENTORY_H
