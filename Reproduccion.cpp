#include"Reproduccion.h"
#include"Criatura.h"

// ============================================================================
// IMPLEMENTACI�N DE REPRODUCCION
// ============================================================================

Reproduccion::Reproduccion(int energiaMin, int edadMin)
    : energiaMinima(energiaMin), edadMinima(edadMin) {
}

Reproduccion::~Reproduccion() {}

bool Reproduccion::ejecutar(Criatura* c1, Criatura* c2) {
    if (!c1 || !c2) return false;
    // Deben ser mismo tipo
    if (c1->getTipo() != c2->getTipo()) return false;
    // Edad y energ�a m�nima
    if (c1->getEdad() < edadMinima || c2->getEdad() < edadMinima) return false;
    if (c1->getEnergia() < energiaMinima || c2->getEnergia() < energiaMinima) return false;
    // Consumir energ�a de ambos padres
    c1->consumirEnergia(energiaMinima / 2);
    c2->consumirEnergia(energiaMinima / 2);
    return true;
}

string Reproduccion::getTipo() const
{
    return "Reproduccion";
}


