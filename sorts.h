
/*
 * sorts.h
 *
 * Created on: 20/09/2026
 * Author: Julio Cesar Hdez.
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include <vector>
#include "jugador.h"
#include "queue.h"

using namespace std;

template <class T>
class Sorts {
private:


    bool menorIgual(const T &jugador1, const T &jugador2, int criterio) {
        if (criterio == 1) {
            return jugador1.getNombre() <= jugador2.getNombre();
        }
        else if (criterio == 2) {
            return jugador1.getEquipo() <= jugador2.getEquipo();
        }
        else if (criterio == 3) {
            return jugador1.getPosicion() <= jugador2.getPosicion();
        }
        else if (criterio == 4) {
            return jugador1.getEdad() <= jugador2.getEdad();
        }
        else if (criterio == 5) {
            return jugador1.getAltura() <= jugador2.getAltura();
        }
        else if (criterio == 6) {
            return jugador1.getPuntos() <= jugador2.getPuntos();
        }
        else if (criterio == 7) {
            return jugador1.getRebotes() <= jugador2.getRebotes();
        }
        else {
            return jugador1.getAsistencias() <= jugador2.getAsistencias();
        }
    }

    // Combina dos mitades ordenadas
    // Mejor caso: O(n)
    // Caso promedio: O(n)
    // Peor caso: O(n)
    void mergeArray(vector<T> &datos, int inicio, int mitad,
                    int fin, int criterio) {
        vector<T> temporal(fin - inicio + 1); // O(n)

        int indiceIzquierdo = inicio; // O(1)
        int indiceDerecho = mitad + 1; // O(1)
        int indiceTemporal = 0; // O(1)

        // Compara y copia elementos de ambas mitades
        while (indiceIzquierdo <= mitad && indiceDerecho <= fin) { // O(n)
            if (menorIgual(datos[indiceIzquierdo],
                           datos[indiceDerecho], criterio)) { // O(1)
                temporal[indiceTemporal] = datos[indiceIzquierdo]; // O(1)
                indiceIzquierdo++; // O(1)
            }
            else {
                temporal[indiceTemporal] = datos[indiceDerecho]; // O(1)
                indiceDerecho++; // O(1)
            }

            indiceTemporal++; // O(1)
        }

        // Copia los elementos restantes de la mitad izquierda
        while (indiceIzquierdo <= mitad) { // O(n)
            temporal[indiceTemporal] = datos[indiceIzquierdo]; // O(1)
            indiceIzquierdo++; // O(1)
            indiceTemporal++; // O(1)
        }

        // Copia los elementos restantes de la mitad derecha
        while (indiceDerecho <= fin) { // O(n)
            temporal[indiceTemporal] = datos[indiceDerecho]; // O(1)
            indiceDerecho++; // O(1)
            indiceTemporal++; // O(1)
        }

        // Regresa los elementos ordenados al vector original
        for (int i = 0; i < (int)temporal.size(); i++) { // O(n)
            datos[inicio + i] = temporal[i]; // O(1)
        }
    }

    // Divide el vector y ordena recursivamente sus mitades
    // Mejor caso: O(n log n)
    // Caso promedio: O(n log n)
    // Peor caso: O(n log n)
    void mergeSplit(vector<T> &datos, int inicio, int fin, int criterio) {
        if (inicio >= fin) { // O(1)
            return; // O(1)
        }

        int mitad = inicio + (fin - inicio) / 2; // O(1)

        mergeSplit(datos, inicio, mitad, criterio); // O(n log n)
        mergeSplit(datos, mitad + 1, fin, criterio); // O(n log n)

        mergeArray(datos, inicio, mitad, fin, criterio); // O(n)
    }

public:

    // Ordena un vector utilizando Merge Sort
    // Mejor caso: O(n log n)
    // Caso promedio: O(n log n)
    // Peor caso: O(n log n)
    vector<T> mergeSort(vector<T> datos, int criterio) {
        if (datos.size() <= 1) { // O(1)
            return datos; // O(n) por copia del vector
        }

        mergeSplit(datos, 0, (int)datos.size() - 1, criterio); // O(n log n)

        return datos; // O(n) por copia del vector
    }

    // Ordena una fila convirtiendola a vector y regresando el resultado a otra fila
    // Mejor caso: O(n log n)
    // Caso promedio: O(n log n)
    // Peor caso: O(n log n)
    QueueList<T> mergeSort(const QueueList<T> &source, int criterio) {
        QueueList<T> copia(source); // O(n)

        int cantidad = 0; // O(1)

        // Cuenta los elementos de la fila
        while (!copia.empty()) { // O(n)
            cantidad++; // O(1)
            copia.dequeue(); // O(1)
        }

        vector<T> datos; // O(1)

        QueueList<T> copiaDatos(source); // O(n)

        // Copia los elementos de la fila al vector
        for (int i = 0; i < cantidad; i++) { // O(n)
            datos.push_back(copiaDatos.front()); // O(1) amortizado
            copiaDatos.dequeue(); // O(1)
        }

        // Ordena el vector
        datos = mergeSort(datos, criterio); // O(n log n)

        QueueList<T> resultado; // O(1)

        // Copia los elementos ordenados a la fila de salida
        for (int i = 0; i < (int)datos.size(); i++) { // O(n)
            resultado.enqueue(datos[i]); // O(1)
        }

        return resultado; // O(n) por copia de la fila
    }
};

#endif
