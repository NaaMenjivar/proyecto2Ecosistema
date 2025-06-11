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
    DepredaHerbivoro();
    DepredaHerbivoro(int fuerza);
    ~DepredaHerbivoro();
    bool ejecutar(Criatura* criatura, Criatura* her);
    string getTipo() const override;
private:
    bool atacarHerbivoro(Criatura* carnivoro, Herbivoro* herbivoro);
};

#endif // DEPREDA_HERBIVORO_H