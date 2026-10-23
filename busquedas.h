/*
 * busquedas.h
 *
 * Created on: 21/10/2026
 * Author: Julio Cesar Hdez.
 */

#ifndef BUSQUEDAS_H_
#define BUSQUEDAS_H_

#include <iostream>
#include <string>
#include <vector>
#include "jugador.h"

using namespace std;

int compararJugador(const Jugador &jugador, int criterio, string valor) {
    if (criterio == 1) {
        if (jugador.getNombre() == valor) {
            return 0;
        }
        if (jugador.getNombre() < valor) {
            return -1;
        }
        return 1;
    }
    else if (criterio == 2) {
        if (jugador.getEquipo() == valor) {
            return 0;
        }
        if (jugador.getEquipo() < valor) {
            return -1;
        }
        return 1;
    }
    else if (criterio == 3) {
        if (jugador.getPosicion() == valor) {
            return 0;
        }
        if (jugador.getPosicion() < valor) {
            return -1;
        }
        return 1;
    }
    else if (criterio == 4) {
        int buscado = stoi(valor);
        if (jugador.getEdad() == buscado) {
            return 0;
        }
        if (jugador.getEdad() < buscado) {
            return -1;
        }
        return 1;
    }
    else if (criterio == 5) {
        int buscado = stoi(valor);
        if (jugador.getAltura() == buscado) {
            return 0;
        }
        if (jugador.getAltura() < buscado) {
            return -1;
        }
        return 1;
    }
    else if (criterio == 6) {
        double buscado = stod(valor);
        if (jugador.getPuntos() == buscado) {
            return 0;
        }
        if (jugador.getPuntos() < buscado) {
            return -1;
        }
        return 1;
    }
    else if (criterio == 7) {
        double buscado = stod(valor);
        if (jugador.getRebotes() == buscado) {
            return 0;
        }
        if (jugador.getRebotes() < buscado) {
            return -1;
        }
        return 1;
    }
    else if (criterio == 8) {
        double buscado = stod(valor);
        if (jugador.getAsistencias() == buscado) {
            return 0;
        }
        if (jugador.getAsistencias() < buscado) {
            return -1;
        }
        return 1;
    }

    return 0;
}

// Busqueda binaria iterativa
// Mejor caso: O(1)
// Caso promedio: O(log n)
// Peor caso: O(log n)
int bs_seq(const vector<Jugador> &datos, int size, int criterio, string valor) {
    int inicio = 0; // O(1)
    int fin = size - 1; // O(1)

    while (inicio <= fin) { // O(log n)
        int mitad = inicio + (fin - inicio) / 2; // O(1)

        int comparacion = compararJugador(datos[mitad], criterio, valor); // O(1), excepto comparaciones de cadenas

        if (comparacion == 0) { // O(1)
            return mitad; // O(1)
        }

        if (comparacion > 0) { // O(1)
            fin = mitad - 1; // O(1)
        }
        else {
            inicio = mitad + 1; // O(1)
        }
    }

    return -1; // O(1)
}

// Funcion auxiliar para la busqueda binaria recursiva
// Mejor caso: O(1)
// Caso promedio: O(log n)
// Peor caso: O(log n)
int bs_aux(const vector<Jugador> &datos, int low, int high,
           int criterio, string valor) {
    if (low > high) { // O(1)
        return -1; // O(1)
    }

    int mitad = low + (high - low) / 2; // O(1)

    int comparacion = compararJugador(datos[mitad], criterio, valor); // O(1), excepto comparaciones de cadenas

    if (comparacion == 0) { // O(1)
        return mitad; // O(1)
    }

    if (comparacion > 0) { // O(1)
        return bs_aux(datos, low, mitad - 1, criterio, valor); // O(log n)
    }

    return bs_aux(datos, mitad + 1, high, criterio, valor); // O(log n)
}

// Funcion principal de busqueda binaria recursiva
// Mejor caso: O(1)
// Caso promedio: O(log n)
// Peor caso: O(log n)
int bs_rec(const vector<Jugador> &datos, int size, int criterio, string valor) {
    return bs_aux(datos, 0, size - 1, criterio, valor); // O(log n)
}

#endif
