#include"Ecosistema.h"

Ecosistema::Ecosistema(){
	clima = 'D';
	colC = new ColeccionT<Criatura>();
	colR = new ColeccionT<Recurso>();
	//Faltan metodos Factory / Matriz
}
Ecosistema::~Ecosistema(){
	if (colC) delete colC;
	if (colR)delete colR;
	//No se hace delete de la matriz ya que se haria un error de compilacion
	//Delete Factory
}

//GETS Y SETS CLIMA
char Ecosistema::getClima() { return clima; }
void Ecosistema::setClima(char cli) { //este mismo metodo utiliza el notify para notificar a los observadores (Criaturas y Recursos)
	clima = cli; 
	this->notify();
} 

//Notify --- MATRIZ
void Ecosistema::notify(){
	//Metodo Matriz
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