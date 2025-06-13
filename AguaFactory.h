#pragma once
#include "RecursoFactory.h"
#include "Agua.h"

class AguaFactory:public RecursoFactory
{
public:
    Recurso* crearRecurso(int x, int y, int valorN, Ecosistema* eco, char clima);
    string getTipoFactory() const override;
};

