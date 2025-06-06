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

#ifndef CRIATURA_H
#define CRIATURA_H

#include <iostream>
#include <string>
using namespace std;

// Clase base abstracta para todas las criaturas
class Criatura {
protected:
    int posX, posY;
    int energia;
    int edad;
    string tipo;

public:
    // Constructor
    Criatura(int x = 0, int y = 0, int energiaInicial = 100);

    // Destructor virtual
    virtual ~Criatura();

    // M�todos virtuales puros
    virtual void Operacion() = 0;
    virtual void Update() = 0;

    // M�todos virtuales
    virtual void mover(int nuevaX, int nuevaY);
    virtual void alimentarse(int energiaObtenida);
    virtual bool puedeReproducirse() const;
    virtual Criatura* reproducirse() = 0;

    // Getters y setters
    int getPosX() const { return posX; }
    int getPosY() const { return posY; }
    int getEnergia() const { return energia; }
    int getEdad() const { return edad; }
    string getTipo() const { return tipo; }

    void setPosicion(int x, int y);
    void consumirEnergia(int cantidad);
    void incrementarEdad();

    // M�todo para verificar si la criatura est� viva
    bool estaViva() const;
};

// Clase Herb�voro
class Herbivoro : public Criatura {
public:
    Herbivoro(int x = 0, int y = 0, int energiaInicial = 80);
    virtual ~Herbivoro();

    virtual void Operacion() override;
    virtual void Update() override;
    virtual Criatura* reproducirse() override;

private:
    void buscarPlantas();
};

// Clase Carn�voro
class Carnivoro : public Criatura {
public:
    Carnivoro(int x = 0, int y = 0, int energiaInicial = 120);
    virtual ~Carnivoro();

    virtual void Operacion() override;
    virtual void Update() override;
    virtual Criatura* reproducirse() override;

private:
    void cazarPresa();
};

// Clase Omn�voro
class Omnivoro : public Criatura {
public:
    Omnivoro(int x = 0, int y = 0, int energiaInicial = 100);
    virtual ~Omnivoro();

    virtual void Operacion() override;
    virtual void Update() override;
    virtual Criatura* reproducirse() override;

private:
    void buscarAlimento();
};

#endif // CRIATURA_H
