#include"DepredaHerbivoro.h"
#include"Criatura.h"
#include"Herbivoro.h"

// ============================================================================
// IMPLEMENTACIÓN DE DEPREDAHERBIVORO
// ============================================================================

DepredaHerbivoro::DepredaHerbivoro() : DepredaHerbivoro(100) {} 

DepredaHerbivoro::DepredaHerbivoro(int fuerza)
    : Alimentacion("Herbivoro"), fuerzaAtaque(fuerza) {
}

DepredaHerbivoro::~DepredaHerbivoro() {
}

bool DepredaHerbivoro::ejecutar(Criatura* criatura,Criatura* her) {
    if (criatura == nullptr || criatura->getTipo() != "Carnivoro") {
        return false;
    }

    Herbivoro* hb = dynamic_cast<Herbivoro*>(her);
    return hb ? atacarHerbivoro(criatura, hb) : false;
}

string DepredaHerbivoro::getTipo() const
{
    return "DepredaHerbivoro";
}

bool DepredaHerbivoro::atacarHerbivoro(Criatura* carnivoro, Herbivoro* herbivoro) {
    if (!carnivoro || !herbivoro) return false;
    carnivoro->alimentarse(fuerzaAtaque);
    herbivoro->consumirEnergia(fuerzaAtaque * 2);
    return true;
}