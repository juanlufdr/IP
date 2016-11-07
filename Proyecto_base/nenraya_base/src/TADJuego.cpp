/*
 * TADJuego.cpp
 *
 *  Created on: 21/06/2013
 *      Author: juanlu
 */

#include "TADJuego.h"

void InicializarJuego(Juego &J) {

	TipoCadena msg1 = "ValorN: ";
	TipoCadena msg2 = "Turno: ";
	TipoCadena msg3;

	int n_filas, n_columnas, n_fichas, n_jugadores, comodin1, comodin2;
	if (TEntornoCargarConfiguracion(n_filas, n_columnas, n_fichas, n_jugadores,
			comodin1, comodin2)) {

		if (TEntornoIniciar(n_filas, n_columnas)) {
			IniciarTablero(J.t, n_filas, n_columnas);
			J.jugadores = 2;
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

void JugarJuego(Juego &J) {

	int col = 0; //columna seleccionada
	int fila; // fila devuelta por PonerFicha del TADTablero
	//int f; // variable utilizada para recorrer todas las filas para la ampliación. Inicializada justo antes del bucle.
	bool salir = false; //controla el final del bucle
	bool fuera = false;
	bool ganador = false;
	//bool cascada; // variable utilizada para salir del bucle while para la ampliacion. Se inicializa justo antes del bucle.
	TipoTecla tecla = TNada; //almacena la tecla pulsada
	TipoCadena msg3;
	TipoMensaje msgganador = "¡¡¡ HA GANADO";
	TipoMensaje msgjugador = " EL JUGADOR";

	while (!salir) {
		tecla = TEntornoLeerTecla();

		switch (tecla) {
		case TDerecha: //la flecha se desplaza hacia la derecha
			TEntornoDesactivarColumna(col);
			if (col < numeroColumnas(J.t) - 1)
				col++;
			TEntornoActivarColumna(col);

			break;

		case TIzquierda:
			//la flecha se desplaza hacia la izquierda

			TEntornoDesactivarColumna(col);
			if (col > 0)
				col--;
			TEntornoActivarColumna(col);

			break;

		case TEnter:
			//se borran las 4 fichas que hay en el tablero
			if (!ganador && !fuera) {
				if (!PonerFicha(J.t, fila, col, J.turno)) {
					if (comprobarTablero(J.t)) {
						if (!ganador)
							TEntornoMostrarMensajeFin("¡¡¡ E M P A T E !!!");
						fuera = true;
					}
				} else {
					TEntornoPonerCasilla(fila, col, J.turno);

					if (Ganador(J.t, fila, col, J.turno, J.nraya)) {
						if (J.turno == 1)
							strcat(msgjugador, " A !!!");
						else
							strcat(msgjugador, " B !!!");

						strcat(msgganador, msgjugador);
						TEntornoMostrarMensajeFin(msgganador);
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

