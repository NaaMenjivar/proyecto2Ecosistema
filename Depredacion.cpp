#include"Depredacion.h"
#include"Criatura.h"

// ============================================================================
// IMPLEMENTACIÓN DE DEPREDACION
// ============================================================================

//Depredacion::Depredacion(int distancia, int rango)
//    : Movimiento(distancia), rangoDeteccion(rango) {
//}
//
//Depredacion::~Depredacion() {
//}
//
//bool Depredacion::ejecutar(Criatura* criatura) {
//    if (criatura == nullptr || criatura->getTipo() != "Carnivoro") {
//        return false;
//    }
//
//    Criatura* presa = buscarPresa(criatura);
//    if (presa != nullptr) {
//        return moverHaciaPresa(criatura, presa);
//    }
//
//    return false;
//}
//
//Criatura* Depredacion::buscarPresa(Criatura* depredador) {
//    // en implementación real buscaría presas en el ecosistema
//    return nullptr;
//}
//
//bool Depredacion::moverHaciaPresa(Criatura* depredador, Criatura* presa) {
//    if (depredador == nullptr || presa == nullptr) {
//        return false;
//    }
//
//    int dx = presa->getPosX() - depredador->getPosX();
//    int dy = presa->getPosY() - depredador->getPosY();
//
//    // Normalizar movimiento a distancia máxima
//    int nuevaX = depredador->getPosX();
//    int nuevaY = depredador->getPosY();
//
//    if (dx > 0) nuevaX += (dx > distanciaMaxima ? distanciaMaxima : dx);
//    else if (dx < 0) nuevaX -= ((-dx) > distanciaMaxima ? distanciaMaxima : (-dx));
//
//    if (dy > 0) nuevaY += (dy > distanciaMaxima ? distanciaMaxima : dy);
//    else if (dy < 0) nuevaY -= ((-dy) > distanciaMaxima ? distanciaMaxima : (-dy));
//
//    return moverA(depredador, nuevaX, nuevaY);
//}
