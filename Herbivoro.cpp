#include"Herbivoro.h"
#include"FactoryManager.h"
#include"Matriz.h"

// Implementación de Herbívoro
Herbivoro::Herbivoro(int x, int y, int energiaInicial, Ecosistema* e, char cl)
    : Criatura(x, y, energiaInicial, e, cl) {
    tipo = "Herbivoro";
}

Herbivoro::~Herbivoro() {
}

void Herbivoro::Operacion(Matriz* mat) {
    int oldX = getPosX(), oldY = getPosY();
    Observer* ob = mat->verEntorno(oldX, oldY);

    if (ob) {
        // Reproducción
        if (Criatura* pareja = dynamic_cast<Criatura*>(ob)) {
            Reproduccion repro(80, 4, 1);
            if (repro.ejecutar(this, pareja)) {
                Criatura* cr = reproducirse();
                if (cr) {
                    bool inserted = false;
                    for (int i = 0; i < 10 && !inserted; ++i) {
                        for (int j = 0; j < 10 && !inserted; ++j) {
                            if (mat->obtener(i, j) == nullptr) {
                                cr->setPosicion(i, j);
                                if (mat->insertar(cr, i, j)) {
                                    cout << "[HERBIVORO] (" << oldX << "," << oldY
                                        << ") se reprodujo y nació un HERBIVORO en ("
                                        << i << "," << j << ")\n";
                                    inserted = true;
                                }
                            }
                        }
                    }
                }
            }
            return;
        }
        // Beber agua
        if (Agua* ag = dynamic_cast<Agua*>(ob)) {
            TomaAgua tA;
            if (tA.ejecutar(this, ag)) {
                cout << "[HERBIVORO] (" << oldX << "," << oldY
                    << ") bebió AGUA en (" << ag->getPosX() << "," << ag->getPosY() << ")\n";
            }
            return;
        }
        // Comer planta
        if (Planta* pl = dynamic_cast<Planta*>(ob)) {
            int tx = pl->getPosX(), ty = pl->getPosY();
            alimentarse(pl->getValorNutricional());
            if (mat->eliminarSeguro(tx, ty) &&
                mat->moverSeguro(oldX, oldY, tx, ty))
            {
                setPosicion(tx, ty);
                cout << "[HERBIVORO] (" << oldX << "," << oldY
                    << ") comió PLANTA en (" << tx << "," << ty << ")\n";
            }
            return;
        }
    }
    //Mover aleatorio
    CambiaDireccion cd(1);
    cd.ejecutar(this);
    int newX = getPosX(), newY = getPosY();
    if (mat->moverSeguro(oldX, oldY, newX, newY)) {
        cout << "[HERBIVORO] (" << oldX << "," << oldY
            << ") se movió a (" << newX << "," << newY << ")\n";
    }
    else {
        setPosicion(oldX, oldY);
    }
}

void Herbivoro::Update() {
    incrementarEdad();
    consumirEnergia(2); // Metabolismo base
    if (getClima() == 'N') { 
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

char Herbivoro::getSimbolo() const
{
    return 'H';
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
    Criatura* cri = fact->crearCriaturaPorTipo(tip, pX, pY, en, eco, cl);
    cri->setEdad(ed);
    return cri;
}