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
#ifndef COME_PLANTA_H
#define  COME_PLANTA_H
#include"Alimentacion.h"

// declarations
class Herbivoro;
class Omnivoro;

// Estrategia para comer plantas
class ComePlanta : public Alimentacion {
public:
    ComePlanta();
    virtual ~ComePlanta();

    bool ejecutar(Criatura* criatura);
    virtual string getTipo() const override { return "ComePlanta"; }
    virtual bool esRecursoCompatible(Recurso* recurso) override;
};

#endif // COME_PLANTA_H