#include "Recurso.h"

// Implementación de Recurso (clase base)
Recurso::Recurso(int x, int y, int valor)
    : posX(x), posY(y), valorNutricional(valor), tipo("Recurso"),
    disponible(true), tiempoRegeneracion(0) {
}

Recurso::~Recurso() {
}

void Recurso::regenerar() {
    if (!disponible && tiempoRegeneracion <= 0) {
        disponible = true;
        tiempoRegeneracion = 0;
    }
}

int Recurso::serConsumido() {
    if (disponible) {
        disponible = false;
        tiempoRegeneracion = 10; // Tiempo base de regeneración
        return valorNutricional;
    }
    return 0;
}

void Recurso::setPosicion(int x, int y) {
    posX = x;
    posY = y;
}

void Recurso::setDisponible(bool estado) {
    disponible = estado;
}
