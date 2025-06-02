#pragma once
#ifndef HERBIVORO_H
#define HERBIVORO_H
#include"Criatura.h"

// Clase Herbívoro
class Herbivoro : public Criatura {
public:
    Herbivoro(int x = 0, int y = 0, int energiaInicial = 80);
    virtual ~Herbivoro();

    virtual void Operacion() override;
    virtual void Update() override;
    virtual Criatura* reproducirse() override;

private:
    void buscarPlantas();
};

#endif // HERBIVORO_H