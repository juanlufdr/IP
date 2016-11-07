/*
 * TADJuego.h
 *
 *  Created on: 21/06/2013
 *      Author: juanlu
 */

#ifndef TADJUEGO_H_
#define TADJUEGO_H_


#include "entorno.h"
#include "TADTablero.h"
#include <iostream>
#include "string.h"
using namespace std;

typedef struct Juego {
	Tablero t;
	int nraya;
	int jugadores;
	int turno;
} Juego;

void InicializarJuego(Juego &J, int jugadores);

void JugarJuego(Juego &J);

void animacion (Juego J,int fila, int columna);

void mensajeGanador (Juego J);

void eliminarNraya (Juego &J,int fila, int columna);

void caerFicha (Juego &J, int fila, int columna);

#endif /* TADJUEGO_H_ */

