#include"Herbivoro.h"
#include"FactoryManager.h"

// Implementación de Herbívoro
Herbivoro::Herbivoro(int x, int y, int energiaInicial, Ecosistema* e, char cl)
    : Criatura(x, y, energiaInicial, e, cl) {
    tipo = "Herbivoro";
}

Herbivoro::~Herbivoro() {
}

void Herbivoro::Operacion() {
    buscarPlantas();
    pastar(); 
    consumirEnergia(3); // Los herbívoros consumen menos energía
}

void Herbivoro::Update() {
    incrementarEdad();
    consumirEnergia(2); // Metabolismo base
    if (getClima() == 'D') {
        // Durante el día pueden alimentarse mejor
        alimentarse(5);
    }
    else if (getClima() == 'N') {
        // Durante la noche consumen más energía por estar alerta
        consumirEnergia(3);
    }
}

Criatura* Herbivoro::reproducirse() {
    if (puedeReproducirse()) {
        consumirEnergia(50);
        return new Herbivoro(posX, posY, 100, eco, clima);
    }
    return nullptr;
}

void Herbivoro::buscarPlantas() {
    // Lógica para buscar plantas cercanas
    cout << "Herbivoro buscando plantas..." << endl;
}

void Herbivoro::pastar()
{
    cout << "Herbivoro pastando..." << endl;
    alimentarse(15); // Obtiene energía de las plantas
}


void Herbivoro::Guardar(ofstream& arch) {
    arch << tipo << '\t';
    arch << posX << '\t';
    arch << posY << '\t';
    arch << energia << '\t';
    arch << edad << '\t';
    arch << clima << '\n';
}

Criatura* Herbivoro::Lectura(ifstream& arch, Ecosistema* eco) {
    string tip, poX, poY, ene, eda, cli;
    getline(arch, tip, '\t');
    getline(arch, poX, '\t');
    getline(arch, poY, '\t');
    getline(arch, ene, '\t');
    getline(arch, eda, '\t');
    getline(arch, cli, '\n');
    int pX, pY, en, ed;
    char cl;
    pX = MetAux::seteoInt(poX);
    pY = MetAux::seteoInt(poY);
    en = MetAux::seteoInt(ene);
    ed = MetAux::seteoInt(eda);
    cl = MetAux::seteoChar(cli);
    FactoryManager* fact = FactoryManager::getInstance();
    Criatura* cri = fact->crearCriaturaPorTipo(tip, pX, pX, en, eco, cl);
    cri->setEdad(ed);
    return cri;
}