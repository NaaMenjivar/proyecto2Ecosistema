#include"Ecosistema.h"
#include "FactoryManager.h"

Ecosistema::Ecosistema(){
	this->clima = 'D';
	this->colC = new ColeccionT<Criatura>();
	this->colR = new ColeccionT<Recurso>();
	this->factoryManager = FactoryManager::getInstance();
	this->matriz = new Matriz();
}
Ecosistema::~Ecosistema(){
	if (colC) delete colC;
	if (colR)delete colR;
	if (matriz) delete matriz;
	//No se hace delete del FactoryManager porque es Singleton
}

//GETS Y SETS CLIMA
char Ecosistema::getClima() { return clima; }
void Ecosistema::setClima(char cli) { //este mismo metodo utiliza el notify para notificar a los observadores (Criaturas y Recursos)
	clima = cli; 
	for (int i = 0; i < getTamanioC(); ++i) {
		Criatura* c = obtenerC(i);
		if (c) c->actualizarClima(cli);
	}
	for (int j = 0; j < getTamanioR(); ++j) {
		Recurso * r = obtenerR(j);
		if (r) r->actualizarClima(cli);
	}
	this->notify();
} 

//Notify --- MATRIZ
void Ecosistema::notify(){ //para prueba sin matriz...
	matriz->notifyTodos();
}

Criatura* Ecosistema::crearCriatura(const string& tipo, int x, int y, int energia)
{
	Criatura* nuevaCriatura = factoryManager->crearCriaturaPorTipo(tipo, x, y, energia, this, clima);
	if (nuevaCriatura && matriz->insertar(nuevaCriatura, x, y)) {
		agregarC(nuevaCriatura);
		cout << "Criatura " << tipo << " creada y agregada al ecosistema." << endl;
		return nuevaCriatura;
	}
	delete nuevaCriatura;
	return nullptr;
}

Criatura* Ecosistema::crearCarnivoro(int x, int y, int energia)
{
	CriaturaFactory* factory = factoryManager->getCarnivoroFactory();
	Criatura* carni = factory->crearCriatura(x, y, energia, this, clima);
	if (carni && matriz->insertar(carni, x, y)) {
		agregarC(carni);
		return carni;
	}
	delete carni;
	return nullptr;
}

Criatura* Ecosistema::crearHerbivoro(int x, int y, int energia)
{
	CriaturaFactory* factory = factoryManager->getHerbivoroFactory();
	Criatura* her = factory->crearCriatura(x, y, energia, this, clima);
	if (her && matriz->insertar(her, x, y)) {
		agregarC(her);
		return her;
	}
	delete her;
	return nullptr;
}

Criatura* Ecosistema::crearOmnivoro(int x, int y, int energia)
{
	CriaturaFactory* factory = factoryManager->getOmnivoroFactory();
	Criatura* omni = factory->crearCriatura(x, y, energia, this, clima);
	if (omni && matriz->insertar(omni, x, y)) { 
		agregarC(omni); 
		return omni; 
	}
	delete omni; 
	return nullptr;
}

Recurso* Ecosistema::crearRecurso(const string& tipo, int x, int y, int valorN)
{
	Recurso* nuevoRecurso = factoryManager->crearRecursoPorTipo(tipo, x, y, valorN, this, clima); 
	if (nuevoRecurso && matriz->insertar(nuevoRecurso, x, y)) { 
		agregarR(nuevoRecurso);
		cout << "Recurso " << tipo << " creada y agregada al ecosistema." << endl;
		return nuevoRecurso; 
	}
	delete nuevoRecurso;
	return nullptr;
}

Recurso* Ecosistema::crearAgua(int x, int y, int valorN)
{
	RecursoFactory* factory = factoryManager->getAguaFactory();
	Recurso* agua = factory->crearRecurso(x, y, valorN, this, clima); 
	if (agua && matriz->insertar(agua, x, y)) { 
		agregarR(agua);
		return agua; 
	}
	delete agua; 
	return nullptr;
}

Recurso* Ecosistema::crearPlanta(int x, int y, int valorN)
{
	RecursoFactory* factory = factoryManager->getPlantaFactory();
	Recurso* planta = factory->crearRecurso(x, y, valorN, this, clima);
	if (planta && matriz->insertar(planta, x, y)) { 
		agregarR(planta); 
		return planta; 
	}
	delete planta; 
	return nullptr;
}

