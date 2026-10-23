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
#include <fstream>
#include <sstream>
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

// Lee los jugadores desde un archivo de texto
bool cargarJugadores(const string &nombreArchivo,
                     QueueList<Jugador> &jugadores) {
    ifstream archivo(nombreArchivo);
    string linea;
    int numeroLinea = 0;
    int jugadoresCargados = 0;

    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo "
             << nombreArchivo << "." << endl;
        return false;
    }

    while (getline(archivo, linea)) {
        numeroLinea++;

        if (linea.empty()) {
            continue;
        }

        stringstream flujo(linea);
        string campos[8];

        // Separa los ocho campos utilizando punto y coma
        for (int i = 0; i < 8; i++) {
            if (!getline(flujo, campos[i], ';')) {
                cout << "Registro incompleto en la linea "
                     << numeroLinea << ". Se omitira." << endl;
                break;
            }
        }

        // Verifica que la linea contenga los ocho campos
        bool registroValido = true;

        for (int i = 0; i < 8; i++) {
            if (campos[i].empty()) {
                registroValido = false;
            }
        }

        // Revisa si existen campos adicionales
        string campoExtra;
        if (registroValido && getline(flujo, campoExtra, ';')) {
            registroValido = false;
        }

        if (!registroValido) {
            cout << "Registro invalido en la linea "
                 << numeroLinea << ". Se omitira." << endl;
            continue;
        }

        try {
            string nombre = campos[0];
            string equipo = campos[1];
            string posicion = campos[2];

            int edad = stoi(campos[3]);
            int altura = stoi(campos[4]);
            double puntos = stod(campos[5]);
            double rebotes = stod(campos[6]);
            double asistencias = stod(campos[7]);

            jugadores.enqueue(
                Jugador(nombre, equipo, posicion, edad, altura,
                        puntos, rebotes, asistencias)
            );

            jugadoresCargados++;
        }
        catch (const exception &) {
            cout << "Error en los datos numericos de la linea "
                 << numeroLinea << ". Se omitira." << endl;
        }
    }

    archivo.close();

    cout << "Jugadores cargados: " << jugadoresCargados << endl;

    return jugadoresCargados > 0;
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
         << setw(10) << fixed << setprecision(1)
         << jugador.getPuntos()
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

    // Carga inicial de jugadores desde el archivo
    if (!cargarJugadores("jugadores.txt", jugadores)) {
        cout << "No se pudieron cargar los jugadores. "
             << "Verifica el archivo." << endl;
        return 1;
    }

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

                int indice = bs_rec(
                    datos, datos.size(), criterio, valor
                );

                if (indice != -1) {
                    cout << "\nJugador encontrado:" << endl;
                    mostrarEncabezado();
                    mostrarFila(datos[indice]);
                }
                else {
                    cout << "No se encontro un jugador con ese valor."
                         << endl;
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
