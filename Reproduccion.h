#pragma once
#ifndef REPRODUCCION_H
#define  REPRODUCCION_H
#include <iostream>
#include <string>
using namespace std;

class Criatura;
// Estrategia de reproducción
class Reproduccion {
private:
    int energiaMinima;
    int edadMinima;

public:
    Reproduccion(int energiaMin, int edadMin);
    virtual ~Reproduccion();
    bool ejecutar(Criatura* c1, Criatura* c2);
    string getTipo() const;
};

#endif // REPRODUCCION_H