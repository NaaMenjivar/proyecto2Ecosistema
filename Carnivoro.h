#pragma once
#ifndef CARNIVORO_H
#define CARNIVORO_H
#include"Criatura.h"

// Clase Carnívoro
class Carnivoro : public Criatura {
public:
    Carnivoro(int x = 0, int y = 0, int energiaInicial = 120);
    virtual ~Carnivoro();

    virtual void Operacion() override;
    virtual void Update() override;
    virtual Criatura* reproducirse() override;

private:
    void cazarPresa();
};

#endif // CARNIVORO_H
