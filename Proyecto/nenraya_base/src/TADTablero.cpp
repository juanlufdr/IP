/*
 * TADTablero.cpp
 *
 *  Created on: 21/06/2013
 *      Author: juanlu
 */

#include "TADTablero.h"

void IniciarTablero(Tablero &t, int fila, int columna) {
	t.filasreales = fila;
	t.columreales = columna;
	int i, j;
	for (i = 0; i < fila; i++) {
		for (j = 0; j < columna; j++) {
			t.tab[i][j] = crearCasilla();
		}
	}
}

bool comprobarTablero(Tablero t) { /// no
	bool enc = true;
	int fila = 0;
	int columna;
	while (fila < t.filasreales && enc) {
		columna = 0;
		while (columna < t.columreales && enc) {
			if (esVaciaCasilla(t.tab[fila][columna])) {
				enc = false;
				;
			} else {
				columna++;
			}
		}
		if (enc)
			fila++;
	}
	return enc;
}

int numeroFilas(Tablero t) {
	return t.filasreales;
}

int numeroColumnas(Tablero t) {
	return t.columreales;
}

bool PonerFicha(Tablero &t, int &fila, int columna, int col) {
	bool enc = false;
	fila = t.filasreales - 1;
	while (fila >= 0 && !enc) {
		if (esVaciaCasilla(t.tab[fila][columna])) {
			colorearCasilla(t.tab[fila][columna], col);
			enc = true;
		} else {
			fila--;
		}
	}
	return enc;

}

bool BorrarFicha(Tablero &t, int fila, int columna) {
	bool enc = false;
	fila = t.filasreales - 1;
	int color;
	while (fila >= 0 && !enc) {
		if (!esVaciaCasilla(t.tab[fila][columna])) {
			vaciarCasilla(t.tab[fila][columna]);
			if (!esVaciaCasilla(t.tab[fila + 1][columna])) {
				color = queColorCasilla(t.tab[fila + 1][columna]);
				PonerFicha(t, fila, columna, color);
				vaciarCasilla(t.tab[fila+1][columna]);
			}
			enc = true;
		} else {
			fila++;
		}
	}
	return enc;
}

bool comprobarHorizontal(Tablero t, int fila, int color, int nraya) {
	bool enc = false;
	int i = 0;
	int cont = 0;
	while (i < t.columreales && !enc) {
		if (queColorCasilla(t.tab[fila][i]) == color) {
			cont++;
			i++;
		} else {
			cont = 0;
			i++;
		}
		if (cont == nraya) {
			do {
				i--;
				TEntornoActivarCasilla(fila, i);
				cont--;
			} while (cont > 0);

			enc = true;
		}
	}
	return enc;

}

bool comprobarVertical(Tablero t, int fila, int columna, int color, int nraya) {
	bool enc = false;
	int i = fila;
	int cont = 0;
	while (i < t.filasreales && !enc) {
		if (queColorCasilla(t.tab[i][columna]) == color) {
			cont++;
			i++;
		} else {
			cont = 0;
			i++;
		}
		if (cont == nraya) {
			do {
				i--;
				TEntornoActivarCasilla(i, columna);
				cont--;

			} while (cont > 0);
			enc = true;
		}
	}
	return enc;
}

bool comprobarDiagonal(Tablero t, int fila, int columna, int color, int nraya) {
	bool enc = false;
	int i = fila;
	int j = columna;
	int cont = 0;
	while (i >= 0 && j >= 0) {
		i--;
		j--;
	}
	while (i < t.filasreales && j < t.columreales && !enc) {
		if (queColorCasilla(t.tab[i][j]) == color) {
			cont++;
			i++;
			j++;
		} else {
			cont = 0;
			i++;
			j++;
		}
		if (cont == nraya) {
			do {
				i--;
				j--;
				TEntornoActivarCasilla(i, j);
				cont--;
			} while (cont > 0);

			enc = true;
		}
	}
	return enc;
}

bool comprobarDiagonalInversa(Tablero t, int fila, int columna, int color,
		int nraya) {
	bool enc = false;
	int i = fila;
	int j = columna;
	int cont = 0;
	while (i >= 0 && j < t.columreales) {
		i--;
		j++;
	}
	while (i < t.filasreales && j >= 0 && !enc) {
		if (queColorCasilla(t.tab[i][j]) == color) {
			cont++;
			i++;
			j--;
		} else {
			cont = 0;
			i++;
			j--;
		}
		if (cont == nraya) {
			do {
				i--;
				j++;
				TEntornoActivarCasilla(i, j);
				cont--;
			} while (cont > 0);
			enc = true;
		}
	}
	return enc;
}

bool Ganador(Tablero t, int fila, int columna, int color, int nraya) {
	bool gana = false;
	if (comprobarHorizontal(t, fila, color, nraya)
			|| comprobarVertical(t, fila, columna, color, nraya)
			|| comprobarDiagonal(t, fila, columna, color, nraya)
			|| comprobarDiagonalInversa(t, fila, columna, color, nraya)) {

		gana = true;
	} else {
		gana = false;
	}
	return gana;
}
