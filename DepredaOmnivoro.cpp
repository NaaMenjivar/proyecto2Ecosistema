#include"DepredaOmnivoro.h"
#include"Criatura.h"
#include"Omnivoro.h"

// ============================================================================
// IMPLEMENTACIÓN DE DEPREDAOMNIVORO
// ============================================================================

DepredaOmnivoro::DepredaOmnivoro() : DepredaOmnivoro(20) {}

DepredaOmnivoro::DepredaOmnivoro(int fuerza)
    : Alimentacion("Omnivoro"), fuerzaAtaque(fuerza) {
}

DepredaOmnivoro::~DepredaOmnivoro() {
}

bool DepredaOmnivoro::ejecutar(Criatura* criatura, Criatura* om) {
    if (criatura == nullptr || criatura->getTipo() != "Carnivoro") {
        return false;
    }

    Omnivoro* omn = dynamic_cast<Omnivoro*>(om);
    return omn ? atacarOmnivoro(criatura, omn) : false;
}

string DepredaOmnivoro::getTipo() const
{
    return "DepredaOmnivoro";
}

bool DepredaOmnivoro::atacarOmnivoro(Criatura* carnivoro, Omnivoro* omnivoro) {
    if (!carnivoro || !omnivoro) return false;
    carnivoro->alimentarse(fuerzaAtaque);
    omnivoro->consumirEnergia(fuerzaAtaque * 2);
    return true;
}
