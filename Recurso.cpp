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

// Implementación de Agua
Agua::Agua(int x, int y, int valor)
    : Recurso(x, y, valor), pureza(100) {
    tipo = "Agua";
}

Agua::~Agua() {
}

void Agua::Operacion() {
    if (tiempoRegeneracion > 0) {
        tiempoRegeneracion--;
    }
    regenerar();
}

void Agua::Update() {
    // El agua se mantiene relativamente estable
    if (pureza > 50) {
        pureza--;
    }
}

void Agua::regenerar() {
    if (!disponible && tiempoRegeneracion <= 0) {
        disponible = true;
        tiempoRegeneracion = 0;
        pureza = 100; // El agua se renueva con pureza máxima
    }
}

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