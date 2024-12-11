#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Personaje.h>
#include <iostream>
#include "escenario1.h"
#include "Monstruo.h"
#include "Escenario2.h"
#include "escenario3.h"
#include "Juego.h"
#include "FuncionStartgame.h"
#include "PedirNombre.h"



using namespace std;
void startGame(sf::Clock clock);
//void escenarioPelea();
void starthistoria(sf::Clock clock);
void BatallaCueva(sf::Clock clock);
void llegadaisla(sf::Clock clock);
bool FuncionPos();
float getRandomStat(float min, float max);

#endif // FUNCIONES_H_INCLUDED


