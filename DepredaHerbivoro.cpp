#include"DepredaHerbivoro.h"
#include"Criatura.h"
#include"Herbivoro.h"

// ============================================================================
// IMPLEMENTACI�N DE DEPREDAHERBIVORO
// ============================================================================

DepredaHerbivoro::DepredaHerbivoro(int fuerza)
    : Alimentacion("Herbivoro"), fuerzaAtaque(fuerza) {
}

DepredaHerbivoro::~DepredaHerbivoro() {
}

bool DepredaHerbivoro::ejecutar(Criatura* criatura,Criatura* her) {
    if (criatura == nullptr || criatura->getTipo() != "Carnivoro") {
        return false;
    }

    Herbivoro* herbivoro = dynamic_cast<Herbivoro*>(her);
    if (herbivoro != nullptr) {
        return atacarHerbivoro(criatura, herbivoro);
    }

    return false;
}

bool DepredaHerbivoro::atacarHerbivoro(Criatura* carnivoro, Herbivoro* herbivoro) {
    if (carnivoro == nullptr || herbivoro == nullptr) {
        return false;
    }

    // Calcular distancia para verificar si est� en rango
    int distancia = calcularDistancia(carnivoro->getPosX(), carnivoro->getPosY(),
        herbivoro->getPosX(), herbivoro->getPosY());


    // Realizar ataque
    carnivoro->alimentarse(fuerzaAtaque);

    // El herb�voro pierde energ�a o muere
    herbivoro->consumirEnergia(fuerzaAtaque * 2);

    return true;
}