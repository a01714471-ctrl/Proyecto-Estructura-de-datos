/*
 * jugador.h
 *
 *  Created on: 20/09/2026
 *      Author: Julio César Hdez.
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>

using namespace std;

template <class T>
class Sorts {
private:
	void copyArray(vector<T>&, vector<T>&, int, int);
	void mergeArray(vector<T>&, vector<T>&, int, int, int, int);
	void mergeSplit(vector<T>&, vector<T>&, int, int, int);

public:
	vector<T> mergeSort(const vector<T>&, int);
};

/*
 * Mejor caso: O(1)
 * Caso promedio: O(n)
 * Peor caso: O(n)
 */
template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B,
						 int low, int high) { // O(n)

	for (int i = low; i <= high; i++) { // O(n)
		A[i] = B[i]; // O(1)
	}
}

/*
 * Mejor caso: O(n)
 * Caso promedio: O(n)
 * Peor caso: O(n)
 */
template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B,
						  int low, int mid, int high,
						  int criterio) { // O(n)

	int i_izquierda = low; // O(1)
	int i_derecha = mid + 1; // O(1)
	int i_ordenando = low; // O(1)

	while (i_izquierda <= mid && i_derecha <= high) { // O(n)

		bool izquierda = false; // O(1)

		if (criterio == 1) { // O(1)

			if (A[i_izquierda].getNombre() <=
				A[i_derecha].getNombre()) { // O(1)

				izquierda = true; // O(1)
			}
		}

		else if (criterio == 2) { // O(1)

			if (A[i_izquierda].getEquipo() <=
				A[i_derecha].getEquipo()) { // O(1)

				izquierda = true; // O(1)
			}
		}

		else if (criterio == 3) { // O(1)

			if (A[i_izquierda].getPosicion() <=
				A[i_derecha].getPosicion()) { // O(1)

				izquierda = true; // O(1)
			}
		}

		else if (criterio == 4) { // O(1)

			if (A[i_izquierda].getEdad() <=
				A[i_derecha].getEdad()) { // O(1)

				izquierda = true; // O(1)
			}
		}

		else if (criterio == 5) { // O(1)

			if (A[i_izquierda].getAltura() <=
				A[i_derecha].getAltura()) { // O(1)

				izquierda = true; // O(1)
			}
		}

		else if (criterio == 6) { // O(1)

			if (A[i_izquierda].getPuntos() <=
				A[i_derecha].getPuntos()) { // O(1)

				izquierda = true; // O(1)
			}
		}

		else if (criterio == 7) { // O(1)

			if (A[i_izquierda].getRebotes() <=
				A[i_derecha].getRebotes()) { // O(1)

				izquierda = true; // O(1)
			}
		}

		else if (criterio == 8) { // O(1)

			if (A[i_izquierda].getAsistencias() <=
				A[i_derecha].getAsistencias()) { // O(1)

				izquierda = true; // O(1)
			}
		}

		if (izquierda) { // O(1)

			B[i_ordenando] = A[i_izquierda]; // O(1)
			i_izquierda++; // O(1)

		} else {

			B[i_ordenando] = A[i_derecha]; // O(1)
			i_derecha++; // O(1)
		}

		i_ordenando++; // O(1)
	}

	while (i_izquierda <= mid) { // O(n)

		B[i_ordenando] = A[i_izquierda]; // O(1)
		i_izquierda++; // O(1)
		i_ordenando++; // O(1)
	}

	while (i_derecha <= high) { // O(n)

		B[i_ordenando] = A[i_derecha]; // O(1)
		i_derecha++; // O(1)
		i_ordenando++; // O(1)
	}

	copyArray(A, B, low, high); // O(n)
}

/*
 * Mejor caso: O(n log n)
 * Caso promedio: O(n log n)
 * Peor caso: O(n log n)
 */
template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B,
						  int low, int high,
						  int criterio) { // O(n log n)

	if (low < high) { // O(n log n)

		int mitad = (low + high) / 2; // O(1)

		// Ordenar la mitad izquierda del arreglo
		mergeSplit(A, B, low, mitad, criterio); // O(log n)

		// Ordenar la mitad derecha del arreglo
		mergeSplit(A, B, mitad + 1, high, criterio); // O(log n)

		// Mezclar en orden ambas mitades que ya están ordenadas
		mergeArray(A, B, low, mitad, high, criterio); // O(n)
	}
}

/*
 * Mejor caso: O(n log n)
 * Caso promedio: O(n log n)
 * Peor caso: O(n log n)
 */
template <class T>
vector<T> Sorts<T>::mergeSort(const vector<T> &source,
							  int criterio) { // O(n log n)

	vector<T> v(source); // O(n)
	vector<T> tmp(v.size()); // O(n)

	if (v.size() > 1) { // O(1)

		mergeSplit(v, tmp, 0, v.size() - 1, criterio); // O(n log n)
	}

	return v; // O(1)
}

#endif /* SORTS_H_ */
