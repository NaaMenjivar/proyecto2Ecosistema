#include"Planta.h"


// Implementación de Planta
Planta::Planta(int x, int y, int valor)
    : Recurso(x, y, valor), nivelCrecimiento(50) {
    tipo = "Planta";
}

Planta::~Planta() {
}

void Planta::Operacion() {
    if (disponible) {
        crecer();
    }
    else if (tiempoRegeneracion > 0) {
        tiempoRegeneracion--;
        regenerar();
    }
}

void Planta::Update() {
    // Las plantas crecen gradualmente
    if (nivelCrecimiento < 100 && disponible) {
        nivelCrecimiento += 2;
        valorNutricional = (60 * nivelCrecimiento) / 100;
    }
}

void Planta::regenerar() {
    if (!disponible && tiempoRegeneracion <= 0) {
        disponible = true;
        nivelCrecimiento = 30; // Rebrote con crecimiento inicial
        valorNutricional = 20;
        tiempoRegeneracion = 0;
    }
}

void Planta::crecer() {
    if (nivelCrecimiento < 100) {
        nivelCrecimiento++;
        valorNutricional = (60 * nivelCrecimiento) / 100;
    }
}