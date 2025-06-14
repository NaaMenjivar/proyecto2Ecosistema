#include "Controladora.h"

Controladora::Controladora(){
	eco = new Ecosistema();
}
Controladora::~Controladora(){
	if (eco)delete eco;
}


void Controladora::case0(){
	int op;
	srand(static_cast<unsigned int>(time(nullptr)));
	do {
		op = Interfaz::mostrarMenuPrincipal();
		switch (op) {
		case 1: poblarEcosistemaAutomticamente();break;
		case 2: crearCriaturaIndividual(); break;
		case 3: crearRecursoIndividual(); break;
		case 4: cambiarClima(); break;
		case 5: MostrarEstadodelEcosistema(); break;
		case 6: simulaciónPorTicksInteractiva(); break;
		case 7: GuardarArchivos(); break;
		case 8: lecturaArchivos(); break;
		case 9: cout << "Gracias por su uso" << endl; break;
		default: break;
		};
	} while (op != 9);
}

void Controladora::poblarEcosistemaAutomticamente() { Interfaz::poblarEcosistemaAutomaticamente(eco); }
void Controladora::crearCriaturaIndividual() { Interfaz::crearCriatura(eco); }
void Controladora::crearRecursoIndividual() { Interfaz::crearRecurso(eco); }
void Controladora::cambiarClima() { Interfaz::cambiarClima(eco); }
void Controladora::MostrarEstadodelEcosistema() { Interfaz::mostrarEstadoEcosis(eco); }
void Controladora::simulaciónPorTicksInteractiva() { Interfaz::simulacionPorTicks(eco); }
void Controladora::GuardarArchivos() { Interfaz::GuardadoArchivos(eco); }
void Controladora::lecturaArchivos() { Interfaz::LecturaArchivos(eco); }