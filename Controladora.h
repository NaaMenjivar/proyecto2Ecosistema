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
	void simulaciónPorTicksInteractiva();
	void GuardarArchivos();
	void lecturaArchivos();
};

#endif // CONTROLADORA_H

