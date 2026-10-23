/*
 * main.cpp
 *
 * Created on: 20/09/2026
 * Author: Julio Cesar Hdez.
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "jugador.h"
#include "queue.h"
#include "sorts.h"
#include "busquedas.h"

using namespace std;

vector<Jugador> colaAVector(const QueueList<Jugador> &cola) {
    QueueList<Jugador> copia(cola);
    vector<Jugador> datos;

    while (!copia.empty()) {
        datos.push_back(copia.front());
        copia.dequeue();
    }

    return datos;
}

void mostrarEncabezado() {
    cout << left
         << setw(26) << "Nombre"
         << setw(18) << "Equipo"
         << setw(8)  << "Pos"
         << right
         << setw(7)  << "Edad"
         << setw(9)  << "Altura"
         << setw(10) << "Puntos"
         << setw(10) << "Rebotes"
         << setw(13) << "Asistencias" << endl;

    cout << string(101, '-') << endl;
}

void mostrarFila(const Jugador &jugador) {
    cout << left
         << setw(26) << jugador.getNombre()
         << setw(18) << jugador.getEquipo()
         << setw(8)  << jugador.getPosicion()
         << right
         << setw(7)  << jugador.getEdad()
         << setw(9)  << jugador.getAltura()
         << setw(10) << fixed << setprecision(1) << jugador.getPuntos()
         << setw(10) << jugador.getRebotes()
         << setw(13) << jugador.getAsistencias() << endl;
}

void mostrarJugadores(const QueueList<Jugador> &jugadores) {
    QueueList<Jugador> copia(jugadores);

    if (copia.empty()) {
        cout << "No hay jugadores registrados." << endl;
        return;
    }

    mostrarEncabezado();

    while (!copia.empty()) {
        mostrarFila(copia.front());
        copia.dequeue();
    }
}

int main() {
    QueueList<Jugador> jugadores;
    Sorts<Jugador> sorts;

    // Registro inicial de jugadores
    jugadores.enqueue(Jugador("LeBron James", "Lakers", "F", 41, 206, 25.0, 7.0, 8.0));
    jugadores.enqueue(Jugador("Stephen Curry", "Warriors", "G", 38, 188, 24.5, 4.5, 6.2));
    jugadores.enqueue(Jugador("Nikola Jokic", "Nuggets", "C", 31, 211, 27.1, 12.4, 9.0));
    jugadores.enqueue(Jugador("Luka Doncic", "Lakers", "G", 27, 201, 28.4, 8.7, 8.2));
    jugadores.enqueue(Jugador("Giannis Antetokounmpo", "Heat", "F", 31, 211, 30.2, 11.8, 6.5));
    jugadores.enqueue(Jugador("Jayson Tatum", "Celtics", "F", 28, 203, 27.0, 8.8, 5.9));
    jugadores.enqueue(Jugador("Kevin Durant", "Rockets", "F", 37, 208, 26.8, 6.9, 4.8));
    jugadores.enqueue(Jugador("Anthony Edwards", "Timberwolves", "G", 25, 193, 27.6, 5.2, 4.5));
    jugadores.enqueue(Jugador("Bam Adebayo", "Heat", "C", 32, 213, 28.7, 11.1, 4.2));
    jugadores.enqueue(Jugador("Shai Gilgeous-Alexander", "Thunder", "G", 28, 198, 31.0, 5.4, 6.3));

    int opcion;

    do {
        cout << "\n===== ESTADISTICAS DE JUGADORES DE LA NBA =====" << endl;
        cout << "1. Mostrar jugadores" << endl;
        cout << "2. Ordenar jugadores" << endl;
        cout << "3. Buscar jugador" << endl;
        cout << "4. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            mostrarJugadores(jugadores);
        }
        else if (opcion == 2) {
            int criterio;

            cout << "\nOrdenar por:" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Equipo" << endl;
            cout << "3. Posicion" << endl;
            cout << "4. Edad" << endl;
            cout << "5. Altura" << endl;
            cout << "6. Puntos" << endl;
            cout << "7. Rebotes" << endl;
            cout << "8. Asistencias" << endl;
            cout << "Selecciona un criterio: ";
            cin >> criterio;

            if (criterio >= 1 && criterio <= 8) {
                jugadores = sorts.mergeSort(jugadores, criterio);

                cout << "\nJugadores ordenados correctamente." << endl;
                mostrarJugadores(jugadores);
            }
            else {
                cout << "Criterio no valido." << endl;
            }
        }
        else if (opcion == 3) {
            int criterio;
            string valor;

            cout << "\nBuscar por:" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Equipo" << endl;
            cout << "3. Posicion" << endl;
            cout << "4. Edad" << endl;
            cout << "5. Altura" << endl;
            cout << "6. Puntos" << endl;
            cout << "7. Rebotes" << endl;
            cout << "8. Asistencias" << endl;
            cout << "Selecciona un criterio: ";
            cin >> criterio;

            if (criterio >= 1 && criterio <= 8) {
                cin.ignore(1000, '\n');

                cout << "Ingresa el valor que deseas buscar: ";
                getline(cin, valor);

                // Se ordena por el mismo criterio antes de buscar
                jugadores = sorts.mergeSort(jugadores, criterio);

                vector<Jugador> datos = colaAVector(jugadores);

                int indice = bs_rec(datos, datos.size(), criterio, valor);

                if (indice != -1) {
                    cout << "\nJugador encontrado:" << endl;
                    mostrarEncabezado();
                    mostrarFila(datos[indice]);
                }
                else {
                    cout << "No se encontro un jugador con ese valor." << endl;
                }
            }
            else {
                cout << "Criterio no valido." << endl;
            }
        }
        else if (opcion == 4) {
            cout << "Saliendo del programa..." << endl;
        }
        else {
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 4);

    return 0;
}
