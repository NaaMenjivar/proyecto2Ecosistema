#include "Decorador.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Implementación de Decorador base
Decorador::Decorador(Criatura* criatura) : Criatura(0, 0, "decorado"), criaturaDecorada(criatura) {
}

Decorador::~Decorador() {
    // No eliminamos criaturaDecorada aquí para evitar double deletion
}

void Decorador::Operacion() {
    if (criaturaDecorada) {
        criaturaDecorada->Operacion();
    }
}

void Decorador::Update() {
    if (criaturaDecorada) {
        criaturaDecorada->Update();
    }
}

void Decorador::mover(int nuevaX, int nuevaY) {
    if (criaturaDecorada) {
        criaturaDecorada->mover(nuevaX, nuevaY);
    }
}

void Decorador::alimentarse(int energiaObtenida) {
    if (criaturaDecorada) {
        criaturaDecorada->alimentarse(energiaObtenida);
    }
}

bool Decorador::puedeReproducirse() const {
    return criaturaDecorada ? criaturaDecorada->puedeReproducirse() : false;
}

Criatura* Decorador::reproducirse() {
    return criaturaDecorada ? criaturaDecorada->reproducirse() : nullptr;
}

Criatura* Decorador::getCriaturaDecorada() const {
    return criaturaDecorada;
}

// Implementación de DecoradorVelocidad
DecoradorVelocidad::DecoradorVelocidad(Criatura* criatura, int multiplicador)
    : Decorador(criatura), multiplicadorVelocidad(multiplicador), movimientosExtraPorTick(multiplicador - 1) {
}

DecoradorVelocidad::~DecoradorVelocidad() {
}

void DecoradorVelocidad::Operacion() {
    Decorador::Operacion();
    realizarMovimientosExtra();
}

void DecoradorVelocidad::Update() {
    Decorador::Update();
}

void DecoradorVelocidad::mover(int nuevaX, int nuevaY) {
    Decorador::mover(nuevaX, nuevaY);

    // Movimientos adicionales por velocidad
    for (int i = 0; i < movimientosExtraPorTick && criaturaDecorada; i++) {
        int deltaX = (rand() % 3) - 1;
        int deltaY = (rand() % 3) - 1;
        int nuevoX = nuevaX + deltaX;
        int nuevoY = nuevaY + deltaY;

        if (nuevoX >= 0 && nuevoX < 50 && nuevoY >= 0 && nuevoY < 50) {
            Decorador::mover(nuevoX, nuevoY);
        }
    }
}

void DecoradorVelocidad::realizarMovimientosExtra() {
    cout << "Criatura con velocidad mejorada" << endl;
}

void DecoradorVelocidad::setMultiplicadorVelocidad(int multiplicador) {
    multiplicadorVelocidad = multiplicador;
    movimientosExtraPorTick = multiplicador - 1;
}

int DecoradorVelocidad::getMultiplicadorVelocidad() const {
    return multiplicadorVelocidad;
}

Criatura* DecoradorVelocidad::reproducirse() {
    Criatura* nuevaCriatura = Decorador::reproducirse();
    if (nuevaCriatura) {
        return new DecoradorVelocidad(nuevaCriatura, multiplicadorVelocidad);
    }
    return nullptr;
}

// Implementación de DecoradorResistencia
DecoradorResistencia::DecoradorResistencia(Criatura* criatura, int resistencia)
    : Decorador(criatura), resistenciaExtra(resistencia), reduccionConsumoEnergia(resistencia / 10) {
}

DecoradorResistencia::~DecoradorResistencia() {
}

void DecoradorResistencia::Update() {
    Decorador::Update();
    aplicarResistencia();
}

void DecoradorResistencia::alimentarse(int energiaObtenida) {
    int energiaMejorada = energiaObtenida + (energiaObtenida * resistenciaExtra / 100);
    Decorador::alimentarse(energiaMejorada);
}

void DecoradorResistencia::aplicarResistencia() {
    cout << "Aplicando resistencia extra" << endl;
}

void DecoradorResistencia::setResistenciaExtra(int resistencia) {
    resistenciaExtra = resistencia;
    reduccionConsumoEnergia = resistencia / 10;
}

int DecoradorResistencia::getResistenciaExtra() const {
    return resistenciaExtra;
}

Criatura* DecoradorResistencia::reproducirse() {
    Criatura* nuevaCriatura = Decorador::reproducirse();
    if (nuevaCriatura) {
        return new DecoradorResistencia(nuevaCriatura, resistenciaExtra);
    }
    return nullptr;
}

// Implementación de DecoradorLongevidad
DecoradorLongevidad::DecoradorLongevidad(Criatura* criatura, int factor)
    : Decorador(criatura), factorLongevidad(factor), edadMaximaExtra(factor * 50) {
}

DecoradorLongevidad::~DecoradorLongevidad() {
}

void DecoradorLongevidad::Update() {
    if (deberiaEnvejecer()) {
        Decorador::Update();
    }
}

bool DecoradorLongevidad::puedeReproducirse() const {
    return Decorador::puedeReproducirse();
}

bool DecoradorLongevidad::deberiaEnvejecer() const {
    return (rand() % factorLongevidad) == 0;
}

void DecoradorLongevidad::setFactorLongevidad(int factor) {
    factorLongevidad = factor;
    edadMaximaExtra = factor * 50;
}

int DecoradorLongevidad::getFactorLongevidad() const {
    return factorLongevidad;
}

Criatura* DecoradorLongevidad::reproducirse() {
    Criatura* nuevaCriatura = Decorador::reproducirse();
    if (nuevaCriatura) {
        return new DecoradorLongevidad(nuevaCriatura, factorLongevidad);
    }
    return nullptr;
}
