#include"CambiaDireccion.h"
#include"Criatura.h"
#include "Matriz.h"

// ============================================================================
// IMPLEMENTACIÓN DE CAMBIADIRECCION
// ============================================================================

CambiaDireccion::CambiaDireccion(int distancia) : Movimiento(distancia) {
}

CambiaDireccion::~CambiaDireccion() {
}

bool CambiaDireccion::ejecutar(Criatura* criatura, Matriz* mat) {
    if (!criatura || !mat) return false;
    int nx, ny;
    moverAleatoriamente(criatura, nx, ny);
    return moverA(criatura, nx, ny, mat);
}

void CambiaDireccion::moverAleatoriamente(Criatura* criatura, int& nX, int& nY) {
    int dir = generarDireccionAleatoria();
    nX = criatura->getPosX();
    nY = criatura->getPosY();
    switch (dir) {
    case 0: nY -= distanciaMaxima; break; // Norte
    case 1: nX += distanciaMaxima; break; // Este
    case 2: nY += distanciaMaxima; break; // Sur
    case 3: nX -= distanciaMaxima; break; // Oeste
    }
}

int CambiaDireccion::generarDireccionAleatoria() {
    return rand() % 4;
}