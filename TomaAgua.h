#pragma once
#ifndef TOMA_AGUA_H
#define  TOMA_AGUA_H
#include"Alimentacion.h"

// declarations
class Herbivoro;
class Omnivoro;


// Estrategia para tomar agua
class TomaAgua : public Alimentacion {
public:
    TomaAgua(int rango = 3);
    virtual ~TomaAgua();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "TomaAgua"; }
    virtual bool esRecursoCompatible(Recurso* recurso) override;
};

#endif // TOMA_AGUA_H