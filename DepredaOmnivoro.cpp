#include"DepredaOmnivoro.h"
#include"Criatura.h"
#include"Omnivoro.h"

// ============================================================================
// IMPLEMENTACIÓN DE DEPREDAOMNIVORO
// ============================================================================

DepredaOmnivoro::DepredaOmnivoro(int rango, int fuerza)
    : Alimentacion(rango, "Omnivoro"), fuerzaAtaque(fuerza) {
}

DepredaOmnivoro::~DepredaOmnivoro() {
}

bool DepredaOmnivoro::ejecutar(Criatura* criatura) {
    if (criatura == nullptr || criatura->getTipo() != "Carnivoro") {
        return false;
    }

    Omnivoro* omnivoro = buscarOmnivoro(criatura);
    if (omnivoro != nullptr) {
        return atacarOmnivoro(criatura, omnivoro);
    }

    return false;
}

bool DepredaOmnivoro::atacarOmnivoro(Criatura* carnivoro, Omnivoro* omnivoro) {
    if (carnivoro == nullptr || omnivoro == nullptr) {
        return false;
    }

    // Calcular distancia para verificar si está en rango
    int distancia = calcularDistancia(carnivoro->getPosX(), carnivoro->getPosY(),
        omnivoro->getPosX(), omnivoro->getPosY());

    if (distancia > rangoDeteccion) {
        return false;
    }

    // Realizar ataque
    carnivoro->alimentarse(fuerzaAtaque);

    // El omnívoro pierde energía o muere
    omnivoro->consumirEnergia(fuerzaAtaque * 2);

    return true;
}

Omnivoro* DepredaOmnivoro::buscarOmnivoro(Criatura* carnivoro) {
    // en implementación real buscaría en el ecosistema
    return nullptr;
}
