#include "Matriz.h"

Matriz::Matriz()
{
    this->filas = 10;
    this->columnas = 10;
    matriz = new Observer * *[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new Observer * [columnas];
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = nullptr; // Inicializar todas las posiciones como vacías
        }
    }
}

Matriz::~Matriz()
{
    if (matriz) { 
        for (int i = 0; i < filas; i++) { 
            if (matriz[i]) { 
                delete[] matriz[i]; 
            }
        }
        delete[] matriz; 
    }
}

bool Matriz::insertar(Observer* obs, int x, int y)
{
    if (!dentroLimites(x, y) || matriz[x][y] != nullptr)
        return false;
    matriz[x][y] = obs;
    return true;
}

bool Matriz::mover(int xActual, int yActual, int nuevoX, int nuevoY)
{
    if (!dentroLimites(nuevoX, nuevoY) || matriz[nuevoX][nuevoY] != nullptr)
        return false;

    matriz[nuevoX][nuevoY] = matriz[xActual][yActual];
    matriz[xActual][yActual] = nullptr;
    return true;
}

bool Matriz::eliminar(int x, int y)
{
    if (!dentroLimites(x, y) || matriz[x][y] == nullptr)
        return false;
    matriz[x][y] = nullptr;
    return true;
}

Observer* Matriz::obtener(int x, int y)
{
    if (!dentroLimites(x, y))
        return nullptr;
    return matriz[x][y];
}

void Matriz::notifyTodos()
{
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j) 
            if (matriz[i][j] != nullptr) 
                matriz[i][j]->Update();  
}

void Matriz::mostrar() const
{
    cout << "\nEstado de la matriz (10x10):\n";
    cout << "   ";
    for (int x = 0; x < filas; ++x)
        cout << x << " ";
    cout << endl;

    for (int y = 0; y < columnas; ++y) {
        cout << y << " |";
        for (int x = 0; x < filas; ++x) {
            Observer* obs = matriz[x][y];
            if (obs == nullptr) {
                cout << ". ";
            }
            else {
                cout << obs->getSimbolo() << " ";
            }
        }
        cout << endl;
    }
}

bool Matriz::dentroLimites(int x, int y)
{
    return x >= 0 && x < filas && y >= 0 && y < columnas; 
}
