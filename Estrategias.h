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

#ifndef ESTRATEGIAS_H
#define ESTRATEGIAS_H

#include <iostream>
using namespace std;

// Forward declarations
class Criatura;
class Ecosistema;

// Estrategia base para comportamientos (Strategy Pattern)
class Estrategia {
public:
    virtual ~Estrategia();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) = 0;
};

// Estrategias de Movimiento
class Movimiento : public Estrategia {
public:
    virtual ~Movimiento();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) override = 0;
};

class CambiaDireccion : public Movimiento {
public:
    virtual ~CambiaDireccion();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) override;
private:
    int calcularNuevaDireccion();
};

class Huida : public Movimiento {
public:
    virtual ~Huida();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) override;
private:
    void buscarRutaSegura(Criatura* criatura, Ecosistema* ecosistema);
};

// Estrategias de Alimentación
class Alimentacion : public Estrategia {
public:
    virtual ~Alimentacion();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) override = 0;
};

class ComePlanta : public Alimentacion {
public:
    virtual ~ComePlanta();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) override;
private:
    void buscarPlantaCercana(Criatura* criatura, Ecosistema* ecosistema);
};

class TomaAgua : public Alimentacion {
public:
    virtual ~TomaAgua();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) override;
private:
    void buscarAguaCercana(Criatura* criatura, Ecosistema* ecosistema);
};

class DepredaHerbivoro : public Alimentacion {
public:
    virtual ~DepredaHerbivoro();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) override;
private:
    void cazarHerbivoro(Criatura* criatura, Ecosistema* ecosistema);
};

class DepredaOmnivoro : public Alimentacion {
public:
    virtual ~DepredaOmnivoro();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) override;
private:
    void cazarOmnivoro(Criatura* criatura, Ecosistema* ecosistema);
};

class Depredacion : public Alimentacion {
public:
    virtual ~Depredacion();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) override;
private:
    void buscarPresa(Criatura* criatura, Ecosistema* ecosistema);
};

// Estrategia de Reproducción
class Reproduccion : public Estrategia {
public:
    virtual ~Reproduccion();
    virtual void ejecutar(Criatura* criatura, Ecosistema* ecosistema) override;
private:
    bool cumpleCondicionesReproduccion(Criatura* criatura);
    void realizarReproduccion(Criatura* criatura, Ecosistema* ecosistema);
};

#endif // ESTRATEGIAS_H