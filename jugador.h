/*
 * jugador.h
 *
 *  Created on: 20/09/2026
 *      Author: Julio César Hdez.
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Jugador {
private:
	string nombre;
	string equipo;
	string posicion;
	int edad;
	int altura;
	double puntos;
	double rebotes;
	double asistencias;

public:
	Jugador();
	Jugador(string, string, string, int, int, double, double, double);

	string getNombre() const;
	string getEquipo() const;
	string getPosicion() const;
	int getEdad() const;
	int getAltura() const;
	double getPuntos() const;
	double getRebotes() const;
	double getAsistencias() const;

	string toString() const;
};

Jugador::Jugador() {
	nombre = "";
	equipo = "";
	posicion = "";
	edad = 0;
	altura = 0;
	puntos = 0;
	rebotes = 0;
	asistencias = 0;
}

Jugador::Jugador(string nombre, string equipo, string posicion,
				 int edad, int altura, double puntos,
				 double rebotes, double asistencias) {

	this->nombre = nombre;
	this->equipo = equipo;
	this->posicion = posicion;
	this->edad = edad;
	this->altura = altura;
	this->puntos = puntos;
	this->rebotes = rebotes;
	this->asistencias = asistencias;
}

string Jugador::getNombre() const {
	return nombre;
}

string Jugador::getEquipo() const {
	return equipo;
}

string Jugador::getPosicion() const {
	return posicion;
}

int Jugador::getEdad() const {
	return edad;
}

int Jugador::getAltura() const {
	return altura;
}

double Jugador::getPuntos() const {
	return puntos;
}

double Jugador::getRebotes() const {
	return rebotes;
}

double Jugador::getAsistencias() const {
	return asistencias;
}

string Jugador::toString() const {
	stringstream aux;

	aux << nombre << "\t"
		<< equipo << "\t"
		<< posicion << "\t"
		<< edad << "\t"
		<< altura << "\t"
		<< puntos << "\t"
		<< rebotes << "\t"
		<< asistencias;

	return aux.str();
}

#endif /* JUGADOR_H_ */
