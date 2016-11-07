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
using namespace std;

const int MAXF = 9;
const int MAXC = 8;

typedef casilla TTablero[MAXF][MAXC];

typedef struct Tablero {
	TTablero tab;
	int filasreales;
	int columreales;
} Tablero;


/**
PRE:
POST: Inicia una matriz de tipo casilla de dimensiones fila*columna
Complejidad:
*/

void IniciarTablero(Tablero &t, int fila, int columna);

/**
PRE: Tablero iniciado correctamente
POST: Devuelve TRUE si el tablero esta lleno, FALSE si el tablero no está lleno
Complejidad:
*/

bool comprobarTablero(Tablero t);

/**
PRE:Tablero iniciado correctamente
POST: Devuelve el número de filas de las que está compuesta la matriz del tablero
Complejidad:
*/

int numeroFilas(Tablero t);


/**
PRE:Tablero iniciado correctamente
POST: Devuelve el número de columnas por el que está formado la matriz del tablero
Complejidad:
*/

int numeroColumnas(Tablero t);


/**
PRE: Tablero iniciado correctamente
POST: Coloca una casilla en la posición [fila][columna] de la matriz del tablero del color pasado por parámetro
Complejidad:
*/

bool PonerFicha(Tablero &t, int &fila, int columna, int col);


/**
PRE: Tablero iniciado correctamente y no vacío
POST: Devuelve TRUE si existe una línea horizontal del tamaño nraya en la fila y del color pasados por parámetros. FALSE en caso de no existir.
Complejidad:
*/

bool comprobarHorizontal(Tablero t, int fila, int color, int nraya);

/**
PRE: Tablero iniciado correctamente y no vacío
POST:  Devuelve TRUE si existe una línea verticas del tamaño nraya en la columna y del color pasados por parámetros. FALSE en caso de no existir.
Complejidad:
*/

bool comprobarVertical(Tablero t, int columna, int color, int nraya);

/**
PRE: Tablero iniciado correctamente y no vacío.
POST: Devuelve TRUE si existe una línea diagonal del tamaño nraya donde las columnas y las filas aumentan o decrementan al mismo tiempo. FALSE en caso de no existir
Complejidad:
*/

bool comprobarDiagonal(Tablero t, int fila, int columna, int color, int nraya);

/**
PRE: Tablero iniciado correctamente y no vacío.
POST: Devuelve TRUE si existe una línea diagonal del tamaño nraya donde filas y columnas aumentan o decrementan inversamente. FALSE en caso contrario.
Complejidad:
*/

bool comprobarDiagonalInversa(Tablero t, int fila, int columna, int color,
		int nraya);

/**
PRE: Tablero iniciado correctamente y no vacío.
POST: Devuelve TRUE si existe una línea horizontal, vertical o diagonal en el tablero. FALSE en caso contrario.
Complejidad:
*/

bool Ganador(Tablero t, int fila, int columna, int color, int nraya);

#endif /* TADTABLERO_H_ */
