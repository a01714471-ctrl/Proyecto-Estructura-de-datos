/*
 * AVL.h
 *
 * Adaptado para el proyecto NBA
 */

#ifndef AVL_H_
#define AVL_H_

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "jugador.h"

using namespace std;

template <class T> class AVL;

template <class T>
class Node {
private:
    T value;
    vector<T> repetidos;
    Node *left, *right;
    int level, balance;

    int comparar(T, T, int) const;
    bool iguales(T, T) const;
    void actualizar();
    Node<T>* removeMax(Node<T>*&);

public:
    Node(T);
    Node(T, Node<T>*, Node<T>*, int, int);

    Node<T>* add(T, int);
    bool find(T, int) const;
    vector<T> search(T, int) const;
    Node<T>* remove(T, int);

    void removeChilds();
    void inorder(stringstream&) const;
    void preorder(stringstream&) const;
    int max_depth();

    Node<T>* balance_tree();
    Node<T>* rot_left(Node<T>*);
    Node<T>* rot_right(Node<T>*);
    Node<T>* rot_left_right(Node<T>*);
    Node<T>* rot_right_left(Node<T>*);

    friend class AVL<T>;
};

// Constructor.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
Node<T>::Node(T val)
    : value(val), left(0), right(0), level(1), balance(0) {}

// Constructor.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, int lev, int bal)
    : value(val), left(le), right(ri), level(lev), balance(bal) {}

