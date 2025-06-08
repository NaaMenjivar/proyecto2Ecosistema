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
Criatura::Criatura(int x, int y, int energiaInicial, Ecosistema* e, char cl)
    : posX(x), posY(y), energia(energiaInicial), edad(0), tipo("Criatura"), Observer(e,cl) {
}

Criatura::~Criatura() {}

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



