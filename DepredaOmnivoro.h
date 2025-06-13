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
#ifndef DEPREDA_OMNIVORO_H
#define  DEPREDA_OMNIVORO_H

#include"Alimentacion.h"

class Herbivoro;
class Omnivoro;

class DepredaOmnivoro : public Alimentacion {
private:
    int fuerzaAtaque;
public:
    DepredaOmnivoro();
    DepredaOmnivoro(int fuerza);
    ~DepredaOmnivoro();
    bool ejecutar(Criatura* criatura, Criatura* om);
    string getTipo() const override;
private:
    bool atacarOmnivoro(Criatura* carnivoro, Omnivoro* omnivoro);
};


#endif // DEPREDA_OMNIVORO_H