/*
 * queue.h
 *
 * Created on: 21/10/2026
 * Author: Julio Cesar Hdez.
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <list>

using namespace std;

template <class T>
class Queue {
public:
    virtual void enqueue(T val) = 0;
    virtual void dequeue() = 0;
    virtual T front() const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
    virtual string toString() const = 0;
    virtual ~Queue() {}
};

// Fila implementada con un arreglo circular
template <class T>
class QueueVector : public Queue<T> {
private:
    T *data;
    int head;
    int tail;
    int size;
    int counter;

public:
    QueueVector(int sze = 100) {
        if (sze <= 0) {
            sze = 1;
        }

        size = sze;
        data = new T[size];
        head = 0;
        tail = 0;
        counter = 0;
    }

    ~QueueVector() {
        delete[] data;
    }

    // Inserta un elemento al final de la cola
    // Mejor caso: O(1), caso promedio: O(1), peor caso: O(1)
    void enqueue(T val) {
        if (counter == size) {       // O(1)
            return;                  // O(1)
        }

        data[tail] = val;            // O(1)
        tail = (tail + 1) % size;    // O(1)
        counter++;                   // O(1)
    }

    // Elimina el primer elemento de la cola
    // Mejor caso: O(1), caso promedio: O(1), peor caso: O(1)
    void dequeue() {
        if (counter == 0) {          // O(1)
            return;                  // O(1)
        }

        head = (head + 1) % size;    // O(1)
        counter--;                   // O(1)
    }

    // Regresa el primer elemento sin eliminarlo
    // Mejor caso: O(1), caso promedio: O(1), peor caso: O(1)
    T front() const {
        if (counter == 0) {          // O(1)
            return T();              // O(1)
        }

        return data[head];           // O(1)
    }

    // Indica si la cola esta vacia
    // Complejidad: O(1)
    bool empty() const {
        return counter == 0;         // O(1)
    }

    // Indica si el arreglo esta lleno
    // Complejidad: O(1)
    bool full() const {
        return counter == size;      // O(1)
    }

    // Elimina todos los elementos de la cola
    // Complejidad: O(1)
    void clear() {
        head = 0;                    // O(1)
        tail = 0;                    // O(1)
        counter = 0;                 // O(1)
    }

    // Convierte el contenido de la cola a una cadena
    // Complejidad: O(n)
    string toString() const {
        stringstream salida;         // O(1)
        salida << "[";               // O(1)

        for (int i = 0; i < counter; i++) { // O(n)
            salida << data[(head + i) % size]; // O(1) por elemento
            if (i < counter - 1) {   // O(1)
                salida << ", ";      // O(1)
            }
        }

        salida << "]";               // O(1)
        return salida.str();         // O(n) para construir la cadena
    }
};

template <class T>
class QueueList : public Queue<T> {
private:
    list<T> data;

public:
    // Crea una fila vacia
    // Complejidad: O(1)
    QueueList() {
    }

    // Inserta un elemento al final de la fila
    // Mejor caso: O(1), caso promedio: O(1), peor caso: O(1)
    void enqueue(T val) {
        data.push_back(val);         // O(1)
    }

    // Elimina el primer elemento de la fila
    // Mejor caso: O(1), caso promedio: O(1), peor caso: O(1)
    void dequeue() {
        if (data.empty()) {          // O(1)
            return;                  // O(1)
        }

        data.pop_front();            // O(1)
    }

    // Regresa el primer elemento sin eliminarlo
    // Complejidad: O(1)
    T front() const {
        if (data.empty()) {          // O(1)
            return T();              // O(1)
        }

        return data.front();         // O(1)
    }

    // Indica si la cola esta vacia
    // Complejidad: O(1)
    bool empty() const {
        return data.empty();         // O(1)
    }

    // Elimina todos los elementos de la cola
    // Complejidad: O(n)
    void clear() {
        data.clear();                // O(n)
    }

    // Convierte el contenido de la cola a una cadena
    // Complejidad: O(n)
    string toString() const {
        stringstream salida;         // O(1)
        salida << "[";               // O(1)

        typename list<T>::const_iterator iterador; // O(1)

        int contador = 0;            // O(1)

        for (iterador = data.begin(); iterador != data.end(); iterador++) { // O(n)
            salida << *iterador;     // O(1) por elemento
            contador++;              // O(1)

            if (contador < data.size()) { // O(1)
                salida << ", ";      // O(1)
            }
        }

        salida << "]";               // O(1)
        return salida.str();         // O(n) para construir la cadena
    }
};

#endif
