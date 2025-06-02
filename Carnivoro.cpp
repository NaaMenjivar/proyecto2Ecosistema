#include"Carnivoro.h"

// Implementaci�n de Carn�voro
Carnivoro::Carnivoro(int x, int y, int energiaInicial)
    : Criatura(x, y, energiaInicial) {
    tipo = "Carnivoro";
}

Carnivoro::~Carnivoro() {
}

void Carnivoro::Operacion() {
    cazarPresa();
    consumirEnergia(8); // Los carn�voros consumen m�s energ�a
}

void Carnivoro::Update() {
    incrementarEdad();
    consumirEnergia(5); // Metabolismo base m�s alto
}

Criatura* Carnivoro::reproducirse() {
    if (puedeReproducirse()) {
        consumirEnergia(70);
        return new Carnivoro(posX, posY, 120);
    }
    return nullptr;
}

void Carnivoro::cazarPresa() {
    // L�gica para cazar otras criaturas
    cout << "Carnivoro cazando presa..." << endl;
}