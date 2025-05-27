/* -------------------------------------------------------------------+
* |
* (c) 2025 |
* EIF204 - Programaci�n 2 |
* 1er ciclo 2025 |
* NRC 9999 � Grupo 00 |
* Proyecto 2 |
* |
* 1-1977-0345; Menj�var Ram�rez, Naara |
* 1-1905-0975; Chaves Salazar, Sebasti�n |
* A-0015-0163; Briones Rocha, Jordan |
* |
* versi�n 1.0.0 2025-06-01 |
* |
* -------------------------------------------------------------------+
*/

#include "Criatura.h"

// Implementaci�n de Criatura (clase base)
Criatura::Criatura(int x, int y, int energiaInicial)
    : posX(x), posY(y), energia(energiaInicial), edad(0), tipo("Criatura") {
}

Criatura::~Criatura() {
}

void Criatura::mover(int nuevaX, int nuevaY) {
    posX = nuevaX;
    posY = nuevaY;
    consumirEnergia(5); // Moverse consume energ�a
}

void Criatura::alimentarse(int energiaObtenida) {
    energia += energiaObtenida;
    if (energia > 200) energia = 200; // L�mite m�ximo de energ�a
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

// Implementaci�n de Herb�voro
Herbivoro::Herbivoro(int x, int y, int energiaInicial)
    : Criatura(x, y, energiaInicial) {
    tipo = "Herbivoro";
}

Herbivoro::~Herbivoro() {
}

void Herbivoro::Operacion() {
    buscarPlantas();
    consumirEnergia(3); // Los herb�voros consumen menos energ�a
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
    // L�gica para buscar plantas cercanas
    cout << "Herbivoro buscando plantas..." << endl;
}

// Implementaci�n de Carn�voro
Carnivoro::Carnivoro(int x, int y, int energiaInicial)
    : Criatura(x, y, energiaInicial) {
    tipo = "Carnivoro";
}

Carnivoro::~Carnivoro() {
}

void Carnivoro::Operacion() {
    cazarPresa();
    consumirEnergia(8); // Los carn�voros consumen m�s energ�a
}

void Carnivoro::Update() {
    incrementarEdad();
    consumirEnergia(5); // Metabolismo base m�s alto
}

Criatura* Carnivoro::reproducirse() {
    if (puedeReproducirse()) {
        consumirEnergia(70);
        return new Carnivoro(posX, posY, 120);
    }
    return nullptr;
}

void Carnivoro::cazarPresa() {
    // L�gica para cazar otras criaturas
    cout << "Carnivoro cazando presa..." << endl;
}

// Implementaci�n de Omn�voro
Omnivoro::Omnivoro(int x, int y, int energiaInicial)
    : Criatura(x, y, energiaInicial) {
    tipo = "Omnivoro";
}

Omnivoro::~Omnivoro() {
}

void Omnivoro::Operacion() {
    buscarAlimento();
    consumirEnergia(5); // Consumo medio de energ�a
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
    // L�gica para buscar tanto plantas como presas
    cout << "Omnivoro buscando alimento..." << endl;
}