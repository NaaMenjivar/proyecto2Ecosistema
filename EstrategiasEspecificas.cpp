#include "EstrategiasEspecificas.h"
#include "Criatura.h"
#include "Recurso.h"

// ============================================================================
// IMPLEMENTACI�N DE DEPREDAHERBIVORO
// ============================================================================

DepredaHerbivoro::DepredaHerbivoro(int rango, int fuerza)
    : Alimentacion(rango, "Herbivoro"), fuerzaAtaque(fuerza) {
}

DepredaHerbivoro::~DepredaHerbivoro() {
}

bool DepredaHerbivoro::ejecutar(Criatura* criatura) {
    if (criatura == nullptr || criatura->getTipo() != "Carnivoro") {
        return false;
    }

    Herbivoro* herbivoro = buscarHerbivoro(criatura);
    if (herbivoro != nullptr) {
        return atacarHerbivoro(criatura, herbivoro);
    }

    return false;
}

bool DepredaHerbivoro::atacarHerbivoro(Criatura* carnivoro, Herbivoro* herbivoro) {
    if (carnivoro == nullptr || herbivoro == nullptr) {
        return false;
    }

    // Calcular distancia para verificar si est� en rango
    int distancia = calcularDistancia(carnivoro->getPosX(), carnivoro->getPosY(),
        herbivoro->getPosX(), herbivoro->getPosY());

    if (distancia > rangoDeteccion) {
        return false;
    }

    // Realizar ataque
    carnivoro->alimentarse(fuerzaAtaque);

    // El herb�voro pierde energ�a o muere
    herbivoro->consumirEnergia(fuerzaAtaque * 2);

    return true;
}

Herbivoro* DepredaHerbivoro::buscarHerbivoro(Criatura* carnivoro) {
    // en implementaci�n real buscar�a en el ecosistema
    return nullptr;
}

// ============================================================================
// IMPLEMENTACI�N DE DEPREDAOMNIVORO
// ============================================================================

DepredaOmnivoro::DepredaOmnivoro(int rango, int fuerza)
    : Alimentacion(rango, "Omnivoro"), fuerzaAtaque(fuerza) {
}

DepredaOmnivoro::~DepredaOmnivoro() {
}

bool DepredaOmnivoro::ejecutar(Criatura* criatura) {
    if (criatura == nullptr || criatura->getTipo() != "Carnivoro") {
        return false;
    }

    Omnivoro* omnivoro = buscarOmnivoro(criatura);
    if (omnivoro != nullptr) {
        return atacarOmnivoro(criatura, omnivoro);
    }

    return false;
}

bool DepredaOmnivoro::atacarOmnivoro(Criatura* carnivoro, Omnivoro* omnivoro) {
    if (carnivoro == nullptr || omnivoro == nullptr) {
        return false;
    }

    // Calcular distancia para verificar si est� en rango
    int distancia = calcularDistancia(carnivoro->getPosX(), carnivoro->getPosY(),
        omnivoro->getPosX(), omnivoro->getPosY());

    if (distancia > rangoDeteccion) {
        return false;
    }

    // Realizar ataque
    carnivoro->alimentarse(fuerzaAtaque);

    // El omn�voro pierde energ�a o muere
    omnivoro->consumirEnergia(fuerzaAtaque * 2);

    return true;
}

Omnivoro* DepredaOmnivoro::buscarOmnivoro(Criatura* carnivoro) {
    // en implementaci�n real buscar�a en el ecosistema
    return nullptr;
}

// ============================================================================
// IMPLEMENTACI�N DE COMEPLANTA
// ============================================================================

ComePlanta::ComePlanta(int rango) : Alimentacion(rango, "Planta") {
}

ComePlanta::~ComePlanta() {
}

bool ComePlanta::ejecutar(Criatura* criatura) {
    if (criatura == nullptr) {
        return false;
    }

    Recurso* planta = buscarRecurso(criatura);
    if (planta != nullptr) {
        return consumirRecurso(criatura, planta);
    }

    return false;
}

