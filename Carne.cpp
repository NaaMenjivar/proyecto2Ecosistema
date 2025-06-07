#include"Carne.h"

// Implementación de Carne
Carne::Carne(int x, int y, int valor)
    : Recurso(x, y, valor), tiempoDescomposicion(20) {
    tipo = "Carne";
    tiempoRegeneracion = -1; // La carne no se regenera naturalmente
}

Carne::~Carne() {
}

void Carne::Operacion() {
    if (disponible) {
        descomponer();
    }
}

void Carne::Update() {
    if (tiempoDescomposicion > 0) {
        tiempoDescomposicion--;
        if (tiempoDescomposicion <= 0) {
            disponible = false;
            valorNutricional = 0;
        }
    }
}

void Carne::descomponer() {
    if (tiempoDescomposicion > 0) {
        valorNutricional = (valorNutricional * tiempoDescomposicion) / 20;
    }
}