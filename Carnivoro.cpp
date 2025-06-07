#include"Carnivoro.h"

// Implementación de Carnívoro
Carnivoro::Carnivoro(int x, int y, int energiaInicial)
    : Criatura(x, y, energiaInicial) {
    tipo = "Carnivoro";
}

Carnivoro::~Carnivoro() {
}

void Carnivoro::Operacion() {
    cazarPresa();
    consumirEnergia(8); // Los carnívoros consumen más energía
}

void Carnivoro::Update() {
    incrementarEdad();
    consumirEnergia(5); // Metabolismo base más alto
}

Criatura* Carnivoro::reproducirse() {
    if (puedeReproducirse()) {
        consumirEnergia(70);
        return new Carnivoro(posX, posY, 120);
    }
    return nullptr;
}

void Carnivoro::cazarPresa() {
    // Lógica para cazar otras criaturas
    cout << "Carnivoro cazando presa..." << endl;
}