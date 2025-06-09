#pragma once
#ifndef CARNE_H
#define CARNE_H
#include"Recurso.h"

// Clase Carne
class Carne : public Recurso {
public:
    Carne(int x = 0, int y = 0, int valor = 80, Ecosistema* eco = NULL, char cli = 'i');
    virtual ~Carne();

    virtual void Operacion() override;
    virtual void Update() override;

    virtual void Guardar(ofstream& arch)override;
    static Recurso* Lectura(ifstream& arch, Ecosistema* eco);

    void setTiempoDescomposicion(int t) { tiempoDescomposicion = t; }

private:
    int tiempoDescomposicion;
    void descomponer();
};

#endif // CARNE_H