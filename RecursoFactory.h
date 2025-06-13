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
#ifndef RECURSOFACTORY_H
#define RECURSOFACTORY_H
#include "Recurso.h"

class Ecosistema;

class RecursoFactory
{
public:
    RecursoFactory() {};
    virtual ~RecursoFactory() {};
    virtual Recurso* crearRecurso(int x, int y, int valorNutri, Ecosistema* eco, char clima) = 0;
    virtual string getTipoFactory() const = 0;
};

#endif