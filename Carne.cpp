#include"Carne.h"

// Implementación de Carne

Carne::Carne(int x, int y, int valor, Ecosistema* e, char cli)
    : Recurso(x, y, valor, e, cli), tiempoDescomposicion(20) {
    tipo = "Carne";
    tiempoRegeneracion = -1; // La carne no se regenera naturalmente
}

Carne::~Carne() {
}

void Carne::Operacion() {
    if (disponible) {
        descomponer();
    }
}

void Carne::Update() {
    if (tiempoDescomposicion > 0) {
        tiempoDescomposicion--;
        if (tiempoDescomposicion <= 0) {
            disponible = false;
            valorNutricional = 0;
        }
    }
}

void Carne::descomponer() {
    if (tiempoDescomposicion > 0) {
        valorNutricional = (valorNutricional * tiempoDescomposicion) / 20;
    }
}

void Carne::Guardar(ofstream& arch) {
    arch << tipo << '\t';
    arch << posX << '\t';
    arch << posY << '\t';
    arch << valorNutricional << '\t';
    arch << disponible << '\t';
    arch << tiempoRegeneracion << '\t';
    arch << tiempoDescomposicion << '\t';
    arch << clima << '\n';
}
Recurso* Carne::Lectura(ifstream& arch, Ecosistema* eco) {
    string tip, poX, poY, valNu, dis, tiR, tiD, cli;
    getline(arch, tip, '\t');
    getline(arch, poX, '\t');
    getline(arch, poY, '\t');
    getline(arch, valNu, '\t');
    getline(arch, dis, '\t');
    getline(arch, tiR, '\t');
    getline(arch, tiD, '\t');
    getline(arch, cli, '\n');
    int pX, pY, vN, tR, tD, cl;
    bool di;
    pX = MetAux::seteoInt(poX); pY = MetAux::seteoInt(poY); vN = MetAux::seteoInt(valNu); 
    tR = MetAux::seteoInt(tiR); tD = MetAux::seteoInt(tiD); cl = MetAux::seteoChar(cli);
    di = MetAux::seteoBool(dis);
    Carne* car = new Carne(pX, pY, vN, eco, cl);
    car->setDisponible(di);
    car->setTiempoRegeneracion(tR);
    car->setTiempoDescomposicion(tD);
    return car;
}
