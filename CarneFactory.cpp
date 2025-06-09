#include "CarneFactory.h"

Recurso* CarneFactory::crearRecurso(int x, int y, int valorN, Ecosistema* eco, char clima)
{
    cout << "Creando Carne en posicion (" << x << "," << y << ") con valor nutricional " << valorN << endl;
    return new Carne(x, y, valorN, eco, clima);
}

string CarneFactory::getTipoFactory() const
{
    return "CarneFactory";
}
