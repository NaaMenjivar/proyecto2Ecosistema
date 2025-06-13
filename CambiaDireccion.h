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
#ifndef CAMBIA_DIRECCION_H
#define  CAMBIA_DIRECCION_H
#include"Movimiento.h"

// Estrategia de cambio de dirección aleatorio
class CambiaDireccion : public Movimiento {
public:
    CambiaDireccion(int distancia = 1);
    virtual ~CambiaDireccion();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "CambiaDireccion"; }

private:
    void moverAleatoriamente(Criatura* criatura);
    int generarDireccionAleatoria();
};

#endif // CAMBIA_DIRECCION_H