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

