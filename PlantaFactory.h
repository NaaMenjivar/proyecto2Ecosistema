#pragma once
#include "RecursoFactory.h"
#include "Planta.h"

class PlantaFactory :public RecursoFactory
{
public:
    Recurso* crearRecurso(int x, int y, int valorN, Ecosistema* eco, char clima);
    string getTipoFactory() const override;
};
