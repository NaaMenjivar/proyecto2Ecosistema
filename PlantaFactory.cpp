#include "PlantaFactory.h"

Recurso* PlantaFactory::crearRecurso(int x, int y, int valorN, Ecosistema* eco, char clima)
{
    cout << "Creando Planta en posicion (" << x << "," << y << ") con valor nutricional " << valorN << endl;
    return new Planta(x, y, valorN, eco, clima);
}

string PlantaFactory::getTipoFactory() const
{
    return "PlantaFactory";
}
