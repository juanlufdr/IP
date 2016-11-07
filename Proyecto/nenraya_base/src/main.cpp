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

	InicializarJuego(J, 2);

	JugarJuego(J);

	return 0;
}

/*void pruebaCrearCasilla() {
 casilla c;
 crearCasilla();
 if (esVaciaCasilla(c)) {
 cout << "CrearCasilla funciona" << endl;
 } else {
 cout << "CrearCasilla no funciona" << endl;
 }
 }

 void pruebaColorearCasilla(int n) {
 casilla c;
 colorearCasilla(c, n);
 if (queColorCasilla(c) == n) {
 if (!esVaciaCasilla(c)) {
 vaciarCasilla(c);
 cout << "ColorearCasilla funciona" << endl;
 }
 } else {
 cout << "ColorearCasilla No funciona" << endl;
 }
 }

 //Pruebas TADTablero

 void pruebaIniciarTablero() {
 Tablero t;
 int i = 0;
 int j = 0;
 int fila = MAXF;
 int columna = MAXC;
 bool enc = false;
 IniciarTablero(t, fila, columna);
 while (i < t.filasreales && !enc) {
 while (j < t.columreales && !enc) {
 if (!esVaciaCasilla(t.tab[i][j])) {
 enc = true;
 } else {
 j++;
 }
 }
 i++;
 }
 if (!enc)
 cout << "IniciarTablero funciona" << endl;
 else
 cout << "IniciarTablero no funciona" << endl;
 }

 void pruebaComprobarTablero() {
 Tablero t;
 int fila = MAXF;
 int columna = MAXC;
 IniciarTablero(t, fila, columna);
 if (!comprobarTablero(t)) {
 cout << "ComprobarTablero funciona" << endl;
 } else {
 cout << "ComprobarTablero no funciona" << endl;
 }

 }

 void comprobarNumeroFilas() {
 Tablero t;
 int fila = MAXF;
 int columna = MAXC;
 IniciarTablero(t, fila, columna);
 if (numeroFilas(t) == t.filasreales && numeroColumnas(t) == t.columreales) {
 cout << "NumeroFilas y NumeroColumnas funciona" << endl;
 } else {
 cout << "NumeroFilas y NumeroColumnas no funciona" << endl;
 }
 }

 void pruebaPonerFicha(int n) {
 Tablero t;
 int fila = MAXF;
 int columna = MAXC;
 IniciarTablero(t, fila, columna);
 PonerFicha(t, fila, columna, n);
 if (queColorCasilla(t.tab[fila][columna]) == n) {
 cout << "PonerFicha funciona" << endl;
 } else {
 cout << "PonerFicha no funciona" << endl;
 }

 }

 int main() {

 pruebaCrearCasilla();

 pruebaColorearCasilla(3);

 pruebaIniciarTablero();

 pruebaComprobarTablero();

 comprobarNumeroFilas();

 pruebaPonerFicha(3);



 }*/

