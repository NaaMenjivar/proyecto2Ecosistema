#include "FactoryManager.h"
#include "Ecosistema.h"

FactoryManager* FactoryManager::instance = nullptr;

FactoryManager::FactoryManager()
{
    carnivoroFactory = new CarnivoroFactory();
    herbivoroFactory = new HerbivoroFactory();
    omnivoroFactory = new OmnivoroFactory();
}

FactoryManager* FactoryManager::getInstance()
{
    if (instance == nullptr) {
        instance = new FactoryManager();
    }
    return instance;
}

FactoryManager::~FactoryManager()
{
    limpiarFactories();
}

CriaturaFactory* FactoryManager::getCarnivoroFactory()
{
    return carnivoroFactory;
}

CriaturaFactory* FactoryManager::getHerbivoroFactory()
{
    return herbivoroFactory;
}

CriaturaFactory* FactoryManager::getOmnivoroFactory()
{
    return omnivoroFactory;
}

Criatura* FactoryManager::crearCriaturaPorTipo(const string& tipo, int x, int y, int energia, Ecosistema* eco, char clima)
{
    if (tipo == "Carnivoro" || tipo == "carnivoro") {
        return carnivoroFactory->crearCriatura(x, y, energia, eco, clima);
    }
    else if (tipo == "Herbivoro" || tipo == "herbivoro") {
        return herbivoroFactory->crearCriatura(x, y, energia, eco, clima);
    }
    else if (tipo == "Omnivoro" || tipo == "omnivoro") {
        return omnivoroFactory->crearCriatura(x, y, energia, eco, clima);
    }
    else {
        cout << "Tipo de criatura no reconocido: " << tipo << endl;
        // Por defecto crear un herbívoro...
        return herbivoroFactory->crearCriatura(x, y, energia, eco, clima);
    }
}

void FactoryManager::limpiarFactories()
{
    if (carnivoroFactory) {
        delete carnivoroFactory;
        carnivoroFactory = nullptr;
    }
    if (herbivoroFactory) {
        delete herbivoroFactory;
        herbivoroFactory = nullptr;
    }
    if (omnivoroFactory) {
        delete omnivoroFactory;
        omnivoroFactory = nullptr;
    }
}
