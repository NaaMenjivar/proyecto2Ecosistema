#include"Carnivoro.h"
#include"FactoryManager.h"
#include"Matriz.h"
#include "Ecosistema.h"


// Implementación de Carnívoro
Carnivoro::Carnivoro(int x, int y, int energiaInicial, Ecosistema* e, char cl)
    : Criatura(x, y, energiaInicial, e, cl) {
    tipo = "Carnivoro";
}

Carnivoro::~Carnivoro() {
}

void Carnivoro::Operacion(Matriz* mat) {
    int oldX = getPosX(), oldY = getPosY();
    Observer* ob = mat->verEntorno(oldX, oldY);
    if (ob) {
        // Reproducción
        if (Carnivoro* pareja = dynamic_cast<Carnivoro*>(ob)) {
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
                                    cout << "[CARNIVORO] (" << oldX << "," << oldY
                                        << ") se reprodujo y nacio un nuevo Carnivoro en ("
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
        // Depredar Omnivoro
        if (Omnivoro* om = dynamic_cast<Omnivoro*>(ob)) {
            DepredaOmnivoro dO;
            if (dO.ejecutar(this, om)) {
                if (om->getEnergia() == 0) {
                    int tx = om->getPosX(), ty = om->getPosY();
                    if (mat->eliminarSeguro(tx, ty) &&
                        mat->moverSeguro(oldX, oldY, tx, ty))
                    {
                        setPosicion(tx, ty);
                        cout << "[CARNIVORO] (" << oldX << "," << oldY
                            << ") cazo y devoro un OMNIVORO en ("
                            << tx << "," << ty << ")\n";
                    }
                }
            }
            return;
        }
        // Depredar Herbivoro
        if (Herbivoro* her = dynamic_cast<Herbivoro*>(ob)) {
            DepredaHerbivoro dH;
            if (dH.ejecutar(this, her)) {
                if (her->getEnergia() == 0) {
                    int tx = her->getPosX(), ty = her->getPosY();
                    if (mat->eliminarSeguro(tx, ty) &&
                        mat->moverSeguro(oldX, oldY, tx, ty))
                    {
                        setPosicion(tx, ty);
                        cout << "[CARNIVORO] (" << oldX << "," << oldY
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
                cout << "[CARNIVORO] (" << oldX << "," << oldY
                    << ") comio CARNE en ("
                    << tx << "," << ty << ")\n";
            }
            return;
        }
    }
    // Movimiento aleatorio
    CambiaDireccion cd(1);
    if (cd.ejecutar(this)) {
        // la criatura ya actualizó posX/posY internamente
        int newX = getPosX(), newY = getPosY();
        // intentamos mover en la matriz
        if (mat->moverSeguro(oldX, oldY, newX, newY)) {
            cout << "[CARNIVORO] (" << oldX << "," << oldY
                << ") se movio a (" << newX << "," << newY << ")\n";
        }
        else {
            // si falló en la matriz, revertimos la posición interna
            setPosicion(oldX, oldY);
        }
    }
}

void Carnivoro::Update() {
    incrementarEdad();
    consumirEnergia(1); // Metabolismo base más alto
    if (getClima() == 'D' || getClima() == 'd') {
        // Durante el día gastan más energía por el calor
        consumirEnergia(2);
    }
}

Criatura* Carnivoro::reproducirse() {  
    if (puedeReproducirse()) { 
        return new Carnivoro(posX, posY, 120, eco, clima); 
    }
    return nullptr;
}

char Carnivoro::getSimbolo() const
{
    return 'C';
}

void Carnivoro::cazarPresa() {
    // Lógica para cazar otras criaturas
    cout << "Carnivoro cazando presa..." << endl;
    int exito = 0;
    if (getClima() == 'N') {
        exito = rand() % 100 < 70; // 70% de éxito en la noche
    }
    else if (getClima() == 'T') {
        exito = rand() % 100 < 50; // 50% de éxito en la tarde
    }
    else {
        exito = rand() % 100 < 30; // 30% de éxito en el día
    }

    if (exito) {
        cout << "¡Caza exitosa!" << endl;
        alimentarse(25); // Obtiene mucha energía de una presa
    }
    else {
        cout << "Caza fallida..." << endl;
    }
}

void Carnivoro::Guardar(ofstream& arch){
    arch << tipo << '\t';
    arch << posX << '\t';
    arch << posY << '\t';
    arch << energia << '\t';
    arch << edad << '\t';
    arch << clima << '\n';
}

Criatura* Carnivoro::Lectura(ifstream& arch, Ecosistema* eco) {
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
    Criatura* cri = new Carnivoro(pX, pY, en, eco, cl);
    cri->setEdad(ed);
    return cri;
}

