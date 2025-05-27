/* -------------------------------------------------------------------+
* |
* (c) 2025 |
* EIF204 - Programación 2 |
* 1er ciclo 2025 |
* NRC 9999 – Grupo 00 |
* Proyecto 2 |
* |
* 1-1977-0345; Menjívar Ramírez, Naara |
* 1-1905-0975; Chaves Salazar, Sebastián |
* A-0015-0163; Briones Rocha, Jordan |
* |
* versión 1.0.0 2025-06-01 |
* |
* -------------------------------------------------------------------+
*/

#include "Criatura.h"

// Implementación de Criatura (clase base)
Criatura::Criatura(int x, int y, int energiaInicial)
    : posX(x), posY(y), energia(energiaInicial), edad(0), tipo("Criatura") {
}

Criatura::~Criatura() {
}

void Criatura::mover(int nuevaX, int nuevaY) {
    posX = nuevaX;
    posY = nuevaY;
    consumirEnergia(5); // Moverse consume energía
}

void Criatura::alimentarse(int energiaObtenida) {
    energia += energiaObtenida;
    if (energia > 200) energia = 200; // Límite máximo de energía
}

bool Criatura::puedeReproducirse() const {
    return energia > 150 && edad > 10;
}

void Criatura::setPosicion(int x, int y) {
    posX = x;
    posY = y;
}

void Criatura::consumirEnergia(int cantidad) {
    energia -= cantidad;
    if (energia < 0) energia = 0;
}

void Criatura::incrementarEdad() {
    edad++;
}

bool Criatura::estaViva() const {
    return energia > 0;
}

// Implementación de Herbívoro
Herbivoro::Herbivoro(int x, int y, int energiaInicial)
    : Criatura(x, y, energiaInicial) {
    tipo = "Herbivoro";
}

Herbivoro::~Herbivoro() {
}

void Herbivoro::Operacion() {
    buscarPlantas();
    consumirEnergia(3); // Los herbívoros consumen menos energía
}

void Herbivoro::Update() {
    incrementarEdad();
    consumirEnergia(2); // Metabolismo base
}

Criatura* Herbivoro::reproducirse() {
    if (puedeReproducirse()) {
        consumirEnergia(50);
        return new Herbivoro(posX, posY, 80);
    }
    return nullptr;
}

void Herbivoro::buscarPlantas() {
    // Lógica para buscar plantas cercanas
    cout << "Herbivoro buscando plantas..." << endl;
}

// Implementación de Carnívoro
Carnivoro::Carnivoro(int x, int y, int energiaInicial)
    : Criatura(x, y, energiaInicial) {
    tipo = "Carnivoro";
}

Carnivoro::~Carnivoro() {
}

void Carnivoro::Operacion() {
    cazarPresa();
    consumirEnergia(8); // Los carnívoros consumen más energía
}

void Carnivoro::Update() {
    incrementarEdad();
    consumirEnergia(5); // Metabolismo base más alto
}

Criatura* Carnivoro::reproducirse() {
    if (puedeReproducirse()) {
        consumirEnergia(70);
        return new Carnivoro(posX, posY, 120);
    }
    return nullptr;
}

void Carnivoro::cazarPresa() {
    // Lógica para cazar otras criaturas
    cout << "Carnivoro cazando presa..." << endl;
}

// Implementación de Omnívoro
Omnivoro::Omnivoro(int x, int y, int energiaInicial)
    : Criatura(x, y, energiaInicial) {
    tipo = "Omnivoro";
}

Omnivoro::~Omnivoro() {
}

void Omnivoro::Operacion() {
    buscarAlimento();
    consumirEnergia(5); // Consumo medio de energía
}

void Omnivoro::Update() {
    incrementarEdad();
    consumirEnergia(3); // Metabolismo base medio
}

Criatura* Omnivoro::reproducirse() {
    if (puedeReproducirse()) {
        consumirEnergia(60);
        return new Omnivoro(posX, posY, 100);
    }
    return nullptr;
}

void Omnivoro::buscarAlimento() {
    // Lógica para buscar tanto plantas como presas
    cout << "Omnivoro buscando alimento..." << endl;
}