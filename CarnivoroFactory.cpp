#include "CarnivoroFactory.h"

Criatura* CarnivoroFactory::crearCriatura(int x, int y, int energia, Ecosistema* eco, char clima)
{
	cout << "Creando Carnivoro en posicion (" << x << "," << y << ") con energia " << energia << endl;
	return new Carnivoro(x, y, energia, eco, clima); 
}

string CarnivoroFactory::getTipoFactory() const
{
	return "CarnivoroFactory"; 
}
