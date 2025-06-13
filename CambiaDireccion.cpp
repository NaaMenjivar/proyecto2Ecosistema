#include"CambiaDireccion.h"
#include"Criatura.h"

// ============================================================================
// IMPLEMENTACIÓN DE CAMBIADIRECCION
// ============================================================================

CambiaDireccion::CambiaDireccion(int distancia) : Movimiento(distancia) {
}

CambiaDireccion::~CambiaDireccion() {
}

bool CambiaDireccion::ejecutar(Criatura* criatura) {
    if (!criatura) return false;
    moverAleatoriamente(criatura);
    return true;
}

void CambiaDireccion::moverAleatoriamente(Criatura* criatura) {
    int dir = rand() % 4;
    int nx = criatura->getPosX(), ny = criatura->getPosY();
    switch (dir) {
    case 0: ny -= distanciaMaxima; break;
    case 1: nx += distanciaMaxima; break;
    case 2: ny += distanciaMaxima; break;
    case 3: nx -= distanciaMaxima; break;
    }
    // Aquí no comprobamos límites: lo hará Matriz::moverSeguro
    criatura->setPosicion(nx, ny);
}

int CambiaDireccion::generarDireccionAleatoria() {
    return rand() % 4;
}