/*
 * TADJuego.cpp
 *
 *  Created on: 21/06/2013
 *      Author: juanlu
 */

#include "TADJuego.h"

void InicializarJuego(Juego &J, int jugadores) {

	TipoCadena msg1 = "ValorN: ";
	TipoCadena msg2 = "Turno: ";
	TipoCadena msg3;

	int n_filas, n_columnas, n_fichas, n_jugadores, comodin1, comodin2;
	J.jugadores = jugadores;
	if (TEntornoCargarConfiguracion(n_filas, n_columnas, n_fichas, n_jugadores,
			comodin1, comodin2)) {

		if (TEntornoIniciar(n_filas, n_columnas)) {
			IniciarTablero(J.t, n_filas, n_columnas);
			if (jugadores >= 2 && jugadores <= 5)
				n_jugadores = jugadores;
			J.jugadores = n_jugadores;
			J.nraya = n_fichas;
			J.turno = 1;

			TEntornoEscribirNombres(J.jugadores);
			TEntornoMostrarMensajeconNumero(Zona1, msg1, J.nraya);
			TEntornoMostrarMensaje(Zona2, msg2);
			TEntornoObtenerNombre(msg3, J.turno);
			TEntornoMostrarMensaje(Zona3, msg3);
			TEntornoActivarColumna(0);

		} else {
			cout << "Tablero no creado" << endl;
		}
	} else {
		cout << "Configuración Incorrecta" << endl;
	}

}

void animacion(Juego J, int fila, int columna) {
	int f = 0;
	bool cascada = false;
	while (f <= fila && !cascada) {

		if (f < fila) {
			TEntornoPonerCasilla(f, columna, J.turno);
			//TEntornoPausa(2);
			TEntornoEliminarCasilla(f, columna);
			f++;
		} else {
			TEntornoPonerCasilla(f, columna, J.turno);
			cascada = true;
		}
	}
}

void mensajeGanador(Juego J, TipoMensaje &msgjugador) {

	switch (J.turno) {
	case 1:
		strcpy(msgjugador, " A !!!");
		break;

	case 2:
		strcpy(msgjugador, " B !!!");
		break;
	case 3:
		strcpy(msgjugador, " C !!!");
		break;
	case 4:
		strcpy(msgjugador, " D !!!");
		break;
	case 5:
		strcpy(msgjugador, " E !!!");
		break;
	default:
		break;
	}

}

void JugarJuego(Juego &J) {

	int col = 0; //columna seleccionada
	int fila; // fila devuelta por PonerFicha del TADTablero
	int f; // variable utilizada para recorrer todas las filas para la ampliación. Inicializada justo antes del bucle.
	bool salir = false; //controla el final del bucle
	bool fuera = false;
	bool ganador = false;
	//bool cascada; // variable utilizada para salir del bucle while para la ampliacion. Se inicializa justo antes del bucle.
	TipoTecla tecla = TNada; //almacena la tecla pulsada
	TipoCadena msg3;
	TipoMensaje msgganador = "¡¡¡ HA GANADO";
	TipoMensaje msgjugador;

	while (!salir) {
		tecla = TEntornoLeerTecla();

		switch (tecla) {
		case TDerecha: //la flecha se desplaza hacia la derecha
			if (!ganador) {
				TEntornoDesactivarColumna(col);

				if (col < numeroColumnas(J.t) - 1) {
					col++;
					TEntornoActivarColumna(col);
				} else {
					col = 0;
					TEntornoActivarColumna(col);
				}
			}
			break;

		case TIzquierda: //la flecha se desplaza hacia la izquierda
			if (!ganador) {
				TEntornoDesactivarColumna(col);
				if (col > 0) {
					col--;
					TEntornoActivarColumna(col);
				} else {
					col = numeroColumnas(J.t) - 1;
					TEntornoActivarColumna(col);
				}
			}
			break;

		case TEnter: //se borran las 4 fichas que hay en el tablero
			if (!ganador && !fuera) {
				if (!PonerFicha(J.t, fila, col, J.turno)) {
					if (comprobarTablero(J.t)) {
						if (!ganador)
							TEntornoMostrarMensajeFin("¡¡¡ E M P A T E !!!");
						fuera = true;
					}
				} else {
					animacion(J, fila, col);
					if (Ganador(J.t, fila, col, J.turno, J.nraya)) {

						mensajeGanador(J, msgjugador);

						strcat(msgganador, msgjugador);
						TEntornoMostrarMensajeFin(msgganador);
						if (comprobarTablero(J.t))
							ganador = true;
					}

					J.turno++;
					if (J.turno > J.jugadores) {
						J.turno = 1;
					}
					TEntornoObtenerNombre(msg3, J.turno);
					TEntornoMostrarMensaje(Zona3, msg3);

				}
			} else {
				TEntornoMostrarMensajeFin("¡¡¡ A D I O S !!! :D");
				TEntornoPausa(10);
				salir = true;
			}
			break;

		case TSalir:
			TEntornoMostrarMensajeFin("¡¡¡ A D I O S !!! :D");
			TEntornoPausa(10);
			salir = true;
			break;
		default:
			break;
		}
	}
}

