#include"ComePlanta.h"
#include"Recurso.h"

// ============================================================================
// IMPLEMENTACIÓN DE COMEPLANTA
// ============================================================================

ComePlanta::ComePlanta(int rango) : Alimentacion(rango, "Planta") {
}

ComePlanta::~ComePlanta() {
}

bool ComePlanta::ejecutar(Criatura* criatura) {
    if (criatura == nullptr) {
        return false;
    }

    Recurso* planta = buscarRecurso(criatura);
    if (planta != nullptr) {
        return consumirRecurso(criatura, planta);
    }

    return false;
}

bool ComePlanta::esRecursoCompatible(Recurso* recurso) {
    return (recurso != nullptr && recurso->getTipo() == "Planta");
}
