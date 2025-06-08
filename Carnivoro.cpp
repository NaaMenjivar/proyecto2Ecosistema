#include"Carnivoro.h"

// Implementaci�n de Carn�voro
Carnivoro::Carnivoro(int x, int y, int energiaInicial, Ecosistema* e, char cl)
    : Criatura(x, y, energiaInicial, e, cl) {
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

    if (getClima() == 'N') {
        // Durante la noche pueden cazar mejor
        cout << "Carnivoro aprovecha la noche para cazar" << endl;
        alimentarse(5);
    }
    else if (getClima() == 'D') {
        // Durante el d�a gastan m�s energ�a por el calor
        consumirEnergia(2);
    }
}

Criatura* Carnivoro::reproducirse() {
    if (puedeReproducirse()) { 
        consumirEnergia(70);
        return new Carnivoro(posX, posY, 120, eco, clima); 
    }
    return nullptr;
}

void Carnivoro::cazarPresa() {
    // L�gica para cazar otras criaturas
    cout << "Carnivoro cazando presa..." << endl;
    int exito = 0;
    if (getClima() == 'N') {
        exito = rand() % 100 < 70; // 70% de �xito en la noche
    }
    else if (getClima() == 'T') {
        exito = rand() % 100 < 50; // 50% de �xito en la tarde
    }
    else {
        exito = rand() % 100 < 30; // 30% de �xito en el d�a
    }

    if (exito) {
        cout << "�Caza exitosa!" << endl;
        alimentarse(25); // Obtiene mucha energ�a de una presa
    }
    else {
        cout << "Caza fallida..." << endl;
    }
}