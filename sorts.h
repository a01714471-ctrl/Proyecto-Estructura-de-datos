/*
 * sorts.h
 *
 * Created on: 12/11/2026
 * Author: Julio Cesar Hdez.
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include "jugador.h"

using namespace std;

template <class T>
class Sorts {
private:
    void copyArray(vector<T>&, vector<T>&, int, int);
    void mergeArray(vector<T>&, vector<T>&, int, int, int, int);
    void mergeSplit(vector<T>&, vector<T>&, int, int, int);
    int comparar(T, T, int);

public:
    vector<T> mergeSort(const vector<T>&, int);
};

// Compara dos jugadores según el criterio.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
int Sorts<T>::comparar(T jugador1, T jugador2, int criterio) {

    // El switch selecciona un criterio en tiempo constante.
    switch (criterio) {
        case 1:
            if (jugador1.getNombre() < jugador2.getNombre()) return -1;
            if (jugador1.getNombre() > jugador2.getNombre()) return 1;
            break;

        case 2:
            if (jugador1.getEquipo() < jugador2.getEquipo()) return -1;
            if (jugador1.getEquipo() > jugador2.getEquipo()) return 1;
            break;

        case 3:
            if (jugador1.getPosicion() < jugador2.getPosicion()) return -1;
            if (jugador1.getPosicion() > jugador2.getPosicion()) return 1;
            break;

        case 4:
            if (jugador1.getEdad() < jugador2.getEdad()) return -1;
            if (jugador1.getEdad() > jugador2.getEdad()) return 1;
            break;

        case 5:
            if (jugador1.getAltura() < jugador2.getAltura()) return -1;
            if (jugador1.getAltura() > jugador2.getAltura()) return 1;
            break;

        case 6:
            if (jugador1.getPuntos() < jugador2.getPuntos()) return -1;
            if (jugador1.getPuntos() > jugador2.getPuntos()) return 1;
            break;

        case 7:
            if (jugador1.getRebotes() < jugador2.getRebotes()) return -1;
            if (jugador1.getRebotes() > jugador2.getRebotes()) return 1;
            break;

        case 8:
            if (jugador1.getAsistencias() < jugador2.getAsistencias()) return -1;
            if (jugador1.getAsistencias() > jugador2.getAsistencias()) return 1;
            break;
    }

    return 0;
}

// Copia los elementos del arreglo auxiliar.
// Mejor caso: O(n).
// Caso promedio: O(n).
// Peor caso: O(n).
template <class T>
void Sorts<T>::copyArray(vector<T>& A, vector<T>& B,
                         int low, int high) {

    // Recorre todos los elementos del segmento.
    for (int i = low; i <= high; i++) { // O(n)
        A[i] = B[i]; // O(1)
    }
}

// Mezcla dos mitades ordenadas.
// Mejor caso: O(n).
// Caso promedio: O(n).
// Peor caso: O(n).
template <class T>
void Sorts<T>::mergeArray(vector<T>& A, vector<T>& B,
                          int low, int mid, int high,
                          int criterio) {

    int i_izquierda = low;
    int i_derecha = mid + 1;
    int i_ordenando = low;

    // Compara y coloca elementos de ambas mitades.
    // En total, cada elemento se procesa una vez: O(n).
    while (i_izquierda <= mid && i_derecha <= high) { // O(n)

        // Comparar dos jugadores: O(1).
        if (comparar(A[i_izquierda], A[i_derecha], criterio) <= 0) {
            B[i_ordenando] = A[i_izquierda]; // O(1)
            i_izquierda++;
        } else {
            B[i_ordenando] = A[i_derecha]; // O(1)
            i_derecha++;
        }

        i_ordenando++;
    }

    // Copia los elementos restantes de la mitad izquierda.
    while (i_izquierda <= mid) { // O(n)
        B[i_ordenando] = A[i_izquierda]; // O(1)
        i_izquierda++;
        i_ordenando++;
    }

    // Copia los elementos restantes de la mitad derecha.
    while (i_derecha <= high) { // O(n)
        B[i_ordenando] = A[i_derecha]; // O(1)
        i_derecha++;
        i_ordenando++;
    }

    // Copiar el segmento ordenado: O(n).
    copyArray(A, B, low, high);
}

// Divide recursivamente el arreglo.
// Mejor caso: O(n log n).
// Caso promedio: O(n log n).
// Peor caso: O(n log n).
// Espacio auxiliar: O(log n) por la recursión.
template <class T>
void Sorts<T>::mergeSplit(vector<T>& A, vector<T>& B,
                          int low, int high, int criterio) {

    if (low < high) { // O(1)

        int mitad = (low + high) / 2; // O(1)

        // Ordenar la mitad izquierda.
        mergeSplit(A, B, low, mitad, criterio);

        // Ordenar la mitad derecha.
        mergeSplit(A, B, mitad + 1, high, criterio);

        // Mezclar las mitades ordenadas: O(n).
        mergeArray(A, B, low, mitad, high, criterio);
    }
}

// Ordena el arreglo mediante Merge Sort.
// Mejor caso: O(n log n).
// Caso promedio: O(n log n).
// Peor caso: O(n log n).
// Espacio auxiliar: O(n) por los vectores utilizados.
template <class T>
vector<T> Sorts<T>::mergeSort(const vector<T>& source,
                              int criterio) {

    // Copiar el arreglo original: O(n).
    vector<T> v(source);

    // Crear el vector auxiliar: O(n).
    vector<T> tmp(v.size());

    // Verificar si el vector contiene elementos: O(1).
    if (!v.empty()) {

        // Ordenar mediante Merge Sort: O(n log n).
        mergeSplit(v, tmp, 0, v.size() - 1, criterio);
    }

    return v; // O(1) al retornar por movimiento en condiciones habituales.
}

#endif /* SORTS_H_ */
