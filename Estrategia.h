#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <iostream>
#include <string>
using namespace std;

// declarations
class Criatura;
class Recurso;

// Clase base abstracta para todas las estrategias
class Estrategia {
public:
    Estrategia();
    virtual ~Estrategia();

    // M�todo virtual puro para ejecutar la estrategia
    virtual bool ejecutar(Criatura* criatura) = 0;

    // M�todo para obtener el tipo de estrategia
    virtual string getTipo() const = 0;
};

#endif // ESTRATEGIA_H

