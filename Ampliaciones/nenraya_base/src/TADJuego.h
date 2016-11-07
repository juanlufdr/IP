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
#include "TADCasilla.h"
#include <iostream>
#include "string.h"
using namespace std;

typedef struct Juego {
	Tablero t;
	int nraya;
	int jugadores;
	int turno;
} Juego;

/**
PRE:
POST: Inicia el entorno grafico para jugar, así como la matriz del tablero, ambos necesarios para poder jugar
Complejidad:
*/

void InicializarJuego(Juego &J);

/**
PRE: Juego iniciado correctamente
POST: Lleva a cabo la gestion del juego, actualizando el entorno grafico y la matriz despues de cada movimiento.
Complejidad:
*/

void JugarJuego(Juego &J);

#endif /* TADJUEGO_H_ */

