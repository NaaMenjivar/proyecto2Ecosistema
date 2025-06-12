#ifndef CONTROLADORA_H
#define CONTROLADORA_H
#pragma once
#include"Interfaz.h"

class Controladora{
private:
	Ecosistema* eco;

public:
	Controladora();
	virtual ~Controladora();

	void case0();

	void poblarEcosistemaAutomticamente();
	void crearCriaturaIndividual();
	void crearRecursoIndividual();
	void cambiarClima();
	void MostrarEstadodelEcosistema();
	void simulaci�nPorTicksInteractiva();
};

#endif // CONTROLADORA_H

