#include "Alimentacion.h"
#include "Criatura.h"
#include "Recurso.h"

// Constructor
Alimentacion::Alimentacion(string tipoRecurso)
    : tipoRecursoObjetivo(tipoRecurso) {
    // Inicialización de la estrategia de alimentación
}

// Destructor
Alimentacion::~Alimentacion() {
    // Limpieza si es necesario
}

// Buscar recurso compatible cerca de la criatura
Recurso* Alimentacion::buscarRecurso(Criatura* criatura) {
    if (criatura == nullptr) {
        return nullptr;
    }

    // Aquí se implementaría la búsqueda en el ecosistema
    // Por ahora retornamos nullptr 
    // En la implementación real, se accede al ecosistema global
    // para buscar recursos en el rango especificado

    return nullptr;
}

// Consumir un recurso
bool Alimentacion::consumirRecurso(Criatura* criatura, Recurso* recurso) {
    if (criatura == nullptr || recurso == nullptr) {
        return false;
    }

    // Verificar si el recurso está disponible
    if (!recurso->estaDisponible()) {
        return false;
    }

    // Verificar si el recurso es compatible
    if (!esRecursoCompatible(recurso)) {
        return false;
    }

    // Consumir el recurso
    int valorNutricional = recurso->serConsumido();
    criatura->alimentarse(valorNutricional);

    return true;
}

// Verificar si un recurso es compatible con esta estrategia
bool Alimentacion::esRecursoCompatible(Recurso* recurso) {
    if (recurso == nullptr) {
        return false;
    }

    // Si no hay tipo específico, acepta cualquier recurso
    if (tipoRecursoObjetivo.empty()) {
        return true;
    }

    // Verificar si el tipo coincide
    return recurso->getTipo() == tipoRecursoObjetivo;
}

// Calcular distancia entre dos puntos
int Alimentacion::calcularDistancia(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    return dx + dy;
}
