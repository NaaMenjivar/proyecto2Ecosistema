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
#ifndef CRIATURAFACTORY_H
#define CRIATURAFACTORY_H
#include "Criatura.h"

class Ecosistema;

class CriaturaFactory
{
public:
    CriaturaFactory() {};
    virtual ~CriaturaFactory() {};
    virtual Criatura* crearCriatura(int x, int y, int energia, Ecosistema* eco, char clima) = 0;
    virtual string getTipoFactory() const = 0;
};

#endif