// Compara jugadores según el criterio seleccionado.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
int Node<T>::comparar(T jugador1, T jugador2, int criterio) const {

    switch (criterio) { // O(1)
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

    return 0; // O(1)
}

// Compara el registro completo de dos jugadores.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
bool Node<T>::iguales(T jugador1, T jugador2) const {

    return jugador1.getNombre() == jugador2.getNombre() &&
           jugador1.getEquipo() == jugador2.getEquipo() &&
           jugador1.getPosicion() == jugador2.getPosicion() &&
           jugador1.getEdad() == jugador2.getEdad() &&
           jugador1.getAltura() == jugador2.getAltura() &&
           jugador1.getPuntos() == jugador2.getPuntos() &&
           jugador1.getRebotes() == jugador2.getRebotes() &&
           jugador1.getAsistencias() == jugador2.getAsistencias(); // O(1)
}

// Actualiza altura y factor de balance.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
void Node<T>::actualizar() {

    int le = 0, ri = 0; // O(1)

    if (left != 0) {
        le = left->level; // O(1)
    }

    if (right != 0) {
        ri = right->level; // O(1)
    }

    if (le > ri) {
        level = le + 1; // O(1)
    } else {
        level = ri + 1; // O(1)
    }

    balance = le - ri; // O(1)
}

// Inserta un jugador en el árbol.
// Mejor caso: O(1), cuando se inserta como raíz o se encuentra una clave repetida.
// Caso promedio: O(log n).
// Peor caso: O(log n), porque el árbol AVL permanece balanceado.
template <class T>
Node<T>* Node<T>::add(T val, int criterio) {

    int resultado = comparar(val, value, criterio); // O(1)

    if (resultado < 0) {
        if (left != 0) {
            left = left->add(val, criterio); // O(log n)
        } else {
            left = new Node<T>(val); // O(1)
        }
    } else if (resultado > 0) {
        if (right != 0) {
            right = right->add(val, criterio); // O(log n)
        } else {
            right = new Node<T>(val); // O(1)
        }
    } else {
        repetidos.push_back(val); // O(1) amortizado
        return this; // O(1)
    }

    return balance_tree(); // O(1)
}

// Busca una clave en el árbol.
// Mejor caso: O(1), cuando la clave está en la raíz.
// Caso promedio: O(log n).
// Peor caso: O(log n), porque el árbol AVL permanece balanceado.
template <class T>
bool Node<T>::find(T val, int criterio) const {

    int resultado = comparar(val, value, criterio); // O(1)

    if (resultado == 0) {
        return true; // O(1)
    } else if (resultado < 0) {
        return (left != 0 && left->find(val, criterio)); // O(log n)
    } else {
        return (right != 0 && right->find(val, criterio)); // O(log n)
    }
}

// Regresa todos los jugadores que comparten una clave.
// Localizar la clave: O(log n).
// Copiar los jugadores encontrados: O(n).
template <class T>
vector<T> Node<T>::search(T val, int criterio) const {

    int resultado = comparar(val, value, criterio); // O(1)
    vector<T> jugadores; // O(1)

    if (resultado == 0) {
        jugadores.push_back(value); // O(1) amortizado

        // Copia los jugadores que comparten la misma clave
        for (int i = 0; i < repetidos.size(); i++) { // O(n)
            jugadores.push_back(repetidos[i]); // O(1) amortizado
        }
    } else if (resultado < 0) {
        if (left != 0) {
            return left->search(val, criterio); // O(log n)
        }
    } else {
        if (right != 0) {
            return right->search(val, criterio); // O(log n)
        }
    }

    return jugadores; // O(1)
}

// Extrae el nodo con mayor valor del subárbol.
// Mejor caso: O(1), cuando el nodo no tiene hijo derecho.
// Caso promedio: O(log n).
// Peor caso: O(log n), por la altura del árbol AVL.
template <class T>
Node<T>* Node<T>::removeMax(Node<T>*& nodo) {

    if (nodo->right == 0) {
        Node<T>* aux = nodo; // O(1)
        nodo = nodo->left; // O(1)
        aux->left = 0; // O(1)
        return aux; // O(1)
    }

    Node<T>* aux = removeMax(nodo->right); // O(log n)
    nodo = nodo->balance_tree(); // O(1)

    return aux; // O(1)
}

// Elimina un jugador específico.
// Buscar la clave en el árbol: O(log n).
// Buscar un jugador dentro de los repetidos: O(n).
// Rebalancear el camino recorrido: O(log n).
template <class T>
Node<T>* Node<T>::remove(T val, int criterio) {

    int resultado = comparar(val, value, criterio); // O(1)

    if (resultado < 0) {
        if (left != 0) {
            left = left->remove(val, criterio); // O(log n)
        }
    } else if (resultado > 0) {
        if (right != 0) {
            right = right->remove(val, criterio); // O(log n)
        }
    } else {

        bool encontrado = false; // O(1)

        if (iguales(value, val)) { // O(1)
            encontrado = true; // O(1)

            if (!repetidos.empty()) { // O(1)
                value = repetidos[repetidos.size() - 1]; // O(1)
                repetidos.pop_back(); // O(1)
                return this; // O(1)
            }
        } else {
            // Busca el jugador entre los repetidos
            for (int i = 0; i < repetidos.size(); i++) { // O(n)
                if (iguales(repetidos[i], val)) { // O(1)
                    repetidos[i] = repetidos[repetidos.size() - 1]; // O(1)
                    repetidos.pop_back(); // O(1)
                    return this; // O(1)
                }
            }
        }

        if (encontrado) {

            if (left == 0) {
                Node<T>* aux = right; // O(1)
                right = 0; // O(1)
                delete this; // O(1)
                return aux; // O(1)
            }

            if (right == 0) {
                Node<T>* aux = left; // O(1)
                left = 0; // O(1)
                delete this; // O(1)
                return aux; // O(1)
            }

            Node<T>* aux = removeMax(left); // O(log n)

            aux->left = left; // O(1)
            aux->right = right; // O(1)

            left = 0; // O(1)
            right = 0; // O(1)

            delete this; // O(1)

            return aux->balance_tree(); // O(1)
        }
    }

    return balance_tree(); // O(1)
}

// Elimina los nodos hijos.
// Mejor caso: O(1), cuando no existen hijos.
// Caso promedio: O(n).
// Peor caso: O(n), porque se visitan todos los nodos.
template <class T>
void Node<T>::removeChilds() {

    if (left != 0) {
        left->removeChilds(); // O(n)
        delete left; // O(1)
        left = 0; // O(1)
    }

    if (right != 0) {
        right->removeChilds(); // O(n)
        delete right; // O(1)
        right = 0; // O(1)
    }
}

// Recorrido inorder.
// Mejor caso: O(n).
// Caso promedio: O(n).
// Peor caso: O(n).
template <class T>
void Node<T>::inorder(stringstream &aux) const {

    if (left != 0) {
        left->inorder(aux); // O(n)
    }

    if (aux.tellp() != 1) { // O(1)
        aux << " "; // O(1)
    }

    aux << value; // O(1)

    // Agrega los jugadores repetidos
    for (int i = 0; i < repetidos.size(); i++) { // O(n)
        aux << " " << repetidos[i]; // O(1)
    }

    if (right != 0) {
        right->inorder(aux); // O(n)
    }
}

// Recorrido preorder.
// Mejor caso: O(n).
// Caso promedio: O(n).
// Peor caso: O(n).
template <class T>
void Node<T>::preorder(stringstream &aux) const {

    aux << value; // O(1)

    // Agrega los jugadores repetidos
    for (int i = 0; i < repetidos.size(); i++) { // O(n)
        aux << " " << repetidos[i]; // O(1)
    }

    if (left != 0) {
        aux << " "; // O(1)
        left->preorder(aux); // O(n)
    }

    if (right != 0) {
        aux << " "; // O(1)
        right->preorder(aux); // O(n)
    }
}

// Calcula la altura almacenada del árbol.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
int Node<T>::max_depth() {

    actualizar(); // O(1)
    return level; // O(1)
}

// Balancea el árbol.
// Mejor caso: O(1), si no se necesita una rotación.
// Caso promedio: O(1).
// Peor caso: O(1), porque realiza como máximo una rotación simple o doble.
template <class T>
Node<T>* Node<T>::balance_tree() {

    actualizar(); // O(1)

    if (balance > 1) {
        if (left->balance >= 0) { // O(1)
            return rot_right(this); // O(1)
        } else {
            return rot_left_right(this); // O(1)
        }
    }

    if (balance < -1) {
        if (right->balance <= 0) { // O(1)
            return rot_left(this); // O(1)
        } else {
            return rot_right_left(this); // O(1)
        }
    }

    return this; // O(1)
}

// Rotación izquierda.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
Node<T>* Node<T>::rot_left(Node<T>* a) {

    Node<T>* b = a->right; // O(1)

    a->right = b->left; // O(1)
    b->left = a; // O(1)

    a->actualizar(); // O(1)
    b->actualizar(); // O(1)

    return b; // O(1)
}

// Rotación derecha.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
Node<T>* Node<T>::rot_right(Node<T>* a) {

    Node<T>* b = a->left; // O(1)

    a->left = b->right; // O(1)
    b->right = a; // O(1)

    a->actualizar(); // O(1)
    b->actualizar(); // O(1)

    return b; // O(1)
}

// Rotación izquierda-derecha.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
Node<T>* Node<T>::rot_left_right(Node<T>* a) {

    a->left = rot_left(a->left); // O(1)
    return rot_right(a); // O(1)
}

// Rotación derecha-izquierda.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
Node<T>* Node<T>::rot_right_left(Node<T>* a) {

    a->right = rot_right(a->right); // O(1)
    return rot_left(a); // O(1)
}

template <class T>
class AVL {
private:
    Node<T>* root;
    int criterio;

public:
    AVL(int);
    ~AVL();

    bool empty() const;
    void add(T);
    bool find(T) const;
    vector<T> search(T) const;
    void remove(T);
    void removeAll();

    string inorder() const;
    string preorder() const;
};

// Constructor.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
AVL<T>::AVL(int criterio) : root(0), criterio(criterio) {}

// Destructor.
// Mejor caso: O(1), cuando el árbol está vacío.
// Caso promedio: O(n).
// Peor caso: O(n), porque elimina todos los nodos.
template <class T>
AVL<T>::~AVL() {
    removeAll(); // O(n)
}

// Comprueba si está vacío.
// Mejor caso: O(1).
// Caso promedio: O(1).
// Peor caso: O(1).
template <class T>
bool AVL<T>::empty() const {

    return (root == 0); // O(1)
}

// Inserta un jugador.
// Mejor caso: O(1), cuando el árbol está vacío.
// Caso promedio: O(log n).
// Peor caso: O(log n), por la altura del árbol AVL.
template <class T>
void AVL<T>::add(T val) {

    if (root != 0) {
        root = root->add(val, criterio); // O(log n)
    } else {
        root = new Node<T>(val); // O(1)
    }
}

// Busca una clave.
// Mejor caso: O(1), cuando la clave está en la raíz.
// Caso promedio: O(log n).
// Peor caso: O(log n), por la altura del árbol AVL.
template <class T>
bool AVL<T>::find(T val) const {

    if (root != 0) {
        return root->find(val, criterio); // O(log n)
    }

    return false; // O(1)
}

// Busca todos los jugadores de una clave.
// Localizar la clave: O(log n).
// Copiar los jugadores encontrados: O(n).
template <class T>
vector<T> AVL<T>::search(T val) const {

    if (root != 0) {
        return root->search(val, criterio); // O(log n) para localizar la clave
    }

    return vector<T>(); // O(1)
}

// Elimina un jugador.
// Buscar la clave en el árbol: O(log n).
// Buscar un jugador dentro de los repetidos: O(n).
// Rebalancear el camino recorrido: O(log n).
template <class T>
void AVL<T>::remove(T val) {

    if (root != 0) {
        root = root->remove(val, criterio); // O(log n), más la búsqueda O(n) entre repetidos
    }
}

// Elimina todos los nodos.
// Mejor caso: O(1), cuando el árbol está vacío.
// Caso promedio: O(n).
// Peor caso: O(n), porque se libera cada nodo.
template <class T>
void AVL<T>::removeAll() {

    if (root != 0) {
        root->removeChilds(); // O(n)
        delete root; // O(1)
        root = 0; // O(1)
    }
}

// Recorrido inorder.
// Mejor caso: O(n).
// Caso promedio: O(n).
// Peor caso: O(n).
template <class T>
string AVL<T>::inorder() const {

    stringstream aux; // O(1)

    aux << "["; // O(1)

    if (!empty()) {
        root->inorder(aux); // O(n)
    }

    aux << "]"; // O(1)

    return aux.str(); // O(n)
}

// Recorrido preorder.
// Mejor caso: O(n).
// Caso promedio: O(n).
// Peor caso: O(n).
template <class T>
string AVL<T>::preorder() const {

    stringstream aux; // O(1)

    aux << "["; // O(1)

    if (!empty()) {
        root->preorder(aux); // O(n)
    }

    aux << "]"; // O(1)

    return aux.str(); // O(n)
}

#endif /* AVL_H_ */
