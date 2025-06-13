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
#ifndef MATRIZ_H
#define MATRIZ_H
#include "Observer.h"

class Matriz {
private:
    Observer*** matriz;
    int filas;
    int columnas;
public:
    Matriz();
    virtual ~Matriz();
    bool insertar(Observer* obs, int x, int y);
    bool dentroLimites(int x, int y) const;
    Observer* obtener(int x, int y)const;
    Observer* verEntorno(int X, int Y) ;
    bool moverSeguro(int xActual, int yActual, int nuevoX, int nuevoY);
    bool eliminarSeguro(int x, int y);
    void simulacion();
    void notifyTodos();
    void mostrar() const;
};
#endif // MATRIZ_H

