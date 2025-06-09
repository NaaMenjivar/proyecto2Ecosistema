#pragma once
#ifndef DEPREDACION_H
#define  DEPREDACION_H
#include"Movimiento.h"

// Estrategia de depredación (movimiento hacia presas)
class Depredacion : public Movimiento {
private:
    int rangoDeteccion;

public:
    Depredacion(int distancia = 2, int rango = 4);
    virtual ~Depredacion();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "Depredacion"; }

    Criatura* buscarPresa(Criatura* depredador);
    bool moverHaciaPresa(Criatura* depredador, Criatura* presa);

    int getRangoDeteccion() const { return rangoDeteccion; }
    void setRangoDeteccion(int rango) { rangoDeteccion = rango; }
};

#endif // DEPREDACION_H