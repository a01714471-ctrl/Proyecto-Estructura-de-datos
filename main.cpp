
/*
 * main.cpp
 *
 * Created on: 12/11/2026
 * Author: Julio Cesar Hdez.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "jugador.h"
#include "AVL.h"
#include "sorts.h"

using namespace std;

// Clase para administrar los ocho indices AVL

class Indices {
private:
    AVL<Jugador> nombre;
    AVL<Jugador> equipo;
    AVL<Jugador> posicion;
    AVL<Jugador> edad;
    AVL<Jugador> altura;
    AVL<Jugador> puntos;
    AVL<Jugador> rebotes;
    AVL<Jugador> asistencias;

public:
    Indices() : nombre(1), equipo(2), posicion(3), edad(4),
                altura(5), puntos(6), rebotes(7), asistencias(8) {
    }

    // Inserta un jugador en los ocho indices.
    // Tiempo: O(log n), porque se realizan ocho inserciones AVL.
    void add(Jugador jugador) {
        nombre.add(jugador);
        equipo.add(jugador);
        posicion.add(jugador);
        edad.add(jugador);
        altura.add(jugador);
        puntos.add(jugador);
        rebotes.add(jugador);
        asistencias.add(jugador);
    }

    // Elimina un jugador de los ocho indices.
    // Tiempo: O(log n + k), considerando la busqueda entre duplicados.
    void remove(Jugador jugador) {
        nombre.remove(jugador);
        equipo.remove(jugador);
        posicion.remove(jugador);
        edad.remove(jugador);
        altura.remove(jugador);
        puntos.remove(jugador);
        rebotes.remove(jugador);
        asistencias.remove(jugador);
    }

    // Busca jugadores dependiendo del criterio seleccionado.
    // Tiempo: O(log n + k).
    vector<Jugador> search(Jugador jugador, int criterio) {
        switch (criterio) {
            case 1:
                return nombre.search(jugador);
            case 2:
                return equipo.search(jugador);
            case 3:
                return posicion.search(jugador);
            case 4:
                return edad.search(jugador);
            case 5:
                return altura.search(jugador);
            case 6:
                return puntos.search(jugador);
            case 7:
                return rebotes.search(jugador);
            case 8:
                return asistencias.search(jugador);
            default:
                return vector<Jugador>();
        }
    }
};

// --------------------------------------------------
// Funciones auxiliares
// --------------------------------------------------

void mostrarCriterios() {
    cout << "\nCriterios disponibles:\n";
    cout << "1. Nombre\n";
    cout << "2. Equipo\n";
    cout << "3. Posicion\n";
    cout << "4. Edad\n";
    cout << "5. Altura\n";
    cout << "6. Puntos\n";
    cout << "7. Rebotes\n";
    cout << "8. Asistencias\n";
}

// Muestra los jugadores en una tabla organizada.
// Tiempo: O(n).
void mostrarJugadores(const vector<Jugador>& jugadores) {

    if (jugadores.empty()) {
        cout << "\nNo hay jugadores registrados.\n";
        return;
    }

    cout << "\n";

    cout << left
         << setw(27) << "NOMBRE"
         << setw(17) << "EQUIPO"
         << setw(12) << "POSICION"
         << right
         << setw(8) << "EDAD"
         << setw(10) << "ALTURA"
         << setw(10) << "PUNTOS"
         << setw(10) << "REBOTES"
         << setw(13) << "ASISTENCIAS"
         << endl;

    cout << string(107, '-') << endl;

    for (int i = 0; i < jugadores.size(); i++) {

        cout << left
             << setw(27) << jugadores[i].getNombre()
             << setw(17) << jugadores[i].getEquipo()
             << setw(12) << jugadores[i].getPosicion()
             << right
             << setw(8) << jugadores[i].getEdad()
             << setw(10) << jugadores[i].getAltura()
             << setw(10) << fixed << setprecision(1)
             << jugadores[i].getPuntos()
             << setw(10) << jugadores[i].getRebotes()
             << setw(13) << jugadores[i].getAsistencias()
             << endl;
    }

    cout << string(107, '-') << endl;
}

// Convierte una cadena a entero y verifica que no tenga caracteres extra.
bool convertirEntero(string cadena, int& valor) {
    stringstream aux(cadena);

    aux >> valor;
    aux >> ws;

    return !aux.fail() && aux.eof();
}

// Convierte una cadena a double y verifica que no tenga caracteres extra.
bool convertirDouble(string cadena, double& valor) {
    stringstream aux(cadena);

    aux >> valor;
    aux >> ws;

    return !aux.fail() && aux.eof();
}

// Convierte una linea del archivo en un objeto Jugador.
// Tiempo: O(L), donde L es la longitud de la linea.
bool convertirJugador(string linea, Jugador& jugador) {
    string campos[8];
    stringstream aux(linea);

    for (int i = 0; i < 8; i++) {
        if (!getline(aux, campos[i], ';')) {
            return false;
        }
    }

    string extra;
    if (getline(aux, extra, ';')) {
        return false;
    }

    int edad, altura;
    double puntos, rebotes, asistencias;

    if (!convertirEntero(campos[3], edad) ||
        !convertirEntero(campos[4], altura) ||
        !convertirDouble(campos[5], puntos) ||
        !convertirDouble(campos[6], rebotes) ||
        !convertirDouble(campos[7], asistencias)) {
        return false;
    }

    jugador = Jugador(campos[0], campos[1], campos[2],
                      edad, altura, puntos, rebotes, asistencias);

    return true;
}

// Carga los jugadores desde el archivo.
// Tiempo: O(n log n), por las inserciones en los ocho AVL.
void cargarJugadores(string archivo, vector<Jugador>& jugadores,
                     Indices& indices) {

    ifstream entrada(archivo.c_str());

    if (!entrada.is_open()) {
        cout << "\nNo se pudo abrir el archivo " << archivo << ".\n";
        return;
    }

    string linea;
    Jugador jugador;
    int cargados = 0;

    while (getline(entrada, linea)) {
        if (convertirJugador(linea, jugador)) {
            jugadores.push_back(jugador);
            indices.add(jugador);
            cargados++;
        }
    }

    entrada.close();

    cout << "\nSe cargaron " << cargados << " jugadores.\n";
}

// Guarda los jugadores en un archivo.
// Tiempo: O(n).
void guardarJugadores(string archivo, const vector<Jugador>& jugadores) {
    ofstream salida(archivo.c_str());

    if (!salida.is_open()) {
        cout << "\nNo se pudo guardar el archivo " << archivo << ".\n";
        return;
    }

    for (int i = 0; i < jugadores.size(); i++) {
        salida << jugadores[i].getNombre() << ";"
               << jugadores[i].getEquipo() << ";"
               << jugadores[i].getPosicion() << ";"
               << jugadores[i].getEdad() << ";"
               << jugadores[i].getAltura() << ";"
               << jugadores[i].getPuntos() << ";"
               << jugadores[i].getRebotes() << ";"
               << jugadores[i].getAsistencias() << endl;
    }

    salida.close();

    cout << "\nArchivo guardado correctamente: " << archivo << endl;
}

// Crea un jugador temporal para realizar una busqueda por criterio.
Jugador crearClave(string valor, int criterio) {
    int numeroEntero = 0;
    double numeroDouble = 0;

    if (criterio == 1) {
        return Jugador(valor, "", "", 0, 0, 0, 0, 0);
    }

    if (criterio == 2) {
        return Jugador("", valor, "", 0, 0, 0, 0, 0);
    }

    if (criterio == 3) {
        return Jugador("", "", valor, 0, 0, 0, 0, 0);
    }

    if (criterio == 4 || criterio == 5) {
        convertirEntero(valor, numeroEntero);

        if (criterio == 4) {
            return Jugador("", "", "", numeroEntero, 0, 0, 0, 0);
        }

        return Jugador("", "", "", 0, numeroEntero, 0, 0, 0);
    }

    convertirDouble(valor, numeroDouble);

    if (criterio == 6) {
        return Jugador("", "", "", 0, 0, numeroDouble, 0, 0);
    }

    if (criterio == 7) {
        return Jugador("", "", "", 0, 0, 0, numeroDouble, 0);
    }

    return Jugador("", "", "", 0, 0, 0, 0, numeroDouble);
}

// Captura los datos de un nuevo jugador.
Jugador capturarJugador() {
    string nombre, equipo, posicion;
    string entrada;
    int edad, altura;
    double puntos, rebotes, asistencias;

    cout << "\nNombre: ";
    getline(cin, nombre);

    cout << "Equipo: ";
    getline(cin, equipo);

    cout << "Posicion: ";
    getline(cin, posicion);

    do {
        cout << "Edad: ";
        getline(cin, entrada);
    } while (!convertirEntero(entrada, edad));

    do {
        cout << "Altura (cm): ";
        getline(cin, entrada);
    } while (!convertirEntero(entrada, altura));

    do {
        cout << "Puntos: ";
        getline(cin, entrada);
    } while (!convertirDouble(entrada, puntos));

    do {
        cout << "Rebotes: ";
        getline(cin, entrada);
    } while (!convertirDouble(entrada, rebotes));

    do {
        cout << "Asistencias: ";
        getline(cin, entrada);
    } while (!convertirDouble(entrada, asistencias));

    return Jugador(nombre, equipo, posicion, edad, altura,
                   puntos, rebotes, asistencias);
}

// Compara todos los atributos de dos jugadores.
bool mismoJugador(Jugador jugador1, Jugador jugador2) {
    return jugador1.getNombre() == jugador2.getNombre() &&
           jugador1.getEquipo() == jugador2.getEquipo() &&
           jugador1.getPosicion() == jugador2.getPosicion() &&
           jugador1.getEdad() == jugador2.getEdad() &&
           jugador1.getAltura() == jugador2.getAltura() &&
           jugador1.getPuntos() == jugador2.getPuntos() &&
           jugador1.getRebotes() == jugador2.getRebotes() &&
           jugador1.getAsistencias() == jugador2.getAsistencias();
}

void mostrarMenu() {
    cout << "\n========== NBA PLAYER STATS ==========\n";
    cout << "1. Mostrar jugadores\n";
    cout << "2. Ordenar jugadores\n";
    cout << "3. Buscar jugadores\n";
    cout << "4. Agregar jugador\n";
    cout << "5. Eliminar jugador\n";
    cout << "6. Guardar jugadores\n";
    cout << "7. Salir\n";
    cout << "Selecciona una opcion: ";
}

// --------------------------------------------------
// Funcion principal
// --------------------------------------------------

int main() {

    vector<Jugador> jugadores;
    Indices indices;
    Sorts<Jugador> ordenamiento;

    int opcion = 0;
    string entrada;

    // Carga inicial de los jugadores.
    cargarJugadores("jugadores.txt", jugadores, indices);

    do {
        mostrarMenu();
        getline(cin, entrada);

        if (!convertirEntero(entrada, opcion)) {
            opcion = 0;
        }

        switch (opcion) {

            // Mostrar jugadores.
            case 1:
                mostrarJugadores(jugadores);
                break;

            // Ordenar jugadores con Merge Sort.
            case 2: {
                int criterio;

                mostrarCriterios();
                cout << "\nSelecciona el criterio para ordenar: ";
                getline(cin, entrada);

                if (!convertirEntero(entrada, criterio) ||
                    criterio < 1 || criterio > 8) {
                    cout << "\nCriterio no valido.\n";
                    break;
                }

                // Tiempo: O(n log n).
                vector<Jugador> ordenados =
                    ordenamiento.mergeSort(jugadores, criterio);

                cout << "\nJugadores ordenados:\n";
                mostrarJugadores(ordenados);

                guardarJugadores("jugadores_ordenados.txt", ordenados);
                break;
            }

            // Buscar jugadores mediante los indices AVL.
            case 3: {
                int criterio;

                mostrarCriterios();
                cout << "\nSelecciona el criterio para buscar: ";
                getline(cin, entrada);

                if (!convertirEntero(entrada, criterio) ||
                    criterio < 1 || criterio > 8) {
                    cout << "\nCriterio no valido.\n";
                    break;
                }

                cout << "Ingresa el valor que deseas buscar: ";
                getline(cin, entrada);

                if (criterio == 4 || criterio == 5) {
                    int valor;

                    if (!convertirEntero(entrada, valor)) {
                        cout << "\nEl valor debe ser un numero entero.\n";
                        break;
                    }
                }

                if (criterio >= 6) {
                    double valor;

                    if (!convertirDouble(entrada, valor)) {
                        cout << "\nEl valor debe ser numerico.\n";
                        break;
                    }
                }

                Jugador clave = crearClave(entrada, criterio);

                // Tiempo: O(log n + k).
                vector<Jugador> resultado = indices.search(clave, criterio);

                cout << "\nResultados de la busqueda:\n";
                mostrarJugadores(resultado);
                break;
            }

            // Agregar un jugador.
            case 4: {
                Jugador nuevo = capturarJugador();

                jugadores.push_back(nuevo);
                indices.add(nuevo);

                cout << "\nJugador agregado correctamente.\n";
                break;
            }

            // Eliminar un jugador por nombre.
            case 5: {
                string nombre;

                cout << "\nIngresa el nombre del jugador que deseas eliminar: ";
                getline(cin, nombre);

                Jugador clave = crearClave(nombre, 1);
                vector<Jugador> resultado = indices.search(clave, 1);

                if (resultado.empty()) {
                    cout << "\nNo se encontro ningun jugador con ese nombre.\n";
                    break;
                }

                cout << "\nJugadores encontrados:\n";
                mostrarJugadores(resultado);

                int seleccion = 1;

                if (resultado.size() > 1) {
                    cout << "\nHay varios jugadores con ese nombre.\n";
                    cout << "Selecciona el numero del jugador que deseas eliminar: ";
                    getline(cin, entrada);

                    if (!convertirEntero(entrada, seleccion) ||
                        seleccion < 1 ||
                        seleccion > resultado.size()) {
                        cout << "\nSeleccion no valida.\n";
                        break;
                    }
                }

                Jugador eliminado = resultado[seleccion - 1];

                indices.remove(eliminado);

                for (int i = 0; i < jugadores.size(); i++) {
                    if (mismoJugador(jugadores[i], eliminado)) {
                        jugadores.erase(jugadores.begin() + i);
                        break;
                    }
                }

                cout << "\nJugador eliminado correctamente.\n";
                break;
            }

            // Guardar jugadores.
            case 6:
                guardarJugadores("jugadores.txt", jugadores);
                break;

            // Salir del programa.
            case 7:
                guardarJugadores("jugadores.txt", jugadores);
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "\nOpcion no valida. Intenta nuevamente.\n";
                break;
        }

    } while (opcion != 7);

    return 0;
}
