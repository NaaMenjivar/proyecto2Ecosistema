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

void Matriz::mostrar() const
{
    cout << "\nEstado de la matriz (" << filas << "x" << columnas << "):\n   ";
    for (int x = 0; x < filas; ++x) cout << x << ' ';
    cout << "\n";
    for (int y = 0; y < columnas; ++y) {
        cout << y << " |";
        for (int x = 0; x < filas; ++x) {
            if (matriz[x][y] == nullptr) cout << ". ";
            else cout << matriz[x][y]->getSimbolo() << ' ';
        }
        cout << "\n";
    }
}

bool Matriz::dentroLimites(int x, int y) const
{
    return x >= 0 && x < filas && y >= 0 && y < columnas; 
}

bool Matriz::moverSeguro(int xActual, int yActual, int nuevoX, int nuevoY)
{
    if (!dentroLimites(xActual, yActual) || !dentroLimites(nuevoX, nuevoY)) {
        return false;
    }
    Observer* obs = matriz[xActual][yActual];
    if (obs == nullptr) {
        return false;
    }
    // Limpia destino sin delete
    matriz[nuevoX][nuevoY] = nullptr;
    matriz[nuevoX][nuevoY] = obs;
    matriz[xActual][yActual] = nullptr;
    return true;
}

bool Matriz::eliminarSeguro(int x, int y)
{
    if (!dentroLimites(x, y)) {
        return false;
    }
    if (matriz[x][y] == nullptr) return false;
    matriz[x][y] = nullptr;
    return true;
}

Observer* Matriz::obtener(int x, int y) const
{
    if (!dentroLimites(x, y))
        return nullptr;
    return matriz[x][y];
}


Observer* Matriz::verEntorno(int X, int Y)  {
    for (int x = -1; x <= 1; ++x) //Recorro las filas, anterior, actual y posterior
    {
        for (int y = -1; y <= 1; ++y) //Recorro las columnas, anterior, actual y posterior
        {
            if (x == 0 && y == 0) continue; 
            int nx = X + x; //Este es mi control de filas
            int ny = Y + y; //Este es mi control de columnas
            //Vamos a validar si debemos contar o no debemos contar las minas cercanas (vecinas)
            if (dentroLimites(nx,ny) == true && !(nx==X && ny ==Y)){
                if (matriz[nx][ny] != nullptr) {
                    return matriz[nx][ny];
                }
            }
        }
    }
    return nullptr;
}

void Matriz::simulacion(){
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] != nullptr) {
                matriz[i][j]->Operacion(this);
            }
        }
    }
}

void Matriz::notifyTodos()
{
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            if (matriz[i][j] != nullptr)
                matriz[i][j]->Update();
}




