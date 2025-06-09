#pragma once
#include "CriaturaFactory.h"
#include "CarnivoroFactory.h"
#include "OmnivoroFactory.h"
#include "HerbivoroFactory.h"
#include "RecursoFactory.h"
#include "AguaFactory.h"
#include "PlantaFactory.h"
#include "CarneFactory.h"

class FactoryManager // Factory Manager - Singleton para gestionar las factories...
{
private:
    static FactoryManager* instance;
    CarnivoroFactory* carnivoroFactory;
    HerbivoroFactory* herbivoroFactory;
    OmnivoroFactory* omnivoroFactory;
    AguaFactory* aguaFactory;
    PlantaFactory* plantaFactory;
    CarneFactory* carneFactory;

    FactoryManager();
public:
    static FactoryManager* getInstance();
    ~FactoryManager();

    // Métodos factories específicas...
    CriaturaFactory* getCarnivoroFactory();
    CriaturaFactory* getHerbivoroFactory();
    CriaturaFactory* getOmnivoroFactory();
    RecursoFactory* getAguaFactory();
    RecursoFactory* getPlantaFactory();
    RecursoFactory* getCarneFactory();

    // Método para crear criatura y recursos por tipo...
    Criatura* crearCriaturaPorTipo(const string& tipo, int x, int y, int energia, Ecosistema* eco, char clima);
    Recurso* crearRecursoPorTipo(const string& tipo, int x, int y, int valorN, Ecosistema* eco, char clima);

    // Limpiar memoria...
    void limpiarFactories();
};

