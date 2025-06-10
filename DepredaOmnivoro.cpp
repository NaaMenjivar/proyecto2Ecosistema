#include"DepredaOmnivoro.h"
#include"Criatura.h"
#include"Omnivoro.h"

// ============================================================================
// IMPLEMENTACI�N DE DEPREDAOMNIVORO
// ============================================================================

DepredaOmnivoro::DepredaOmnivoro(int fuerza)
    : Alimentacion("Omnivoro"), fuerzaAtaque(fuerza) {
}

DepredaOmnivoro::~DepredaOmnivoro() {
}

bool DepredaOmnivoro::ejecutar(Criatura* criatura, Criatura* om) {
    if (criatura == nullptr || criatura->getTipo() != "Carnivoro") {
        return false;
    }

    Omnivoro* omnivoro = dynamic_cast<Omnivoro*>(om);
    if (omnivoro != nullptr) {
        return atacarOmnivoro(criatura, omnivoro);
    }

    return false;
}

bool DepredaOmnivoro::atacarOmnivoro(Criatura* carnivoro, Omnivoro* omnivoro) {
    if (carnivoro == nullptr || omnivoro == nullptr) {
        return false;
    }

    // Calcular distancia para verificar si est� en rango
    int distancia = calcularDistancia(carnivoro->getPosX(), carnivoro->getPosY(),
        omnivoro->getPosX(), omnivoro->getPosY());

    // Realizar ataque
    carnivoro->alimentarse(fuerzaAtaque);

    // El omn�voro pierde energ�a o muere
    omnivoro->consumirEnergia(fuerzaAtaque * 2);

    return true;
}
