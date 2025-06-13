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
    DepredaOmnivoro();
    DepredaOmnivoro(int fuerza);
    ~DepredaOmnivoro();
    bool ejecutar(Criatura* criatura, Criatura* om);
    string getTipo() const override;
private:
    bool atacarOmnivoro(Criatura* carnivoro, Omnivoro* omnivoro);
};


#endif // DEPREDA_OMNIVORO_H