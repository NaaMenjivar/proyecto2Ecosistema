#pragma once
#include "Recurso.h"

class Ecosistema;

class RecursoFactory
{
public:
    RecursoFactory() {};
    virtual ~RecursoFactory() {};
    virtual Recurso* crearRecurso(int x, int y, int valorNutri, Ecosistema* eco, char clima) = 0;
    virtual string getTipoFactory() const = 0;
};

