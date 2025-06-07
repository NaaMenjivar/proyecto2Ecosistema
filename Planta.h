#pragma once
#ifndef PLANTA_H
#define PLANTA_H
#include"Recurso.h"

// Clase Planta
class Planta : public Recurso {
public:
    Planta(int x = 0, int y = 0, int valor = 60);
    virtual ~Planta();

    virtual void Operacion() override;
    virtual void Update() override;
    virtual void regenerar() override;

private:
    int nivelCrecimiento;
    void crecer();
};

#endif // PLANTA_H