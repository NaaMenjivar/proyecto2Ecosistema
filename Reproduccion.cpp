#include"Reproduccion.h"
#include"Criatura.h"

// ============================================================================
// IMPLEMENTACIÓN DE REPRODUCCION
// ============================================================================

Reproduccion::Reproduccion(int energiaMin, int edadMin, int rango)
    : energiaMinima(energiaMin), edadMinima(edadMin), rangoPareja(rango) {
}

Reproduccion::~Reproduccion() {}

bool Reproduccion::ejecutar(Criatura* criatura, Criatura* cri) {
    if (criatura == nullptr) {
        return false;
    }

    if (!puedeReproducirse(criatura)) {
        return false;
    }

    Criatura* pareja = cri;
    if (pareja != nullptr) {
        return intentarReproduccion(criatura, cri);
    }

    return false;
}

string Reproduccion::getTipo() const
{
    return "Reproduccion";
}

bool Reproduccion::puedeReproducirse(Criatura* criatura) {
    if (criatura == nullptr) {
        return false;
    }

    return (criatura->getEnergia() >= energiaMinima &&
        criatura->getEdad() >= edadMinima);
}

Criatura* Reproduccion::buscarPareja(Criatura* criatura) {
    // en implementación real buscaría parejas compatibles
    return nullptr;
}

bool Reproduccion::intentarReproduccion(Criatura* criatura, Criatura* pareja) {
    if (criatura == nullptr || pareja == nullptr) {
        return false;
    }

    if (!sonCompatibles(criatura, pareja)) {
        return false;
    }

    // Verificar distancia
    int distancia = calcularDistancia(criatura->getPosX(), criatura->getPosY(),
        pareja->getPosX(), pareja->getPosY());

    if (distancia > rangoPareja) {
        return false;
    }

    // Realizar reproducción
    Criatura* cria = criatura->reproducirse();
    if (cria != nullptr) {
        // Consumir energía de ambos padres
        criatura->consumirEnergia(energiaMinima / 2);
        pareja->consumirEnergia(energiaMinima / 2);
        return true;
    }

    return false;
}

bool Reproduccion::sonCompatibles(Criatura* criatura1, Criatura* criatura2) {
    if (criatura1 == nullptr || criatura2 == nullptr) {
        return false;
    }

    // Deben ser del mismo tipo y ambos poder reproducirse
    return (criatura1->getTipo() == criatura2->getTipo() &&
        puedeReproducirse(criatura1) &&
        puedeReproducirse(criatura2));
}

int Reproduccion::calcularDistancia(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    return dx + dy;
}