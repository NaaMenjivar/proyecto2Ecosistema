#pragma once
#ifndef DEPREDA_HERBIVORO_H
#define  DEPREDA_HERBIVORO_H
#include"Alimentacion.h"

class Herbivoro;
class Omnivoro;

class DepredaHerbivoro : public Alimentacion {
private:
    int fuerzaAtaque;

public:
    DepredaHerbivoro(int fuerza = 50);
    virtual ~DepredaHerbivoro();

    bool ejecutar(Criatura* criatura,Criatura* her);
    virtual string getTipo() const override { return "DepredaHerbivoro"; }

    bool atacarHerbivoro(Criatura* carnivoro, Herbivoro* herbivoro);

    int getFuerzaAtaque() const { return fuerzaAtaque; }
    void setFuerzaAtaque(int fuerza) { fuerzaAtaque = fuerza; }
};

#endif // DEPREDA_HERBIVORO_H