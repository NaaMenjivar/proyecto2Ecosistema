#include"TomaAgua.h"
#include"Recurso.h"

// ============================================================================
// IMPLEMENTACIÓN DE TOMAAGUA
// ============================================================================

TomaAgua::TomaAgua() : Alimentacion("Agua") {
}

TomaAgua::~TomaAgua() {
}

bool TomaAgua::ejecutar(Criatura* criatura, Recurso* rec) {
    if (criatura == nullptr) {
        return false;
    }

    Recurso* agua = rec;
    if (agua != nullptr) {
        return consumirRecurso(criatura, agua);
    }

    return false;
}

bool TomaAgua::esRecursoCompatible(Recurso* recurso) {
    return (recurso != nullptr && recurso->getTipo() == "Agua");
}