Recurso* Ecosistema::crearCarne(int x, int y, int valorN)
{
	RecursoFactory* factory = factoryManager->getCarneFactory();
	Recurso* carne = factory->crearRecurso(x, y, valorN, this, clima);
	if (carne && matriz->insertar(carne, x, y)) {
		agregarR(carne);
		return carne; 
	}
	delete carne;
	return nullptr;
}

void Ecosistema::simularxTicks(int cantTicks)
{
	for (int t = 1; t <= cantTicks; ++t) {
		cout << "Realizando operaciones de criaturas...\n";
		matriz->simulacion();

		cout << "Actualizando estado de todas las entidades...\n";
		notify();

		cout << "Eliminando criaturas muertas...\n";
		eliminarMuert();

		cout << "\n";
		matriz->mostrar();
		cout << "\n";
	}
}

void Ecosistema::poblarEcosistema(int numCarnivoros, int numHerbivoros, int numOmnivoros)//para prueba...
{
	cout << "\n--- Poblando ecosistema ---" << endl;

	// Crear carnívoros
	for (int i = 0; i < numCarnivoros; i++) {
		int x, y;
		do {
			x = rand() % 10;
			y = rand() % 10;
		} while (matriz->obtener(x, y) != nullptr);

		crearCarnivoro(x, y, 100 + rand() % 50);
	}
	// Crear herbívoros
	for (int i = 0; i < numHerbivoros; i++) {
		int x, y;
		do {
			x = rand() % 10;
			y = rand() % 10;
		} while (matriz->obtener(x, y) != nullptr);

		crearHerbivoro(x, y, 80 + rand() % 40);
	}
	// Crear omnívoros
	for (int i = 0; i < numOmnivoros; i++) {
		int x, y;
		do {
			x = rand() % 10;
			y = rand() % 10;
		} while (matriz->obtener(x, y) != nullptr);

		crearOmnivoro(x, y, 90 + rand() % 45);
	}
	// Crear recursos
	for (int i = 0; i < 3; i++) {
		int x, y;
		// Agua
		do {
			x = rand() % 10;
			y = rand() % 10;
		} while (matriz->obtener(x, y) != nullptr);
		crearAgua(x, y, 30 + rand() % 20);

		// Planta
		do {
			x = rand() % 10;
			y = rand() % 10;
		} while (matriz->obtener(x, y) != nullptr);
		crearPlanta(x, y, 40 + rand() % 20);

		// Carne
		do {
			x = rand() % 10;
			y = rand() % 10;
		} while (matriz->obtener(x, y) != nullptr);
		crearCarne(x, y, 50 + rand() % 30);
	}

	cout << "Ecosistema poblado con " << colC->getTamanio() << " criaturas y "
		<< colR->getTamanio() << " recursos." << endl;

}

void Ecosistema::eliminarMuert()
{
	for (int i = getTamanioC() - 1; i >= 0; --i) {
		Criatura* c = obtenerC(i);
		if (c != nullptr && !c->estaViva()) {
			cout << "Criatura muerta eliminada: " << c->getTipo()
				<< " en (" << c->getPosX() << "," << c->getPosY() << ")\n";

			matriz->eliminarSeguro(c->getPosX(), c->getPosY());
			eliminarC(i);  
			delete c; 
		}
	}
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

void Ecosistema::GuardarCriaturas(string arch){
	GestionArchivos::GuardarCriaturas(colC, arch);
}
void Ecosistema::LecturaCriaturas(string arch){
	GestionArchivos::LecturaCriaturas(colC, arch,this);
}



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

void  Ecosistema::GuardarRecrusos(string arch){
	GestionArchivos::GuardarRecursos(colR, arch);
}
void  Ecosistema::LecturaRecursos(string arch){
	GestionArchivos::LecturaRecursos(colR, arch, this);
}


//METODOS DE LA MATRIZ.....

void Ecosistema::insertaMatriz(Observer* cri, int posX, int posY) {
	matriz->insertar(cri, posX, posY);
}