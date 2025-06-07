#pragma once
#ifndef REPRODUCCION_H
#define  REPRODUCCION_H
#include"Estrategia.h"

// Estrategia de reproducción
class Reproduccion : public Estrategia {
private:
    int energiaMinima;
    int edadMinima;
    int rangoPareja;

public:
    Reproduccion(int energiaMin = 150, int edadMin = 10, int rango = 2);
    virtual ~Reproduccion();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "Reproduccion"; }

    bool puedeReproducirse(Criatura* criatura);
    Criatura* buscarPareja(Criatura* criatura);
    bool intentarReproduccion(Criatura* criatura, Criatura* pareja);

    // Getters y setters
    int getEnergiaMinima() const { return energiaMinima; }
    int getEdadMinima() const { return edadMinima; }
    int getRangoPareja() const { return rangoPareja; }
    void setEnergiaMinima(int energia) { energiaMinima = energia; }
    void setEdadMinima(int edad) { edadMinima = edad; }
    void setRangoPareja(int rango) { rangoPareja = rango; }

private:
    bool sonCompatibles(Criatura* criatura1, Criatura* criatura2);
    int calcularDistancia(int x1, int y1, int x2, int y2);
};

#endif // REPRODUCCION_H