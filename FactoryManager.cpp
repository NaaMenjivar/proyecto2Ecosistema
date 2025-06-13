#include "FactoryManager.h"
#include "Ecosistema.h"

FactoryManager* FactoryManager::instance = nullptr;

FactoryManager::FactoryManager()
{
    this->carnivoroFactory = new CarnivoroFactory();
    this->herbivoroFactory = new HerbivoroFactory();
    this->omnivoroFactory = new OmnivoroFactory();
    this->aguaFactory = new AguaFactory();
    this->plantaFactory = new PlantaFactory(); 
    this->carneFactory = new CarneFactory();
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

RecursoFactory* FactoryManager::getAguaFactory()
{
    return aguaFactory; 
}

RecursoFactory* FactoryManager::getPlantaFactory()
{ 
    return plantaFactory; 
}

RecursoFactory* FactoryManager::getCarneFactory()
{
    return carneFactory; 
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

Recurso* FactoryManager::crearRecursoPorTipo(const string& tipo, int x, int y, int valorN, Ecosistema* eco, char clima)
{
    if (tipo == "Agua" || tipo == "agua") {
        return aguaFactory->crearRecurso(x, y, valorN, eco, clima); 
    }
    else if (tipo == "Planta" || tipo == "planta") {
        return plantaFactory->crearRecurso(x, y, valorN, eco, clima); 
    }
    else if (tipo == "Carne" || tipo == "carne") {
        return carneFactory->crearRecurso(x, y, valorN, eco, clima);
    }
    else {
        cout << "Tipo de recurso no reconocido: " << tipo << endl;
        // Por defecto crear una planta... 
        return plantaFactory->crearRecurso(x, y, valorN, eco, clima); 
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
    if (aguaFactory) {
        delete aguaFactory; 
        aguaFactory = nullptr; 
    } 
    if (plantaFactory) {
        delete plantaFactory; 
        plantaFactory = nullptr; 
    }
    if (carneFactory) {
        delete carneFactory; 
        carneFactory = nullptr; 
    }
}
