/*
 * main.cpp
 *
 *  Created on: 20/09/2026
 *      Author: Julio César Hdez.
 */

#include <iostream>
#include <string>
#include <vector>
#include "jugador.h"
#include "sorts.h"

using namespace std;

void mostrarJugadores(const vector<Jugador> &jugadores) {

	cout << endl;
	cout << "Nombre | Equipo | Pos | Edad | Altura | Puntos | Rebotes | Asistencias" << endl;

	for (int i = 0; i < jugadores.size(); i++) {

		cout << jugadores[i].getNombre() << " | "
			 << jugadores[i].getEquipo() << " | "
			 << jugadores[i].getPosicion() << " | "
			 << jugadores[i].getEdad() << " | "
			 << jugadores[i].getAltura() << " | "
			 << jugadores[i].getPuntos() << " | "
			 << jugadores[i].getRebotes() << " | "
			 << jugadores[i].getAsistencias() << endl;
	}
}

void mostrarMenuOrdenamiento() {

	cout << endl;
	cout << "Ordenar jugadores por:" << endl;
	cout << "1. Nombre" << endl;
	cout << "2. Equipo" << endl;
	cout << "3. Posicion" << endl;
	cout << "4. Edad" << endl;
	cout << "5. Altura" << endl;
	cout << "6. Puntos" << endl;
	cout << "7. Rebotes" << endl;
	cout << "8. Asistencias" << endl;
}

int main() {

	vector<Jugador> jugadores(10);

	jugadores[0] = Jugador("LeBron James", "Lakers", "F",
						   41, 206, 25.0, 7.0, 8.0);

	jugadores[1] = Jugador("Stephen Curry", "Warriors", "G",
						   38, 188, 24.5, 4.5, 6.2);

	jugadores[2] = Jugador("Nikola Jokic", "Nuggets", "C",
						   31, 211, 27.1, 12.4, 9.0);

	jugadores[3] = Jugador("Luka Doncic", "Lakers", "G",
						   27, 201, 28.4, 8.7, 8.2);

	jugadores[4] = Jugador("Giannis Antetokounmpo", "Bucks", "F",
						   31, 211, 30.2, 11.8, 6.5);

	jugadores[5] = Jugador("Jayson Tatum", "Celtics", "F",
						   28, 203, 27.0, 8.8, 5.9);

	jugadores[6] = Jugador("Kevin Durant", "Rockets", "F",
						   37, 208, 26.8, 6.9, 4.8);

	jugadores[7] = Jugador("Anthony Edwards", "Timberwolves", "G",
						   25, 193, 27.6, 5.2, 4.5);

	jugadores[8] = Jugador("Joel Embiid", "76ers", "C",
						   32, 213, 28.7, 11.1, 4.2);

	jugadores[9] = Jugador("Shai Gilgeous-Alexander", "Thunder", "G",
						   28, 198, 31.0, 5.4, 6.3);

	Sorts<Jugador> sorts;

	int opcion = 0;

	while (opcion != 3) {

		cout << endl;
		cout << "ESTADISTICAS DE JUGADORES NBA" << endl;
		cout << "1. Mostrar jugadores" << endl;
		cout << "2. Ordenar jugadores" << endl;
		cout << "3. Salir" << endl;
		cout << "Selecciona una opcion: ";
		cin >> opcion;

		if (opcion == 1) {

			mostrarJugadores(jugadores);

		} else if (opcion == 2) {

			mostrarMenuOrdenamiento();

			int criterio;
			cout << "Selecciona una opcion: ";
			cin >> criterio;

			if (criterio >= 1 && criterio <= 8) {

				jugadores = sorts.mergeSort(jugadores, criterio);

				cout << endl;
				cout << "Jugadores ordenados correctamente." << endl;

				mostrarJugadores(jugadores);

			} else {

				cout << endl;
				cout << "Opcion no valida." << endl;
			}

		} else if (opcion == 3) {

			cout << endl;
			cout << "Programa terminado." << endl;

		} else {

			cout << endl;
			cout << "Opcion no valida." << endl;
		}
	}

	return 0;
}
