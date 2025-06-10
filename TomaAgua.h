#pragma once
#ifndef TOMA_AGUA_H
#define  TOMA_AGUA_H
#include"Alimentacion.h"

// declarations
class Herbivoro;
class Omnivoro;
class Carnivoro;


// Estrategia para tomar agua
class TomaAgua : public Alimentacion {
public:
    TomaAgua();
    virtual ~TomaAgua();

    bool ejecutar(Criatura* criatura, Recurso* rec);
    virtual string getTipo() const override { return "TomaAgua"; }
    virtual bool esRecursoCompatible(Recurso* recurso) override;
};

#endif // TOMA_AGUA_H