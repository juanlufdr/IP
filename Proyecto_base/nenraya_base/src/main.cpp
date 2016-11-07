/**

 INTRODUCCIÓN A LA PROGRAMACIÓN / FUNDAMENTOS DE PROGRAMACIÓN
 Curso 2012/2013

 Nombre: main.cpp
 Descripción: Implementación del programa principal para el proyecto NenRaya_base
 Encargado del funcionamiento del juego.
 Autor:	Profesores de las asignaturas
 Fecha:5/12/2012

 */
#include "entorno.h"
#include "TADCasilla.h"
#include "TADTablero.h"
#include "TADJuego.h"
#include <iostream>

using namespace std;

int main() {

	Juego J;

	InicializarJuego(J);

	JugarJuego(J);

	return 0;
}

//void pruebaCrearCasilla() {
//	casilla c;
//	c = crearCasilla();
//	if (esVaciaCasilla(c)) {
//		cout << "CrearCasilla funciona" << endl;
//	} else {
//		cout << "CrearCasilla NO funciona" << endl;
//	}
//}
//
//void pruebaColorearCasilla(int n) {
//	casilla c;
//	colorearCasilla(c, n);
//	if (queColorCasilla(c) == n) {
//		if (!esVaciaCasilla(c)) {
//			vaciarCasilla(c);
//			cout << "ColorearCasilla funciona" << endl;
//		}
//	} else {
//		cout << "ColorearCasilla NO funciona" << endl;
//	}
//}
//
////Pruebas TADTablero
//
//void pruebaIniciarTablero() {
//	Tablero t;
//	int i = 0;
//	int j = 0;
//	int fila = MAXF;
//	int columna = MAXC;
//	bool enc = false;
//	IniciarTablero(t, fila, columna);
//	while (i < t.filasreales && !enc) {
//		while (j < t.columreales && !enc) {
//			if (!esVaciaCasilla(t.tab[i][j])) {
//				enc = true;
//			} else {
//				j++;
//			}
//		}
//		i++;
//	}
//	if (!enc)
//		cout << "IniciarTablero funciona" << endl;
//	else
//		cout << "IniciarTablero NO funciona" << endl;
//}
//
//void pruebaComprobarTablero() {
//	Tablero t;
//	int fila = MAXF;
//	int columna = MAXC;
//	IniciarTablero(t, fila, columna);
//	if (!comprobarTablero(t)) {
//		cout << "ComprobarTablero funciona" << endl;
//	} else {
//		cout << "ComprobarTablero NO funciona" << endl;
//	}
//
//}
//
//void comprobarNumeroFilas() {
//	Tablero t;
//	int fila = MAXF;
//	int columna = MAXC;
//	IniciarTablero(t, fila, columna);
//	if (numeroFilas(t) == t.filasreales && numeroColumnas(t) == t.columreales) {
//		cout << "NumeroFilas y NumeroColumnas funciona" << endl;
//	} else {
//		cout << "NumeroFilas y NumeroColumnas NO funciona" << endl;
//	}
//}
//
//void pruebaPonerFicha(int n) {
//	Tablero t;
//	int fila = MAXF;
//	int columna = MAXC;
//	IniciarTablero(t, fila, columna);
//	PonerFicha(t, fila, columna, n);
//	if (queColorCasilla(t.tab[fila][columna]) == n) {
//		cout << "PonerFicha funciona" << endl;
//	} else {
//		cout << "PonerFicha NO funciona" << endl;
//	}
//
//}
//
//void pruebaGanador() {
//	Tablero t;
//	int i = numeroFilas(t) - 1;
//	int j = 0;
//	IniciarTablero(t, MAXF, MAXC);
//	while (i > 4) {
//		j = 0;
//		while (j < 4) {
//			PonerFicha(t, i, j, 1);
//			j++;
//		}
//		i--;
//	}
//	if (Ganador(t, t.filasreales - 1, 0, 1, 4)
//			&& Ganador(t, t.filasreales - 1, 3, 1, 4)) {
//		cout << "Ganador funciona" << endl;
//	} else {
//		cout << "Ganador NO funciona" << endl;
//	}
//
//}
//
//// Pruebas TAD Juego
//
//void pruebaIniciarJuego() {
//	Juego J;
//	int filas, columnas, fichas, jugadores, comodin1, comodin2;
//	if (TEntornoCargarConfiguracion(filas, columnas, fichas, jugadores,
//			comodin1, comodin2)) {
//		J.t.filasreales = filas;
//		J.t.columreales = columnas;
//		J.nraya = fichas;
//		J.jugadores = jugadores;
//		if (J.t.filasreales == 9 && J.t.columreales == 8 && J.nraya == 4
//				&& J.jugadores == 2 && comodin1 == 0 && comodin2 == 0) {
//			cout << "Iniciar Juego Funciona" << endl;
//		}
//	} else {
//		cout << "Iniciar juego NO funciona" << endl;
//	}
//}
//
//void pruebaJuego() {
//	Juego J;
//	IniciarTablero(J.t, MAXF, MAXC);
//
//	int i = numeroFilas(J.t) - 1;
//	int j = 0;
//	while (i > 4) {
//		j = 0;
//		while (j < 4) {
//			PonerFicha(J.t, i, j, 1);
//			j++;
//		}
//		i--;
//	}
//
//	if (Ganador(J.t, 8, 3, 1, 4)) {
//		cout << "Jugar Juego Funciona" << endl;
//	} else {
//		cout << "JugarJuego NO funciona" << endl;
//	}
//
//}
//
//int main() {
//
//	cout << "------------ Pruebas TADCasilla ------------------" << endl;
//
//	pruebaCrearCasilla();
//
//	pruebaColorearCasilla(3);
//
//	cout << "------------ Pruebas TADTablero ------------------" << endl;
//
//	pruebaIniciarTablero();
//
//	pruebaComprobarTablero();
//
//	comprobarNumeroFilas();
//
//	//pruebaPonerFicha(3);
//
//	cout << "------------ Pruebas TADJuego ------------------" << endl;
//
//	pruebaGanador();
//
//	pruebaIniciarJuego();
//
//	pruebaJuego();
//
//}

