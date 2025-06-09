#pragma once
#ifndef ECOSISTEMA_H
#define  ECOSISTEMA_H
#include"ColeccionT.h"
#include"Criatura.h"
#include"Recurso.h"
#include "Matriz.h"


class FactoryManager;

class Ecosistema{  //SUJETO (PATRON OBSERVER)
private:
	//Matriz dinamica de objetos observer
	char clima;
	ColeccionT<Criatura>* colC;
	ColeccionT<Recurso>* colR;
	FactoryManager* factoryManager;
	Matriz* matriz;
public:
	Ecosistema();
	virtual~Ecosistema();

	//GETS Y SETS CLIMA
	char getClima();
	void setClima(char cli); //este mismo metodo utiliza el notify para notificar a los observadores (Criaturas y Recursos)
	
	//Notify --- MATRIZ
	void notify();

	// METODOS FACTORY
	Criatura* crearCriatura(const string & tipo, int x, int y, int energia = 100);
	Criatura* crearCarnivoro(int x, int y, int energia = 120);
	Criatura* crearHerbivoro(int x, int y, int energia = 100);
	Criatura* crearOmnivoro(int x, int y, int energia = 110);
	Recurso* crearRecurso(const string& tipo, int x, int y, int valorN = 100);
	Recurso* crearAgua(int x, int y, int valorN = 120);
	Recurso* crearPlanta(int x, int y, int valorN = 110);
	Recurso* crearCarne(int x, int y, int valorN = 115);

	//METODOS DE SIMULACION
	void simularCiclo();
	void poblarEcosistema(int numCarnivoros, int numHerbivoros, int numOmnivoros);

	//METODOS COLECCION CRIATURAS
	void agregarC(Criatura* elemento);
	bool eliminarC(int indice);
	bool eliminarC(Criatura* elemento);
	Criatura* obtenerC(int indice) const;
	int buscarC(Criatura* elemento) const;

	int getTamanioC () const;
	int getCapacidadC() const;
	bool estaVaciaC() const;

	void limpiarC();
	//GUARDADO
	//LECTURA


	//METODOS COLECCION RECURSOS..

	void agregarR(Recurso* elemento);
	bool eliminarR(int indice);
	bool eliminarR(Recurso* elemento);
	Recurso* obtenerR(int indice) const;
	int buscarR(Recurso* elemento) const;

	int getTamanioR() const;
	int getCapacidadR() const;
	bool estaVaciaR() const;

	void limpiarR();
	//GUARDADO
	//LECTURA


	//METODOS DE LA MATRIZ.....

};

#endif // ECOSISTEMA_H

