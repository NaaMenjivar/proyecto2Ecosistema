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

#ifndef RECURSO_H
#define RECURSO_H

#include"Observer.h"
#include<fstream>
#include"Criatura.h"

class Matriz;

// Clase base abstracta para todos los recursos
class Recurso:public Observer {
protected:
    int posX, posY;
    int valorNutricional;
    string tipo;
    bool disponible;
    int tiempoRegeneracion;

public:
    // Constructor
    Recurso(int x = 0, int y = 0, int valor = 50, Ecosistema* e = NULL, char cli = 'i');

    // Destructor virtual
    virtual ~Recurso();

    // M�todos virtuales puros
    virtual void Operacion(Matriz* mat) = 0;
    virtual void Update() = 0;

    // M�todos virtuales
    virtual void regenerar();
    virtual int serConsumido();

    // Getters y setters
    int getPosX() const { return posX; }
    int getPosY() const { return posY; }
    int getValorNutricional() const { return valorNutricional; }
    string getTipo() const { return tipo; }
    bool estaDisponible() const { return disponible; }
    virtual char getSimbolo() const override = 0;
    void setPosicion(int x, int y);
    void setDisponible(bool estado);
    void setTiempoRegeneracion(int t) { tiempoRegeneracion = t; }

    virtual void Guardar(ofstream& arch) = 0;
};

#endif // RECURSO_H