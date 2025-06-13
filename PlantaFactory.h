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
#ifndef PLANTAFACTORY_H
#define PLANTAFACTORY_H
#include "RecursoFactory.h"
#include "Planta.h"

class PlantaFactory :public RecursoFactory
{
public:
    Recurso* crearRecurso(int x, int y, int valorN, Ecosistema* eco, char clima);
    string getTipoFactory() const override;
};

#endif