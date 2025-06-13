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
#ifndef COLECCION_H
#define COLECCION_H

#include <iostream>
using namespace std;

// Template de Colección que simula un vector
template <class T>
class ColeccionT {
private:
    T** elementos;
    int capacidad;
    int tamanio;

    void redimensionar();

public:
    // Constructor
    ColeccionT(int capacidadInicial = 10);

    // Destructor
    ~ColeccionT();

    // Constructor de copia
    ColeccionT(const ColeccionT<T>& otra);

    // Operador de asignación
    ColeccionT<T>& operator=(const ColeccionT<T>& otra);

    // Métodos principales
    void agregar(T* elemento);
    bool eliminar(int indice);
    bool eliminar(T* elemento);
    T* obtener(int indice) const;
    int buscar(T* elemento) const;

    // Getters
    int getTamanio() const { return tamanio; }
    int getCapacidad() const { return capacidad; }
    T** getVec()const { return elementos; }
    bool estaVacia() const { return tamanio == 0; }

    // Operador de acceso por índice
    T* operator[](int indice) const;

    // Método para limpiar la colección
    void limpiar();

    // Iterador interno simple
    void paraEach(void (*funcion)(T*));

    // Clase Iterador anidada
    class Iterador {
    private:
        T** coleccion;
        int can;
        int tam;


    public:
        Iterador(T** col, int t);
        bool tieneSiguiente() const;
        void siguiente();
        void reiniciar();
        T* actual() const;
    };

    // Método para obtener un iterador
    Iterador* obtenerIterador();
};

// Implementación del template (debe estar en el .h)

template <class T>
ColeccionT<T>::ColeccionT(int capacidadInicial)
    : capacidad(capacidadInicial), tamanio(0) {
    elementos = new T * [capacidad];
    for (int i = 0; i < capacidad; i++) {
        elementos[i] = nullptr;
    }
}

template <class T>
ColeccionT<T>::~ColeccionT() {
    limpiar();
    delete[] elementos;
}

template <class T>
ColeccionT<T>::ColeccionT(const ColeccionT<T>& otra)
    : capacidad(otra.capacidad), tamanio(otra.tamanio) {
    elementos = new T * [capacidad];
    for (int i = 0; i < tamanio; i++) {
        elementos[i] = otra.elementos[i];
    }
    for (int i = tamanio; i < capacidad; i++) {
        elementos[i] = nullptr;
    }
}

template <class T>
ColeccionT<T>& ColeccionT<T>::operator=(const ColeccionT<T>& otra) {
    if (this != &otra) {
        delete[] elementos;
        capacidad = otra.capacidad;
        tamanio = otra.tamanio;
        elementos = new T * [capacidad];
        for (int i = 0; i < tamanio; i++) {
            elementos[i] = otra.elementos[i];
        }
        for (int i = tamanio; i < capacidad; i++) {
            elementos[i] = nullptr;
        }
    }
    return *this;
}

template <class T>
void ColeccionT<T>::redimensionar() {
    int nuevaCapacidad = capacidad * 2;
    T** nuevosElementos = new T * [nuevaCapacidad];

    for (int i = 0; i < tamanio; i++) {
        nuevosElementos[i] = elementos[i];
    }
    for (int i = tamanio; i < nuevaCapacidad; i++) {
        nuevosElementos[i] = nullptr;
    }

    delete[] elementos;
    elementos = nuevosElementos;
    capacidad = nuevaCapacidad;
}

template <class T>
void ColeccionT<T>::agregar(T* elemento) {
    if (tamanio >= capacidad) {
        redimensionar();
    }
    elementos[tamanio] = elemento;
    tamanio++;
}

template <class T>
bool ColeccionT<T>::eliminar(int indice) {
    if (indice < 0 || indice >= tamanio) {
        return false;
    }

    for (int i = indice; i < tamanio - 1; i++) {
        elementos[i] = elementos[i + 1];
    }
    elementos[tamanio - 1] = nullptr;
    tamanio--;
    return true;
}

template <class T>
bool ColeccionT<T>::eliminar(T* elemento) {
    int indice = buscar(elemento);
    if (indice != -1) {
        return eliminar(indice); 
    }
    return false;
}

template <class T>
T* ColeccionT<T>::obtener(int indice) const {
    if (indice < 0 || indice >= tamanio) {
        return nullptr;
    }
    return elementos[indice];
}

template <class T>
int ColeccionT<T>::buscar(T* elemento) const {
    for (int i = 0; i < tamanio; i++) {
        if (elementos[i] == elemento) {
            return i;
        }
    }
    return -1;
}

template <class T>
T* ColeccionT<T>::operator[](int indice) const {
    return obtener(indice);
}

template <class T>
void ColeccionT<T>::limpiar() {
    for (int i = 0; i < tamanio; i++) {
        elementos[i] = nullptr;
    }
    tamanio = 0;
}

template <class T>
void ColeccionT<T>::paraEach(void (*funcion)(T*)) {
    for (int i = 0; i < tamanio; i++) {
        if (elementos[i] != nullptr) {
            funcion(elementos[i]);
        }
    }
}

// --------------------------------Implementación del Iterador------------------------------------
template <class T>
ColeccionT<T>::Iterador::Iterador(T** col, int t)
    : coleccion(col), can(0),tam(t) {
}

template <class T>
bool ColeccionT<T>::Iterador::tieneSiguiente() const {
    return can < tam;
}

template <class T>
void ColeccionT<T>::Iterador::siguiente() {
    can++;
}

template <class T>
void ColeccionT<T>::Iterador::reiniciar() {
    can = 0;
}

template <class T>
T* ColeccionT<T>::Iterador::actual() const {
    return coleccion[can];
}

template <class T>
typename ColeccionT<T>::Iterador* ColeccionT<T>::obtenerIterador() {
    return new Iterador(this, tamanio);
}

#endif // COLECCION_H