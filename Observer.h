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
#ifndef OBSERVER_H
#define OBSERVER_H
#include<iostream>
#include<string>
#include<sstream>
#include <cstdlib>
#include <ctime>


using namespace std;

class Matriz;

class Ecosistema;

//EL observer a las clases dentro del ecosistema(Criatura/Recurso)
//Estas son las que van a recibir los cambios del ecosistema
class Observer {
protected:
	char clima;  // Dia = D / Tarde = T / Noche = N
	Ecosistema* eco;

public:
	Observer(Ecosistema* e, char cli) {
		clima = cli; 
		eco = e;
	}
	virtual~Observer() {}

	virtual void Operacion(Matriz* mat) = 0;
	virtual void Update() = 0;
	virtual char getSimbolo() const = 0; 
	void actualizarClima(char cli) { clima = cli; }
protected:
	char getClima() { return clima; }
	Ecosistema* getEcosistema() { return eco; }
};


#endif // OBSERVER_H