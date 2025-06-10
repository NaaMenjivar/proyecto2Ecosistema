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
    ComePlanta();
    virtual ~ComePlanta();

    bool ejecutar(Criatura* criatura);
    virtual string getTipo() const override { return "ComePlanta"; }
    virtual bool esRecursoCompatible(Recurso* recurso) override;
};

#endif // COME_PLANTA_H