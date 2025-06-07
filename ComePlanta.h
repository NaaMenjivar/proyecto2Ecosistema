#pragma once
#ifndef COME_PLANTA_H
#define  COME_PLANTA_H
#include"Alimentacion.h"

// declarations
class Herbivoro;
class Omnivoro;

// Estrategia para comer plantas
class ComePlanta : public Alimentacion {
public:
    ComePlanta(int rango = 2);
    virtual ~ComePlanta();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "ComePlanta"; }
    virtual bool esRecursoCompatible(Recurso* recurso) override;
};

#endif // COME_PLANTA_H