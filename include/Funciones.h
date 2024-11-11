#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Personaje.h>
#include <iostream>
#include "menu.h"
#include <ctime>
#include <fstream>  // Para leer y escribir archivos
#include <stdlib.h>
#include "escenario1.h"
#include "Monstruo.h"
#include "Escenario2.h"
#include "escenario3.h"
#include "Juego.h"


using namespace std;
void startGame();
void escenarioPelea();
void starthistoria();
void BatallaCueva();
void llegadaisla();
bool FuncionPos();

#endif // FUNCIONES_H_INCLUDED
