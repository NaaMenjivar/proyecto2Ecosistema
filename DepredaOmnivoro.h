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
    DepredaOmnivoro(int fuerza = 100);
    virtual ~DepredaOmnivoro();

    bool ejecutar(Criatura* criatura, Criatura* om) ;
    virtual string getTipo() const override { return "DepredaOmnivoro"; }

    bool atacarOmnivoro(Criatura* carnivoro, Omnivoro* omnivoro);

    int getFuerzaAtaque() const { return fuerzaAtaque; }
    void setFuerzaAtaque(int fuerza) { fuerzaAtaque = fuerza; }
};


#endif // DEPREDA_OMNIVORO_H