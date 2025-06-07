#pragma once
#ifndef PLANTA_H
#define PLANTA_H
#include"Recurso.h"

// Clase Agua
class Agua : public Recurso {
public:
    Agua(int x = 0, int y = 0, int valor = 30);
    virtual ~Agua();

    virtual void Operacion() override;
    virtual void Update() override;
    virtual void regenerar() override;

private:
    int pureza;
};


#endif // PLANTA_H