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

#ifndef FABRICA_ELEMENTOS_H
#define FABRICA_ELEMENTOS_H

#include "Criatura.h"
#include "Recurso.h"
#include <string>

// Clase base abstracta para las fábricas (Abstract Factory Pattern)
class FabricaElementos {
public:
    virtual ~FabricaElementos();
    virtual Criatura* crearCriatura(const string& tipo, int x, int y) = 0;
    virtual Recurso* crearRecurso(const string& tipo, int x, int y) = 0;
};

// Fábrica especializada para crear criaturas (Factory Method Pattern)
class FabricaCriaturas : public FabricaElementos {
public:
    virtual ~FabricaCriaturas();
    virtual Criatura* crearCriatura(const string& tipo, int x, int y) override;
    virtual Recurso* crearRecurso(const string& tipo, int x, int y) override;

    // Métodos específicos para crear cada tipo de criatura
    Criatura* crearHerbivoro(int x, int y);
    Criatura* crearCarnivoro(int x, int y);
    Criatura* crearOmnivoro(int x, int y);
};

// Fábrica especializada para crear recursos (Factory Method Pattern)
class FabricaRecursos : public FabricaElementos {
public:
    virtual ~FabricaRecursos();
    virtual Criatura* crearCriatura(const string& tipo, int x, int y) override;
    virtual Recurso* crearRecurso(const string& tipo, int x, int y) override;

    // Métodos específicos para crear cada tipo de recurso
    Recurso* crearAgua(int x, int y);
    Recurso* crearCarne(int x, int y);
    Recurso* crearPlanta(int x, int y);
};

#endif // FABRICA_ELEMENTOS_H