/* -------------------------------------------------------------------+
* |
* (c) 2025 |
* EIF204 - Programación 2 |
* 1er ciclo 2025 |
* NRC 9999 – Grupo 00 |
* Proyecto 2 |
* |
* 1-1977-0345; Menjívar Ramírez, Naara |
* 1-1905-0975; Chaves Salazar, Sebastián |
* A-0015-0163; Briones Rocha, Jordan |
* |
* versión 1.0.0 2025-06-01 |
* |
* -------------------------------------------------------------------+
*/
#ifndef ECOSISTEMA_H
#define  ECOSISTEMA_H
#include"ColeccionT.h"
#include"Criatura.h"
#include"Recurso.h"
#include "Matriz.h"
#include"Archivos.h"


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
	void simularxTicks(int cantTicks);
	void poblarEcosistema(int numCarnivoros, int numHerbivoros, int numOmnivoros);
	void eliminarMuert();

	//METODOS COLECCION CRIATURAS
	void agregarC(Criatura* elemento);
	bool eliminarC(int indice);
	bool eliminarC(Criatura* elemento);
	Criatura* obtenerC(int indice) const;
	int buscarC(Criatura* elemento) const;

	int getTamanioC () const;
	int getCapacidadC() const;
	int getCantMatCriaturas();
	int getCantMatRecursos();
	bool estaVaciaC() const;

	void limpiarC();

	void GuardarCriaturas(string arch);
	void LecturaCriaturas(string arch);

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


	void GuardarRecrusos(string arch);
	void LecturaRecursos(string arch);

	//METODOS MATRIZ

	void insertaMatriz(Observer* cri, int posX, int posY);
};

#endif // ECOSISTEMA_H

