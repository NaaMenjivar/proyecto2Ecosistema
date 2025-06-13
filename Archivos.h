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
#ifndef ARCHIVOS_H
#define ARCHIVOS_H
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

#endif 