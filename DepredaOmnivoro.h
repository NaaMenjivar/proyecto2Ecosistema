#pragma once
#ifndef DEPREDA_OMNIVORO_H
#define  DEPREDA_OMNIVORO_H

#include"Alimentacion.h"

class Herbivoro;
class Omnivoro;

class DepredaOmnivoro : public Alimentacion {
private:
    int fuerzaAtaque;

public:
    DepredaOmnivoro(int rango = 1, int fuerza = 40);
    virtual ~DepredaOmnivoro();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "DepredaOmnivoro"; }

    bool atacarOmnivoro(Criatura* carnivoro, Omnivoro* omnivoro);
    Omnivoro* buscarOmnivoro(Criatura* carnivoro);

    int getFuerzaAtaque() const { return fuerzaAtaque; }
    void setFuerzaAtaque(int fuerza) { fuerzaAtaque = fuerza; }
};


#endif // DEPREDA_OMNIVORO_H