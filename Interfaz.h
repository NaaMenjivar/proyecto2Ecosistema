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
#ifndef INTERFAZ_H
#define INTERFAZ_H
#pragma once
#include"Ecosistema.h"
#include "Excepcion.h"

class Interfaz{
public:
	//Menus
	static int mostrarMenuPrincipal();
	static void mostrarMenuCrearCriatura();
	static void mostrarMenuCrearRecurso();
	static void mostrarMenuClima();
	static void mostrarEstadoEcosistema(Ecosistema* eco);
	static void mostrarEstadoSimulacion(Ecosistema* eco, int tick);
	static void poblarEcosistemaAutomaticamente(Ecosistema* eco);

	//Manejo de excepciones con ingreso de operadores
	static int ingresarInt(int);
	static int ingresarInt(int, int);
	static string ingresarString();
	static char ingresarChar();

	//Metodos de creacion
	static void crearCriatura(Ecosistema* eco);
	static void crearRecurso(Ecosistema* eco);
	static void cambiarClima(Ecosistema* eco);

	//Metodo reportes
	static void mostrarEstadoEcosis(Ecosistema* eco);

	//Simulacion
	static void simulacionPorTicks(Ecosistema* eco);

	//Mensajes
	static void GuardadoArchivos(Ecosistema* eco);
	static void LecturaArchivos(Ecosistema* eco);
};

#endif // INTERFAZ_H
