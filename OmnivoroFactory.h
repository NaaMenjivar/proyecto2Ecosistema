#pragma once
#include "CriaturaFactory.h"
#include "Omnivoro.h"

class OmnivoroFactory : public CriaturaFactory {
public:
    Criatura* crearCriatura(int x, int y, int energia, Ecosistema* eco, char clima) override;
    string getTipoFactory() const override;
};

