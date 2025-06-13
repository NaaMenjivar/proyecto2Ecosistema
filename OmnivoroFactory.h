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
#ifndef OMNIVOROFACTORY_H
#define OMNIVOROFACTORY_H 
#include "CriaturaFactory.h"
#include "Omnivoro.h"

class OmnivoroFactory : public CriaturaFactory {
public:
    Criatura* crearCriatura(int x, int y, int energia, Ecosistema* eco, char clima) override;
    string getTipoFactory() const override;
};

#endif