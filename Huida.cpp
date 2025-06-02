#include"Huida.h"
#include"Criatura.h"

// ============================================================================
// IMPLEMENTACIÓN DE HUIDA
// ============================================================================

Huida::Huida(int distancia, int rango)
    : Movimiento(distancia), rangoPeligro(rango) {
}

Huida::~Huida() {
}

bool Huida::ejecutar(Criatura* criatura) {
    if (criatura == nullptr) {
        return false;
    }

    if (hayPeligroCerca(criatura)) {
        huirDePeligro(criatura);
        return true;
    }

    return false;
}

bool Huida::hayPeligroCerca(Criatura* criatura) {
    // en implementación real verificaría carnívoros cercanos
    // Por ahora asumimos que no hay peligro
    return false;
}

void Huida::huirDePeligro(Criatura* criatura) {
    if (criatura == nullptr) {
        return;
    }

    // Generar una dirección aleatoria para huir
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

int Huida::generarDireccionAleatoria() {
    // Implementación simple sin usar rand()
    static int contador = 0;
    contador = (contador + 1) % 4;
    return contador;
}