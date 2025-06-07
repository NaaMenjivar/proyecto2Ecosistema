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
    if (criatura == nullptr) {
        return false;
    }

    moverAleatoriamente(criatura);
    return true;
}

void CambiaDireccion::moverAleatoriamente(Criatura* criatura) {
    if (criatura == nullptr) {
        return;
    }

    int direccion = generarDireccionAleatoria();
    int nuevaX = criatura->getPosX();
    int nuevaY = criatura->getPosY();

    // Calcular nueva posición basada en la dirección
    switch (direccion) {
    case 0: nuevaY -= distanciaMaxima; break; // Norte
    case 1: nuevaX += distanciaMaxima; break; // Este
    case 2: nuevaY += distanciaMaxima; break; // Sur
    case 3: nuevaX -= distanciaMaxima; break; // Oeste
    }

    moverA(criatura, nuevaX, nuevaY);
}

int CambiaDireccion::generarDireccionAleatoria() {
    // Implementación simple sin usar rand()
    static int contador = 0;
    contador = (contador + 7) % 4; // Usar 7 para que varíe más
    return contador;
}