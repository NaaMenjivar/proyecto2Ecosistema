#pragma once
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
    void mover(int xActual, int yActual, int nuevoX, int nuevoY);
    bool eliminar(int x, int y);
    Observer* obtener(int x, int y);
    void notifyTodos();
    void mostrar()const;
    bool intercambiar(int x1, int y1, int x2, int y2);
    Observer* verEntorno(int x, int y);
    void simulacion();

private:
    bool dentroLimites(int x, int y);
};

