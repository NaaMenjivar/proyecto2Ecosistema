#include"Herbivoro.h"

// Implementaci�n de Herb�voro
Herbivoro::Herbivoro(int x, int y, int energiaInicial, Ecosistema* e, char cl)
    : Criatura(x, y, energiaInicial, e, cl) {
    tipo = "Herbivoro";
}

Herbivoro::~Herbivoro() {
}

void Herbivoro::Operacion() {
    buscarPlantas();
    pastar(); 
    consumirEnergia(3); // Los herb�voros consumen menos energ�a
}

void Herbivoro::Update() {
    incrementarEdad();
    consumirEnergia(2); // Metabolismo base
    if (getClima() == 'D') {
        // Durante el d�a pueden alimentarse mejor
        alimentarse(5);
    }
    else if (getClima() == 'N') {
        // Durante la noche consumen m�s energ�a por estar alerta
        consumirEnergia(3);
    }
}

Criatura* Herbivoro::reproducirse() {
    if (puedeReproducirse()) {
        consumirEnergia(50);
        return new Herbivoro(posX, posY, 100, eco, clima);
    }
    return nullptr;
}

void Herbivoro::buscarPlantas() {
    // L�gica para buscar plantas cercanas
    cout << "Herbivoro buscando plantas..." << endl;
}

void Herbivoro::pastar()
{
    cout << "Herbivoro pastando..." << endl;
    alimentarse(15); // Obtiene energ�a de las plantas
}
