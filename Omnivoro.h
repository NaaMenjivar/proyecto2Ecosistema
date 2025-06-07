#pragma once
#ifndef OMNIVORO_H
#define OMNIVORO_H
#include"Criatura.h"

// Clase Omnívoro
class Omnivoro : public Criatura {
public:
    Omnivoro(int x = 0, int y = 0, int energiaInicial = 100);
    virtual ~Omnivoro();

    virtual void Operacion() override;
    virtual void Update() override;
    virtual Criatura* reproducirse() override;

private:
    void buscarAlimento();
};

#endif // OMNIVORO_H