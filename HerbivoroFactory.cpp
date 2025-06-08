#include "HerbivoroFactory.h"

Criatura* HerbivoroFactory::crearCriatura(int x, int y, int energia, Ecosistema* eco, char clima)
{
    cout << "Creando Herbivoro en posicion (" << x << "," << y << ") con energia " << energia << endl;
    return new Herbivoro(x, y, energia, eco, clima);
}

string HerbivoroFactory::getTipoFactory() const
{
    return "HerbivoroFactory";
}
