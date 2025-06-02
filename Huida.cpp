#include"Huida.h"
#include"Criatura.h"

// ============================================================================
// IMPLEMENTACI�N DE HUIDA
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
    // en implementaci�n real verificar�a carn�voros cercanos
    // Por ahora asumimos que no hay peligro
    return false;
}

void Huida::huirDePeligro(Criatura* criatura) {
    if (criatura == nullptr) {
        return;
    }

    // Generar una direcci�n aleatoria para huir
    int direccion = generarDireccionAleatoria();
    int nuevaX = criatura->getPosX();
    int nuevaY = criatura->getPosY();

    // Calcular nueva posici�n basada en la direcci�n
    switch (direccion) {
    case 0: nuevaY -= distanciaMaxima; break; // Norte
    case 1: nuevaX += distanciaMaxima; break; // Este
    case 2: nuevaY += distanciaMaxima; break; // Sur
    case 3: nuevaX -= distanciaMaxima; break; // Oeste
    }

    moverA(criatura, nuevaX, nuevaY);
}

int Huida::generarDireccionAleatoria() {
    // Implementaci�n simple sin usar rand()
    static int contador = 0;
    contador = (contador + 1) % 4;
    return contador;
}