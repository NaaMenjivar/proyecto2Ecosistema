#include"Agua.h"

// Implementación de Agua
Agua::Agua(int x, int y, int valor, Ecosistema* e, char cli)
    : Recurso(x, y, valor, e, cli), pureza(100) {
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