#include"Herbivoro.h"
#include"FactoryManager.h"
#include"Matriz.h"
#include "Ecosistema.h"

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
        if (Herbivoro* pareja = dynamic_cast<Herbivoro*>(ob)) {
            Reproduccion repro(80, 5);
            if (repro.ejecutar(this, pareja)) {
                Criatura* cr = reproducirse();
                if (cr) {
                    bool inserted = false;
                    for (int i = 0; i < 10 && !inserted; ++i) {
                        for (int j = 0; j < 10 && !inserted; ++j) {
                            if (mat->obtener(i, j) == nullptr) {
                                cr->setPosicion(i, j);
                                if (mat->insertar(cr, i, j)) {
                                    getEcosistema()->agregarC(cr);
                                    cout << "[HERBIVORO] (" << oldX << "," << oldY
                                        << ") se reprodujo y nacio un HERBIVORO en ("
                                        << i << "," << j << ")\n";
                                    inserted = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        // Beber agua
        if (Agua* ag = dynamic_cast<Agua*>(ob)) {
            TomaAgua tA;
            if (tA.ejecutar(this, ag)) {
                int ax = ag->getPosX(), ay = ag->getPosY();
                if (mat->eliminarSeguro(ax, ay) &&
                    mat->moverSeguro(oldX, oldY, ax, ay))
                {
                    setPosicion(ax, ay);
                    cout << "[CARNIVORO] (" << oldX << "," << oldY
                        << ") bebio AGUA en ("
                        << ax << "," << ay << ")\n";
                }
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
                    << ") comio PLANTA en (" << tx << "," << ty << ")\n";
            }
            return;
        }
    }
    //Mover aleatorio
    CambiaDireccion cd(1);
    bool seMovioInterno = cd.ejecutar(this);
    if (!seMovioInterno) {
        return;
    }
    int newX = getPosX(), newY = getPosY();
    if (mat->moverSeguro(oldX, oldY, newX, newY)) {
        cout << "[HERBIVORO] (" << oldX << "," << oldY
            << ") se movio a (" << newX << "," << newY << ")\n";
    }
    else {
        setPosicion(oldX, oldY);
    }
}

void Herbivoro::Update() {
    incrementarEdad();
    consumirEnergia(1); // Metabolismo base
    if (getClima() == 'N' || getClima() == 'n') {
        // Durante la noche consumen más energía por estar alerta
        consumirEnergia(3); 
    }
}

Criatura* Herbivoro::reproducirse() {
    if (puedeReproducirse()) {
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
    Criatura* cri = new Herbivoro(pX, pY, en, eco, cl);
    cri->setEdad(ed);
    return cri;
}