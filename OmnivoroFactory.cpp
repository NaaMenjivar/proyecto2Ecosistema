#include "OmnivoroFactory.h"

Criatura* OmnivoroFactory::crearCriatura(int x, int y, int energia, Ecosistema* eco, char clima)
{
    cout << "Creando Omnivoro en posicion (" << x << "," << y << ") con energia " << energia << endl;
    return new Omnivoro(x, y, energia, eco, clima);
}

string OmnivoroFactory::getTipoFactory() const
{
    return "OmnivoroFactory";
}
