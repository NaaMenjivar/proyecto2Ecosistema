#include "Movimiento.h"
#include "Criatura.h"
#include "Matriz.h"

// Constructor
Movimiento::Movimiento(int distancia) : distanciaMaxima(distancia) {
    // Inicialización de la estrategia de movimiento
}

// Destructor
Movimiento::~Movimiento() {
    // Limpieza si es necesario
}

// Método para mover una criatura a una posición específica
bool Movimiento::moverA(Criatura* criatura, int x, int y, Matriz* mat) {
    if (!criatura || !mat) return false;

    if (!mat->dentroLimites(x, y)) return false;

    int oldX = criatura->getPosX(), oldY = criatura->getPosY();
    if (x == oldX && y == oldY) return false;

    int dist = abs(x - oldX) + abs(y - oldY);
    if (dist > distanciaMaxima) return false;

    mat->moverSeguro(oldX, oldY, x, y);
    criatura->setPosicion(x, y);
    criatura->consumirEnergia(dist * 2);
    return true;
}

// Verificar si un movimiento es válido
bool Movimiento::esMovimientoValido(int x, int y, Criatura* criatura) {
    if (criatura == nullptr) {
        return false;
    }

    // Verificar límites del mapa
    if (!estaDentroDelMapa(x, y)) {
        return false;
    }

    // Verificar que no sea la misma posición
    if (x == criatura->getPosX() && y == criatura->getPosY()) {
        return false;
    }

    // Aquí se podría agregar verificación de colisiones con otras criaturas
    // Para hacer las cosas más sencillas, se asume que el movimiento es válido si está en el mapa

    return true;
}

// Calcular distancia entre dos puntos
int Movimiento::calcularDistancia(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    return dx + dy;
}

// Verificar si una posición está dentro del mapa
bool Movimiento::estaDentroDelMapa(int x, int y) {
    // Estos valores deberían venir de una configuración global (recuerda eso)
    const int ANCHO_MAPA = 10;
    const int ALTO_MAPA = 10;

    return (x >= 0 && x < ANCHO_MAPA && y >= 0 && y < ALTO_MAPA);
}