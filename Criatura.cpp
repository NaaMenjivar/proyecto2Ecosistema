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
Criatura::Criatura(int x, int y, int energiaInicial, Ecosistema* e, char cl)
    : posX(x), posY(y), energia(energiaInicial), edad(0), tipo("Criatura"), Observer(e,cl) {
}

Criatura::~Criatura() {}

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



