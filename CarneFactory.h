#pragma once
#include "RecursoFactory.h"
#include "Carne.h"

class CarneFactory :public RecursoFactory
{
public:
    Recurso* crearRecurso(int x, int y, int valorN, Ecosistema* eco, char clima);
    string getTipoFactory() const override; 
};
