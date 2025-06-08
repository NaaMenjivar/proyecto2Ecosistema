#include"Ecosistema.h"
#include "FactoryManager.h"

Ecosistema::Ecosistema(){
	clima = 'D';
	colC = new ColeccionT<Criatura>();
	colR = new ColeccionT<Recurso>();
	factoryManager = FactoryManager::getInstance(); 
	//Faltan metodos Matriz
}
Ecosistema::~Ecosistema(){
	if (colC) delete colC;
	if (colR)delete colR;
	//No se hace delete de la matriz ya que se haria un error de compilacion
	//No se hace delete del FactoryManager porque es Singleton
}

//GETS Y SETS CLIMA
char Ecosistema::getClima() { return clima; }
void Ecosistema::setClima(char cli) { //este mismo metodo utiliza el notify para notificar a los observadores (Criaturas y Recursos)
	clima = cli; 
	this->notify();
} 

//Notify --- MATRIZ
void Ecosistema::notify(){ //para prueba sin matriz...
	// Notificar a todas las criaturas sobre el cambio de clima 
	for (int i = 0; i < colC->getTamanio(); i++) { 
		Criatura* criatura = colC->obtener(i); 
		if (criatura != nullptr) { 
			criatura->Update(); // Actualizar cada criatura 
		}
	}
	// Notificar a todos los recursos sobre el cambio de clima
	for (int i = 0; i < colR->getTamanio(); i++) { 
		Recurso* recurso = colR->obtener(i); 
		if (recurso != nullptr) { 
			recurso->Update(); // Actualizar cada recurso 
		}
	}
}

Criatura* Ecosistema::crearCriatura(const string& tipo, int x, int y, int energia)
{
	Criatura* nuevaCriatura = factoryManager->crearCriaturaPorTipo(tipo, x, y, energia, this, clima);
	if (nuevaCriatura != nullptr) {
		agregarC(nuevaCriatura);
		cout << "Criatura " << tipo << " creada y agregada al ecosistema." << endl;
	}
	return nuevaCriatura;
}

Criatura* Ecosistema::crearCarnivoro(int x, int y, int energia)
{
	CriaturaFactory* factory = factoryManager->getCarnivoroFactory(); 
	Criatura* carnivoro = factory->crearCriatura(x, y, energia, this, clima); 
	if (carnivoro != nullptr) { 
		agregarC(carnivoro); 
	}
	return carnivoro; 
}

Criatura* Ecosistema::crearHerbivoro(int x, int y, int energia)
{
	CriaturaFactory* factory = factoryManager->getHerbivoroFactory();
	Criatura* herbivoro = factory->crearCriatura(x, y, energia, this, clima);
	if (herbivoro != nullptr) {
		agregarC(herbivoro);
	}
	return herbivoro;
}

Criatura* Ecosistema::crearOmnivoro(int x, int y, int energia)
{
	CriaturaFactory* factory = factoryManager->getOmnivoroFactory();
	Criatura* omnivoro = factory->crearCriatura(x, y, energia, this, clima);
	if (omnivoro != nullptr) {
		agregarC(omnivoro);
	}
	return omnivoro;
}

void Ecosistema::simularCiclo() //para prueba...
{
	cout << "\n--- Simulando ciclo del ecosistema ---" << endl;
	cout << "Clima actual: " << clima << endl;

	// Ejecutar operaciones de todas las criaturas
	for (int i = 0; i < colC->getTamanio(); i++) {
		Criatura* criatura = colC->obtener(i);
		if (criatura != nullptr && criatura->estaViva()) {
			criatura->Operacion();
		}
	}
	// Remover criaturas muertas
	for (int i = colC->getTamanio() - 1; i >= 0; i--) {
		Criatura* criatura = colC->obtener(i);
		if (criatura != nullptr && !criatura->estaViva()) {
			cout << "Criatura " << criatura->getTipo() << " ha muerto." << endl;
			eliminarC(i);
			delete criatura;
		}
	}
	cout << "Criaturas vivas: " << colC->getTamanio() << endl;
}

void Ecosistema::poblarEcosistema(int numCarnivoros, int numHerbivoros, int numOmnivoros)//para prueba...
{
	cout << "\n--- Poblando ecosistema ---" << endl;

	// Crear carnívoros
	for (int i = 0; i < numCarnivoros; i++) {
		crearCarnivoro(rand() % 100, rand() % 100, 100 + rand() % 50);
	}
	// Crear herbívoros
	for (int i = 0; i < numHerbivoros; i++) {
		crearHerbivoro(rand() % 100, rand() % 100, 80 + rand() % 40);
	}
	// Crear omnívoros
	for (int i = 0; i < numOmnivoros; i++) {
		crearOmnivoro(rand() % 100, rand() % 100, 90 + rand() % 45);
	}

	cout << "Ecosistema poblado con " << colC->getTamanio() << " criaturas." << endl;
}


//METODOS COLECCION CRIATURAS
void Ecosistema::agregarC(Criatura* elemento) { colC->agregar(elemento); }
bool Ecosistema::eliminarC(int indice) { return colC->eliminar(indice); }
bool Ecosistema::eliminarC(Criatura* elemento) { return colC->eliminar(elemento); }
Criatura* Ecosistema::obtenerC(int indice) const { return colC->obtener(indice); }
int Ecosistema::buscarC(Criatura* elemento) const { return colC->buscar(elemento); }

int Ecosistema::getTamanioC() const { return colC->getTamanio(); }
int Ecosistema::getCapacidadC() const { return colC->getCapacidad(); }
bool Ecosistema::estaVaciaC() const { return colC->estaVacia(); }

void Ecosistema::limpiarC() { colC->limpiar(); }
//GUARDADO
//LECTURA



//METODOS COLECCION RECURSOS..

void Ecosistema::agregarR(Recurso* elemento) { colR->agregar(elemento); }
bool Ecosistema::eliminarR(int indice) { return colR->eliminar(indice); }
bool Ecosistema::eliminarR(Recurso* elemento) { return colR->eliminar(elemento); }
Recurso* Ecosistema::obtenerR(int indice) const { return colR->obtener(indice); }
int Ecosistema::buscarR(Recurso* elemento) const { return colR->buscar(elemento); }

int Ecosistema::getTamanioR() const { return colR->getTamanio(); }
int Ecosistema::getCapacidadR() const { return colR->getCapacidad(); }
bool Ecosistema::estaVaciaR() const { return colR->estaVacia(); }

void Ecosistema::limpiarR() { colR->limpiar(); }
//GUARDADO
//LECTURA


//METODOS DE LA MATRIZ.....