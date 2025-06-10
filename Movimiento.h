#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <iostream>
#include <string>
using namespace std;

class Criatura;

// Clase base abstracta para estrategias de movimiento
class Movimiento {
protected:
    int distanciaMaxima;

public:
    Movimiento(int distancia = 1);
    virtual ~Movimiento();

    // heredado de Estrategia
    virtual bool ejecutar(Criatura* criatura) = 0;

    // Métodos específicos de movimiento
    virtual bool moverA(Criatura* criatura, int x, int y);
    virtual bool esMovimientoValido(int x, int y, Criatura* criatura);

    // Getters y setters
    int getDistanciaMaxima() const { return distanciaMaxima; }
    void setDistanciaMaxima(int distancia) { distanciaMaxima = distancia; }
    virtual string getTipo() const = 0;

protected:
    // Métodos auxiliares
    // Protected porque son auxiliares
    int calcularDistancia(int x1, int y1, int x2, int y2);
    bool estaDentroDelMapa(int x, int y);
};

#endif // MOVIMIENTO_H
