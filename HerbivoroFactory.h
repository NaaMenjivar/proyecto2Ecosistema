#pragma once
#include "CriaturaFactory.h"
#include "Herbivoro.h"

class HerbivoroFactory : public CriaturaFactory {
public:
    Criatura* crearCriatura(int x, int y, int energia, Ecosistema* eco, char clima) override;
    string getTipoFactory() const override;
};

