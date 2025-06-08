#ifndef OBSERVER_H
#define OBSERVER_H
#include<iostream>
#include<string>
#include<sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

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
		//eco->inserta(this)   //----------metodo a desarrollar en el sujeto
	}
	virtual~Observer() {}

	virtual void Update() = 0;

protected:
	char getClima() { return clima; }
	Ecosistema* getEcosistema() { return eco; }
};


#endif // OBSERVER_H