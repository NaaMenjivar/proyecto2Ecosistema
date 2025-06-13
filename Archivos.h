#pragma once
#include"ColeccionT.h"
#include"Criatura.h"
#include"Recurso.h"
#include"Carnivoro.h"
#include"Herbivoro.h"
#include"Omnivoro.h"
#include"Agua.h"
#include"Carne.h"
#include"Planta.h"

class GestionArchivos {
public:
	static void GuardarCriaturas(ColeccionT<Criatura>* lista, string& nomArch);
	static void LecturaCriaturas(ColeccionT<Criatura>* lista, string& nomArch,Ecosistema* eco);

	static void GuardarRecursos(ColeccionT<Recurso>* lista, string& nomArch);
	static void LecturaRecursos(ColeccionT<Recurso>* lista, string& nomArch, Ecosistema* eco);

};

