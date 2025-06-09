#pragma once
#ifndef PLANTA_H
#define PLANTA_H
#include"Recurso.h"

// Clase Planta
class Planta : public Recurso {
public:
    Planta(int x = 0, int y = 0, int valor = 50, Ecosistema* e = NULL, char cli = 'i');
    virtual ~Planta();

    virtual void Operacion(Matriz* mat) override;
    virtual void Update() override;
    virtual void regenerar() override;

    virtual void Guardar(ofstream& arch)override;
    static Recurso* Lectura(ifstream& arch, Ecosistema* eco);

    void setNivCrec(int n) { nivelCrecimiento = n; }

private:
    int nivelCrecimiento;
    void crecer();
};

#endif // PLANTA_H