#pragma once
#ifndef CAMBIA_DIRECCION_H
#define  CAMBIA_DIRECCION_H
#include"Movimiento.h"

// Estrategia de cambio de dirección aleatorio
class CambiaDireccion : public Movimiento {
public:
    CambiaDireccion(int distancia = 1);
    virtual ~CambiaDireccion();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "CambiaDireccion"; }

private:
    void moverAleatoriamente(Criatura* criatura);
    int generarDireccionAleatoria();
};

#endif // CAMBIA_DIRECCION_H