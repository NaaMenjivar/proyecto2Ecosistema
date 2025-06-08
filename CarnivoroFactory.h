#pragma once
#include "CriaturaFactory.h"
#include "Carnivoro.h"

class CarnivoroFactory : public CriaturaFactory {
public:
    Criatura* crearCriatura(int x, int y, int energia, Ecosistema* eco, char clima);
    string getTipoFactory() const override;
};
