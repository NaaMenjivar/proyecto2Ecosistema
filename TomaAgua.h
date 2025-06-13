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
#ifndef TOMA_AGUA_H
#define  TOMA_AGUA_H
#include"Alimentacion.h"

// declarations
class Herbivoro;
class Omnivoro;
class Carnivoro;


// Estrategia para tomar agua
class TomaAgua : public Alimentacion {
public:
    TomaAgua();
    virtual ~TomaAgua();

    bool ejecutar(Criatura* criatura, Recurso* rec);
    virtual string getTipo() const override { return "TomaAgua"; }
    virtual bool esRecursoCompatible(Recurso* recurso) override;
};

#endif // TOMA_AGUA_H