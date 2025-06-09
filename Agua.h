#pragma once
#ifndef AGUA_H
#define AGUA_H
#include"Recurso.h"

// Clase Agua
class Agua : public Recurso {
public:
    Agua(int x = 0, int y = 0, int valor = 50, Ecosistema* e = NULL, char cli = 'i');

    virtual ~Agua();

    virtual void Operacion(Matriz* mat) override;
    virtual void Update() override;
    virtual void regenerar() override;

    virtual void Guardar(ofstream& arch)override;
    static Recurso* Lectura(ifstream& arch, Ecosistema* eco);

    void setPureza(int p) { pureza = p; }

private:
    int pureza;
};


#endif // AGUA_H