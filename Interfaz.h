
#ifndef INTERFAZ_H
#define INTERFAZ_H
#pragma once
#include"Ecosistema.h"

class Interfaz{
public:
	static int mostrarMenuPrincipal();
	static void mostrarMenuCrearCriatura();
	static void mostrarMenuClima();
	static void mostrarEstadoEcosistema(Ecosistema* eco);
	static void mostrarEstadoSimulacion(Ecosistema* eco, int tick);
	static void poblarEcosistemaAutomaticamente(Ecosistema* eco);
	static void crearCriatura(Ecosistema* eco);
	static void crearRecurso(Ecosistema* eco);
	static void cambiarClima(Ecosistema* eco);
	static void mostrarEstadoEcosis(Ecosistema* eco);
	static void simulacionPorTicks(Ecosistema* eco);
};

#endif // INTERFAZ_H
