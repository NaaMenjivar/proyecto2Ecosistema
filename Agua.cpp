#include"Agua.h"
#include"Matriz.h"

// Implementación de Agua
Agua::Agua(int x, int y, int valor, Ecosistema* e, char cli)
    : Recurso(x, y, valor, e, cli), pureza(100) {

    tipo = "Agua";
}

Agua::~Agua() {
}

void Agua::Operacion(Matriz* mat) {
    if (tiempoRegeneracion > 0) {
        tiempoRegeneracion--;
    }
    regenerar();
}

void Agua::Update() {
    // El agua se mantiene relativamente estable
    if (pureza > 50) {
        pureza--;
    }
}

void Agua::regenerar() {
    if (!disponible && tiempoRegeneracion <= 0) {
        disponible = true;
        tiempoRegeneracion = 0;
        pureza = 100; // El agua se renueva con pureza máxima
    }
}

char Agua::getSimbolo() const
{
    return 'A';
}

void Agua::Guardar(ofstream& arch) {
    arch << tipo << '\t';
    arch << posX << '\t';
    arch << posY << '\t';
    arch << valorNutricional << '\t';
    arch << disponible << '\t';
    arch << tiempoRegeneracion << '\t';
    arch << pureza<<'\t';
    arch << clima << '\n';
}

Recurso* Agua::Lectura(ifstream& arch, Ecosistema* eco) {
    string tip, poX, poY, valNu, dis, tiR, pur, cli;
    getline(arch, tip, '\t');
    getline(arch, poX, '\t');
    getline(arch, poY, '\t');
    getline(arch, valNu, '\t');
    getline(arch, dis, '\t');
    getline(arch, tiR, '\t');
    getline(arch, pur, '\t');
    getline(arch, cli, '\n');
    int pX, pY, vN, tR, pu, cl;
    bool di;
    pX = MetAux::seteoInt(poX); pY = MetAux::seteoInt(poY); vN = MetAux::seteoInt(valNu);
    tR = MetAux::seteoInt(tiR); pu = MetAux::seteoInt(pur); cl = MetAux::seteoChar(cli);
    di = MetAux::seteoBool(dis);
    Agua* car = new Agua(pX, pY, vN, eco, cl);
    car->setDisponible(di);
    car->setTiempoRegeneracion(tR);
    car->setPureza(pu);
    return car;
}