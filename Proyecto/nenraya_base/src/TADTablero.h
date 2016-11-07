/*
 * TADTablero.h
 *
 *  Created on: 21/06/2013
 *      Author: juanlu
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_
#include <iostream>
#include "TADCasilla.h"
#include "entorno.h"
using namespace std;

const int MAXF = 9;
const int MAXC = 8;

typedef casilla TTablero[MAXF][MAXC];

typedef struct Tablero {
	TTablero tab;
	int filasreales;
	int columreales;
} Tablero;

void IniciarTablero(Tablero &t, int fila, int columna);

bool comprobarTablero(Tablero t);

int numeroFilas(Tablero t);

int numeroColumnas(Tablero t);

bool PonerFicha(Tablero &t, int &fila, int columna, int col);

bool BorrarFicha (Tablero &t, int fila, int columna);

bool comprobarHorizontal(Tablero t, int fila, int color, int nraya);

bool comprobarVertical(Tablero t, int columna, int color, int nraya);

bool comprobarDiagonal(Tablero t, int fila, int columna, int color, int nraya);

bool comprobarDiagonalInversa(Tablero t, int fila, int columna, int color,
		int nraya);

bool Ganador(Tablero t, int fila, int columna, int color, int nraya);

#endif /* TADTABLERO_H_ */
