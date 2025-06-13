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
#ifndef REPRODUCCION_H
#define  REPRODUCCION_H
#include <iostream>
#include <string>
using namespace std;

class Criatura;
// Estrategia de reproducci�n
class Reproduccion {
private:
    int energiaMinima;
    int edadMinima;

public:
    Reproduccion(int energiaMin, int edadMin);
    virtual ~Reproduccion();
    bool ejecutar(Criatura* c1, Criatura* c2);
    string getTipo() const;
};

#endif // REPRODUCCION_H