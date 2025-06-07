#include"Omnivoro.h"

// Implementaci�n de Omn�voro
Omnivoro::Omnivoro(int x, int y, int energiaInicial)
    : Criatura(x, y, energiaInicial) {
    tipo = "Omnivoro";
}

Omnivoro::~Omnivoro() {
}

void Omnivoro::Operacion() {
    buscarAlimento();
    consumirEnergia(5); // Consumo medio de energ�a
}

void Omnivoro::Update() {
    incrementarEdad();
    consumirEnergia(3); // Metabolismo base medio
}

Criatura* Omnivoro::reproducirse() {
    if (puedeReproducirse()) {
        consumirEnergia(60);
        return new Omnivoro(posX, posY, 100);
    }
    return nullptr;
}

void Omnivoro::buscarAlimento() {
    // L�gica para buscar tanto plantas como presas
    cout << "Omnivoro buscando alimento..." << endl;
}