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

#ifndef RECURSO_H
#define RECURSO_H

#include <iostream>
#include <string>
using namespace std;

// Clase base abstracta para todos los recursos
class Recurso {
protected:
    int posX, posY;
    int valorNutricional;
    string tipo;
    bool disponible;
    int tiempoRegeneracion;

public:
    // Constructor
    Recurso(int x = 0, int y = 0, int valor = 50);

    // Destructor virtual
    virtual ~Recurso();

    // Métodos virtuales puros
    virtual void Operacion() = 0;
    virtual void Update() = 0;

    // Métodos virtuales
    virtual void regenerar();
    virtual int serConsumido();

    // Getters y setters
    int getPosX() const { return posX; }
    int getPosY() const { return posY; }
    int getValorNutricional() const { return valorNutricional; }
    string getTipo() const { return tipo; }
    bool estaDisponible() const { return disponible; }

    void setPosicion(int x, int y);
    void setDisponible(bool estado);
};

// Clase Agua
class Agua : public Recurso {
public:
    Agua(int x = 0, int y = 0, int valor = 30);
    virtual ~Agua();

    virtual void Operacion() override;
    virtual void Update() override;
    virtual void regenerar() override;

private:
    int pureza;
};

// Clase Carne
class Carne : public Recurso {
public:
    Carne(int x = 0, int y = 0, int valor = 80);
    virtual ~Carne();

    virtual void Operacion() override;
    virtual void Update() override;

private:
    int tiempoDescomposicion;
    void descomponer();
};

// Clase Planta
class Planta : public Recurso {
public:
    Planta(int x = 0, int y = 0, int valor = 60);
    virtual ~Planta();

    virtual void Operacion() override;
    virtual void Update() override;
    virtual void regenerar() override;

private:
    int nivelCrecimiento;
    void crecer();
};

#endif // RECURSO_H