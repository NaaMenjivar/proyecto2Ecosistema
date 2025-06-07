#pragma once
#ifndef HUIDA_H
#define  HUIDA_H
#include"Movimiento.h"

// Estrategia de huida para herbívoros y omnívoros
class Huida : public Movimiento {
private:
    int rangoPeligro;

public:
    Huida(int distancia = 2, int rango = 3);
    virtual ~Huida();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "Huida"; }

    bool hayPeligroCerca(Criatura* criatura);
    void huirDePeligro(Criatura* criatura);

    int generarDireccionAleatoria();

    int getRangoPeligro() const { return rangoPeligro; }
    void setRangoPeligro(int rango) { rangoPeligro = rango; }
};

#endif // HUIDA_H


