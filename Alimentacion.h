#ifndef ALIMENTACION_H
#define ALIMENTACION_H

#include "Estrategia.h"

// declarations
class Recurso;

// Clase base abstracta para estrategias de alimentación
class Alimentacion : public Estrategia {
protected:
    int rangoDeteccion;
    string tipoRecursoObjetivo;

public:
    Alimentacion(int rango = 2, string tipoRecurso = "");
    virtual ~Alimentacion();

    // heredado de Estrategia
    virtual bool ejecutar(Criatura* criatura) = 0;

    // Métodos específicos de alimentación
    virtual Recurso* buscarRecurso(Criatura* criatura);
    virtual bool consumirRecurso(Criatura* criatura, Recurso* recurso);
    virtual bool esRecursoCompatible(Recurso* recurso);

    // Getters y setters
    int getRangoDeteccion() const { return rangoDeteccion; }
    string getTipoRecursoObjetivo() const { return tipoRecursoObjetivo; }
    void setRangoDeteccion(int rango) { rangoDeteccion = rango; }
    void setTipoRecursoObjetivo(string tipo) { tipoRecursoObjetivo = tipo; }

protected:
    // Métodos auxiliares
    int calcularDistancia(int x1, int y1, int x2, int y2);
    bool estaEnRango(Criatura* criatura, Recurso* recurso);
};

#endif // ALIMENTACION_H

