#include"Omnivoro.h"
#include"FactoryManager.h"

// Implementación de Omnívoro
Omnivoro::Omnivoro(int x, int y, int energiaInicial, Ecosistema* e, char cl)
    : Criatura(x, y, energiaInicial, e, cl) {
    tipo = "Omnivoro";
}

Omnivoro::~Omnivoro() {
}

void Omnivoro::Operacion() {
    buscarAlimento();
    cazarOPastar();
    consumirEnergia(5); // Consumo medio de energía
}

void Omnivoro::Update() {
    incrementarEdad();
    consumirEnergia(3); // Metabolismo base medio
    if (getClima() == 'T') {
        // Durante la tarde tienen ventaja
        alimentarse(3);
    }
    else if (getClima() == 'N') {
        // Durante la noche pueden cazar mejor
        alimentarse(2);
    }
}

Criatura* Omnivoro::reproducirse() { 
    if (puedeReproducirse()) {
        consumirEnergia(60);
        return new Omnivoro(posX, posY, 110, eco, clima); 
    }
    return nullptr;
}

void Omnivoro::buscarAlimento() {
    // Lógica para buscar tanto plantas como presas
    cout << "Omnivoro buscando alimento..." << endl;
}

void Omnivoro::cazarOPastar()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int decision = rand() % 2;

    if (decision == 0) { 
        cout << "Omnivoro decidio cazar..." << endl;
        alimentarse(20); // Energía de cazar
    }
    else {
        cout << "Omnivoro decidio pastar..." << endl;
        alimentarse(10); // Energía de pastar
    }
}

void Omnivoro::Guardar(ofstream& arch) {
    arch << tipo << '\t';
    arch << posX << '\t';
    arch << posY << '\t';
    arch << energia << '\t';
    arch << edad << '\t';
    arch << clima << '\n';
}


Criatura* Omnivoro::Lectura(ifstream& arch, Ecosistema* eco) {
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
