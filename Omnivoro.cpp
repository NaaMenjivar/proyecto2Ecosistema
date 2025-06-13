#include"Omnivoro.h"
#include"FactoryManager.h"
#include"Matriz.h"
#include "Ecosistema.h"


// Implementación de Omnívoro
Omnivoro::Omnivoro(int x, int y, int energiaInicial, Ecosistema* e, char cl)
    : Criatura(x, y, energiaInicial, e, cl) {
    tipo = "Omnivoro";
}

Omnivoro::~Omnivoro() {
}

void Omnivoro::Operacion(Matriz* mat) {
    int oldX = getPosX(), oldY = getPosY();
    Observer* ob = mat->verEntorno(oldX, oldY);

    if (ob) {
        // Reproducción
        if (Omnivoro* pareja = dynamic_cast<Omnivoro*>(ob)) {
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
                                    cout << "[OMNIVORO] (" << oldX << "," << oldY
                                        << ") se reprodujo y nacio un OMNIVORO en ("
                                        << i << "," << j << ")\n";
                                    inserted = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        // Cazar Omnivoro
        if (Omnivoro* om2 = dynamic_cast<Omnivoro*>(ob)) {
            DepredaOmnivoro dO;
            if (dO.ejecutar(this, om2)) {
                if (om2->getEnergia() == 0) {
                    int tx = om2->getPosX(), ty = om2->getPosY();
                    if (mat->eliminarSeguro(tx, ty) &&
                        mat->moverSeguro(oldX, oldY, tx, ty))
                    {
                        setPosicion(tx, ty);
                        cout << "[OMNIVORO] (" << oldX << "," << oldY
                            << ") cazo y devoro un OMNIVORO en ("
                            << tx << "," << ty << ")\n";
                    }
                }
            }
        }
        // Cazar Herbivoro
        if (Herbivoro* her = dynamic_cast<Herbivoro*>(ob)) {
            DepredaHerbivoro dH;
            if (dH.ejecutar(this, her)) {
                if (her->getEnergia() == 0) {
                    int tx = her->getPosX(), ty = her->getPosY();
                    if (mat->eliminarSeguro(tx, ty) &&
                        mat->moverSeguro(oldX, oldY, tx, ty))
                    {
                        setPosicion(tx, ty);
                        cout << "[OMNIVORO] (" << oldX << "," << oldY
                            << ") cazo y devoro un HERBIVORO en ("
                            << tx << "," << ty << ")\n";
                    }
                }
            }
            return;
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
        // Comer carne
        if (Carne* car = dynamic_cast<Carne*>(ob)) {
            int tx = car->getPosX(), ty = car->getPosY();
            alimentarse(car->getValorNutricional());
            if (mat->eliminarSeguro(tx, ty) &&
                mat->moverSeguro(oldX, oldY, tx, ty))
            {
                setPosicion(tx, ty);
                cout << "[OMNIVORO] (" << oldX << "," << oldY
                    << ") comio CARNE en ("
                    << tx << "," << ty << ")\n";
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
                cout << "[OMNIVORO] (" << oldX << "," << oldY
                    << ") comio PLANTA en ("
                    << tx << "," << ty << ")\n";
            }
            return;
        }
    }
    // Mover aleatorio
    CambiaDireccion cd(1);
    bool seMovioInterno = cd.ejecutar(this);
    if (!seMovioInterno) {
        return;
    }
    int newX = getPosX(), newY = getPosY();
    if (mat->moverSeguro(oldX, oldY, newX, newY)) {
        cout << "[OMNIVORO] (" << oldX << "," << oldY
            << ") se movio a (" << newX << "," << newY << ")\n";
    }
    else {
        setPosicion(oldX, oldY);
    }
}

void Omnivoro::Update() {
    incrementarEdad();
    consumirEnergia(1);
    if (getClima() == 'D' || getClima() == 'd') {
        // Durante el día gastan más energía por el calor
        consumirEnergia(2);
    }
}

Criatura* Omnivoro::reproducirse() { 
    if (puedeReproducirse()) {
        return new Omnivoro(posX, posY, 110, eco, clima); 
    }
    return nullptr;
}

char Omnivoro::getSimbolo() const
{
    return 'O';
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
    Criatura* cri = new Omnivoro(pX, pY, en, eco, cl);
    cri->setEdad(ed);
    return cri;
}
