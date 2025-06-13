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
#ifndef DEPREDA_HERBIVORO_H
#define  DEPREDA_HERBIVORO_H
#include"Alimentacion.h"

class Herbivoro;
class Omnivoro;

class DepredaHerbivoro : public Alimentacion {
private:
    int fuerzaAtaque;
public:
    DepredaHerbivoro();
    DepredaHerbivoro(int fuerza);
    ~DepredaHerbivoro();
    bool ejecutar(Criatura* criatura, Criatura* her);
    string getTipo() const override;
private:
    bool atacarHerbivoro(Criatura* carnivoro, Herbivoro* herbivoro);
};

#endif // DEPREDA_HERBIVORO_H