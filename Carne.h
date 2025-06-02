#pragma once
#ifndef CARNE_H
#define CARNE_H
#include"Recurso.h"

// Clase Carne
class Carne : public Recurso {
public:
    Carne(int x = 0, int y = 0, int valor = 80);
    virtual ~Carne();

    virtual void Operacion() override;
    virtual void Update() override;

private:
    int tiempoDescomposicion;
    void descomponer();
};

#endif // CARNE_H