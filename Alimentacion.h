/* -------------------------------------------------------------------+
* |
* (c) 2025 |
* EIF204 - Programaci�n 2 |
* 1er ciclo 2025 |
* NRC 9999 � Grupo 00 |
* Proyecto 2 |
* |
* 1-1977-0345; Menj�var Ram�rez, Naara |
* 1-1905-0975; Chaves Salazar, Sebasti�n |
* A-0015-0163; Briones Rocha, Jordan |
* |
* versi�n 1.0.0 2025-06-01 |
* |
* -------------------------------------------------------------------+
*/
#ifndef ALIMENTACION_H
#define ALIMENTACION_H

#include <iostream>
#include <string>
using namespace std;

// declarations
class Recurso;
class Criatura;

// Clase base abstracta para estrategias de alimentaci�n
class Alimentacion {
protected:
    string tipoRecursoObjetivo;

public:
    Alimentacion(string tipoRecurso = "");
    virtual ~Alimentacion();

    // M�todos espec�ficos de alimentaci�n
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
    // M�todos auxiliares
    int calcularDistancia(int x1, int y1, int x2, int y2);
    bool estaEnRango(Criatura* criatura, Recurso* recurso) {
        return false;
    }
};

#endif // ALIMENTACION_H

