#include"Planta.h"
#include"Matriz.h"


// Implementación de Planta
Planta::Planta(int x, int y, int valor, Ecosistema* e, char cli)
    : Recurso(x, y, valor, e, cli), nivelCrecimiento(50) {
    tipo = "Planta";
}

Planta::~Planta() {
}

void Planta::Operacion(Matriz* mat) {
    if (disponible) {
        crecer();
    }
    else if (tiempoRegeneracion > 0) {
        tiempoRegeneracion--;
        regenerar();
    }
}

void Planta::Update() {
    // Las plantas crecen gradualmente
    if (nivelCrecimiento < 100 && disponible) {
        nivelCrecimiento += 2;
        valorNutricional = (60 * nivelCrecimiento) / 100;
    }
    if (getClima() == 'D') {
        // Durante el día pueden alimentarse mejor
        valorNutricional+=2;
    }
}

void Planta::regenerar() {
    if (!disponible && tiempoRegeneracion <= 0) {
        disponible = true;
        nivelCrecimiento = 30; // Rebrote con crecimiento inicial
        valorNutricional = 20;
        tiempoRegeneracion = 0;
    }
}

void Planta::crecer() {
    if (nivelCrecimiento < 100) {
        nivelCrecimiento++;
        valorNutricional = (60 * nivelCrecimiento) / 100;
    }
}

void Planta::Guardar(ofstream& arch){
    arch << tipo << '\t';
    arch << posX << '\t';
    arch << posY << '\t';
    arch << valorNutricional << '\t';
    arch << disponible << '\t';
    arch << tiempoRegeneracion << '\t';
    arch << nivelCrecimiento << '\t';
    arch << clima << '\n';
}

Recurso* Planta::Lectura(ifstream& arch, Ecosistema* eco) {
    string tip, poX, poY, valNu, dis, tiR, nivC, cli;
    getline(arch, tip, '\t');
    getline(arch, poX, '\t');
    getline(arch, poY, '\t');
    getline(arch, valNu, '\t');
    getline(arch, dis, '\t');
    getline(arch, tiR, '\t');
    getline(arch, nivC, '\t');
    getline(arch, cli, '\n');
    int pX, pY, vN, tR, nC, cl;
    bool di;
    pX = MetAux::seteoInt(poX); pY = MetAux::seteoInt(poY); vN = MetAux::seteoInt(valNu);
    tR = MetAux::seteoInt(tiR); nC = MetAux::seteoInt(nivC); cl = MetAux::seteoChar(cli);
    di = MetAux::seteoBool(dis);
    Planta* car = new Planta(pX, pY, vN, eco, cl);
    car->setDisponible(di);
    car->setTiempoRegeneracion(tR);
    car->setNivCrec(nC);
    return car;
}



