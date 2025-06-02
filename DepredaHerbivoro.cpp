#include"DepredaHerbivoro.h"
#include"Criatura.h"
#include"Herbivoro.h"

// ============================================================================
// IMPLEMENTACIÓN DE DEPREDAHERBIVORO
// ============================================================================

DepredaHerbivoro::DepredaHerbivoro(int rango, int fuerza)
    : Alimentacion(rango, "Herbivoro"), fuerzaAtaque(fuerza) {
}

DepredaHerbivoro::~DepredaHerbivoro() {
}

bool DepredaHerbivoro::ejecutar(Criatura* criatura) {
    if (criatura == nullptr || criatura->getTipo() != "Carnivoro") {
        return false;
    }

    Herbivoro* herbivoro = buscarHerbivoro(criatura);
    if (herbivoro != nullptr) {
        return atacarHerbivoro(criatura, herbivoro);
    }

    return false;
}

bool DepredaHerbivoro::atacarHerbivoro(Criatura* carnivoro, Herbivoro* herbivoro) {
    if (carnivoro == nullptr || herbivoro == nullptr) {
        return false;
    }

    // Calcular distancia para verificar si está en rango
    int distancia = calcularDistancia(carnivoro->getPosX(), carnivoro->getPosY(),
        herbivoro->getPosX(), herbivoro->getPosY());

    if (distancia > rangoDeteccion) {
        return false;
    }

    // Realizar ataque
    carnivoro->alimentarse(fuerzaAtaque);

    // El herbívoro pierde energía o muere
    herbivoro->consumirEnergia(fuerzaAtaque * 2);

    return true;
}

Herbivoro* DepredaHerbivoro::buscarHerbivoro(Criatura* carnivoro) {
    // en implementación real buscaría en el ecosistema
    return nullptr;
}