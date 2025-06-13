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
#ifndef REPRODUCCION_H
#define  REPRODUCCION_H
#include <iostream>
#include <string>
using namespace std;

class Criatura;
// Estrategia de reproducción
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