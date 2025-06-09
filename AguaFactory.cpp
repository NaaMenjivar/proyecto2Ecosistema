#include "AguaFactory.h"

Recurso* AguaFactory::crearRecurso(int x, int y, int valorN, Ecosistema* eco, char clima)
{
    cout << "Creando Agua en posicion (" << x << "," << y << ") con valor nutricional " << valorN << endl;
    return new Agua(x, y, valorN, eco, clima);
}

string AguaFactory::getTipoFactory() const
{
    return "AguaFactory";
}