bool ComePlanta::esRecursoCompatible(Recurso* recurso) {
    return (recurso != nullptr && recurso->getTipo() == "Planta");
}

// ============================================================================
// IMPLEMENTACI�N DE TOMAAGUA
// ============================================================================

TomaAgua::TomaAgua(int rango) : Alimentacion(rango, "Agua") {
}

TomaAgua::~TomaAgua() {
}

bool TomaAgua::ejecutar(Criatura* criatura) {
    if (criatura == nullptr) {
        return false;
    }

    Recurso* agua = buscarRecurso(criatura);
    if (agua != nullptr) {
        return consumirRecurso(criatura, agua);
    }

    return false;
}

bool TomaAgua::esRecursoCompatible(Recurso* recurso) {
    return (recurso != nullptr && recurso->getTipo() == "Agua");
}

// ============================================================================
// IMPLEMENTACI�N DE HUIDA
// ============================================================================

Huida::Huida(int distancia, int rango)
    : Movimiento(distancia), rangoPeligro(rango) {
}

Huida::~Huida() {
}

bool Huida::ejecutar(Criatura* criatura) {
    if (criatura == nullptr) {
        return false;
    }

    if (hayPeligroCerca(criatura)) {
        huirDePeligro(criatura);
        return true;
    }

    return false;
}

bool Huida::hayPeligroCerca(Criatura* criatura) {
    // en implementaci�n real verificar�a carn�voros cercanos
    // Por ahora asumimos que no hay peligro
    return false;
}

void Huida::huirDePeligro(Criatura* criatura) {
    if (criatura == nullptr) {
        return;
    }

    // Generar una direcci�n aleatoria para huir
    int direccion = generarDireccionAleatoria();
    int nuevaX = criatura->getPosX();
    int nuevaY = criatura->getPosY();

    // Calcular nueva posici�n basada en la direcci�n
    switch (direccion) {
    case 0: nuevaY -= distanciaMaxima; break; // Norte
    case 1: nuevaX += distanciaMaxima; break; // Este
    case 2: nuevaY += distanciaMaxima; break; // Sur
    case 3: nuevaX -= distanciaMaxima; break; // Oeste
    }

    moverA(criatura, nuevaX, nuevaY);
}

int Huida::generarDireccionAleatoria() {
    // Implementaci�n simple sin usar rand()
    static int contador = 0;
    contador = (contador + 1) % 4;
    return contador;
}

// ============================================================================
// IMPLEMENTACI�N DE DEPREDACION
// ============================================================================

Depredacion::Depredacion(int distancia, int rango)
    : Movimiento(distancia), rangoDeteccion(rango) {
}

Depredacion::~Depredacion() {
}

bool Depredacion::ejecutar(Criatura* criatura) {
    if (criatura == nullptr || criatura->getTipo() != "Carnivoro") {
        return false;
    }

    Criatura* presa = buscarPresa(criatura);
    if (presa != nullptr) {
        return moverHaciaPresa(criatura, presa);
    }

    return false;
}

Criatura* Depredacion::buscarPresa(Criatura* depredador) {
    // en implementaci�n real buscar�a presas en el ecosistema
    return nullptr;
}

bool Depredacion::moverHaciaPresa(Criatura* depredador, Criatura* presa) {
    if (depredador == nullptr || presa == nullptr) {
        return false;
    }

    int dx = presa->getPosX() - depredador->getPosX();
    int dy = presa->getPosY() - depredador->getPosY();

    // Normalizar movimiento a distancia m�xima
    int nuevaX = depredador->getPosX();
    int nuevaY = depredador->getPosY();

    if (dx > 0) nuevaX += (dx > distanciaMaxima ? distanciaMaxima : dx);
    else if (dx < 0) nuevaX -= ((-dx) > distanciaMaxima ? distanciaMaxima : (-dx));

    if (dy > 0) nuevaY += (dy > distanciaMaxima ? distanciaMaxima : dy);
    else if (dy < 0) nuevaY -= ((-dy) > distanciaMaxima ? distanciaMaxima : (-dy));

    return moverA(depredador, nuevaX, nuevaY);
}

