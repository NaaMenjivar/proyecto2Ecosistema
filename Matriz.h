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
    bool mover(int xActual, int yActual, int nuevoX, int nuevoY);
    bool eliminar(int x, int y);
    Observer* obtener(int x, int y);
    void notifyTodos();
    void mostrar()const;
private:
    bool dentroLimites(int x, int y);
};

