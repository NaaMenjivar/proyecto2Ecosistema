#pragma once
#include "CriaturaFactory.h"
#include "CarnivoroFactory.h"
#include "OmnivoroFactory.h"
#include "HerbivoroFactory.h"

class FactoryManager // Factory Manager - Singleton para gestionar las factories...
{
private:
    static FactoryManager* instance;
    CarnivoroFactory* carnivoroFactory;
    HerbivoroFactory* herbivoroFactory;
    OmnivoroFactory* omnivoroFactory;

    FactoryManager();
public:
    static FactoryManager* getInstance();
    ~FactoryManager();

    // Métodos factories específicas...
    CriaturaFactory* getCarnivoroFactory();
    CriaturaFactory* getHerbivoroFactory();
    CriaturaFactory* getOmnivoroFactory();

    // Método para crear criatura por tipo...
    Criatura* crearCriaturaPorTipo(const string& tipo, int x, int y, int energia, Ecosistema* eco, char clima);

    // Limpiar memoria...
    void limpiarFactories();
};