// ============================================================================
// IMPLEMENTACI�N DE CAMBIADIRECCION
// ============================================================================

CambiaDireccion::CambiaDireccion(int distancia) : Movimiento(distancia) {
}

CambiaDireccion::~CambiaDireccion() {
}

bool CambiaDireccion::ejecutar(Criatura* criatura) {
    if (criatura == nullptr) {
        return false;
    }

    moverAleatoriamente(criatura);
    return true;
}

void CambiaDireccion::moverAleatoriamente(Criatura* criatura) {
    if (criatura == nullptr) {
        return;
    }

    int direccion = generarDireccionAleatoria();
    int nuevaX = criatura->getPosX();
    int nuevaY = criatura->getPosY();

    // Calcular nueva posici�n basada en la direcci�n
    switch (direccion) {
    case 0: nuevaY -= distanciaMaxima; break; // Norte
    case 1: nuevaX += distanciaMaxima; break; // Este
    case 2: nuevaY += distanciaMaxima; break; // Sur
    case 3: nuevaX -= distanciaMaxima; break; // Oeste
    }

    moverA(criatura, nuevaX, nuevaY);
}

int CambiaDireccion::generarDireccionAleatoria() {
    // Implementaci�n simple sin usar rand()
    static int contador = 0;
    contador = (contador + 7) % 4; // Usar 7 para que var�e m�s
    return contador;
}

// ============================================================================
// IMPLEMENTACI�N DE REPRODUCCION
// ============================================================================

Reproduccion::Reproduccion(int energiaMin, int edadMin, int rango)
    : energiaMinima(energiaMin), edadMinima(edadMin), rangoPareja(rango) {
}

Reproduccion::~Reproduccion() {
}

bool Reproduccion::ejecutar(Criatura* criatura) {
    if (criatura == nullptr) {
        return false;
    }

    if (!puedeReproducirse(criatura)) {
        return false;
    }

    Criatura* pareja = buscarPareja(criatura);
    if (pareja != nullptr) {
        return intentarReproduccion(criatura, pareja);
    }

    return false;
}

bool Reproduccion::puedeReproducirse(Criatura* criatura) {
    if (criatura == nullptr) {
        return false;
    }

    return (criatura->getEnergia() >= energiaMinima &&
        criatura->getEdad() >= edadMinima);
}

Criatura* Reproduccion::buscarPareja(Criatura* criatura) {
    // en implementaci�n real buscar�a parejas compatibles
    return nullptr;
}

bool Reproduccion::intentarReproduccion(Criatura* criatura, Criatura* pareja) {
    if (criatura == nullptr || pareja == nullptr) {
        return false;
    }

    if (!sonCompatibles(criatura, pareja)) {
        return false;
    }

    // Verificar distancia
    int distancia = calcularDistancia(criatura->getPosX(), criatura->getPosY(),
        pareja->getPosX(), pareja->getPosY());

    if (distancia > rangoPareja) {
        return false;
    }

    // Realizar reproducci�n
    Criatura* cria = criatura->reproducirse();
    if (cria != nullptr) {
        // Consumir energ�a de ambos padres
        criatura->consumirEnergia(energiaMinima / 2);
        pareja->consumirEnergia(energiaMinima / 2);
        return true;
    }

    return false;
}

bool Reproduccion::sonCompatibles(Criatura* criatura1, Criatura* criatura2) {
    if (criatura1 == nullptr || criatura2 == nullptr) {
        return false;
    }

    // Deben ser del mismo tipo y ambos poder reproducirse
    return (criatura1->getTipo() == criatura2->getTipo() &&
        puedeReproducirse(criatura1) &&
        puedeReproducirse(criatura2));
}

int Reproduccion::calcularDistancia(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    return dx + dy;
}