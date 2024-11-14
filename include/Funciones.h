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
#include "FuncionStartgame.h"
#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include <ctime>


using namespace std;
void startGame();
//void escenarioPelea();
void starthistoria();
void BatallaCueva();
void llegadaisla();
bool FuncionPos();
std::string IngresarNombre();
void iniciarTemporizador(time_t &inicio);
double detenerTemporizador(time_t inicio);
void guardarResultado(const std::string& nombre, double tiempo);
#endif // FUNCIONES_H

#endif // FUNCIONES_H_INCLUDED
