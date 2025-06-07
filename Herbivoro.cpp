#include"Herbivoro.h"

// Implementación de Herbívoro
Herbivoro::Herbivoro(int x, int y, int energiaInicial)
    : Criatura(x, y, energiaInicial) {
    tipo = "Herbivoro";
}

Herbivoro::~Herbivoro() {
}

void Herbivoro::Operacion() {
    buscarPlantas();
    consumirEnergia(3); // Los herbívoros consumen menos energía
}

void Herbivoro::Update() {
    incrementarEdad();
    consumirEnergia(2); // Metabolismo base
}

Criatura* Herbivoro::reproducirse() {
    if (puedeReproducirse()) {
        consumirEnergia(50);
        return new Herbivoro(posX, posY, 80);
    }
    return nullptr;
}

void Herbivoro::buscarPlantas() {
    // Lógica para buscar plantas cercanas
    cout << "Herbivoro buscando plantas..." << endl;
}