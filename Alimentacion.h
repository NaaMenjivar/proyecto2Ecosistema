#ifndef ALIMENTACION_H
#define ALIMENTACION_H

#include <iostream>
#include <string>
using namespace std;

// declarations
class Recurso;
class Criatura;

// Clase base abstracta para estrategias de alimentación
class Alimentacion {
protected:
    string tipoRecursoObjetivo;

public:
    Alimentacion(string tipoRecurso = "");
    virtual ~Alimentacion();

    // heredado de Estrategia
    //virtual bool ejecutar(Criatura* criatura, Criatura* cri) ;

    // Métodos específicos de alimentación
    virtual Recurso* buscarRecurso(Criatura* criatura);
    virtual bool consumirRecurso(Criatura* criatura, Recurso* recurso);
    virtual bool esRecursoCompatible(Recurso* recurso);

    // Getters y setters
    int getRangoDeteccion() const { return -1; }
    string getTipoRecursoObjetivo() const { return tipoRecursoObjetivo; }
    void setRangoDeteccion(int rango) {}
    void setTipoRecursoObjetivo(string tipo) { tipoRecursoObjetivo = tipo; }
    virtual string getTipo() const = 0;

protected:
    // Métodos auxiliares
    int calcularDistancia(int x1, int y1, int x2, int y2);
    bool estaEnRango(Criatura* criatura, Recurso* recurso) {
        return false;
    }
};

#endif // ALIMENTACION_H

