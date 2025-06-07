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
    DepredaHerbivoro(int rango = 1, int fuerza = 50);
    virtual ~DepredaHerbivoro();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "DepredaHerbivoro"; }

    bool atacarHerbivoro(Criatura* carnivoro, Herbivoro* herbivoro);
    Herbivoro* buscarHerbivoro(Criatura* carnivoro);

    int getFuerzaAtaque() const { return fuerzaAtaque; }
    void setFuerzaAtaque(int fuerza) { fuerzaAtaque = fuerza; }
};

#endif // DEPREDA_HERBIVORO_H