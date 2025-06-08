#pragma once
#include "Criatura.h"

class Ecosistema;

class CriaturaFactory
{
public:
    virtual ~CriaturaFactory() {};
    virtual Criatura* crearCriatura(int x, int y, int energia, Ecosistema* eco, char clima) = 0;
    virtual string getTipoFactory() const = 0;
};

