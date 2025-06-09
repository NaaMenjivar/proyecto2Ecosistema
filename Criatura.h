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

#ifndef CRIATURA_H
#define CRIATURA_H

#include"Observer.h"

// Clase base abstracta para todas las criaturas
class Criatura : public Observer {
protected:
    int posX, posY;
    int energia;
    int edad;
    string tipo;

public:
    // Constructor
    Criatura(int x = 0, int y = 0, int energiaInicial = 100, Ecosistema* e = NULL, char cl = 'i');

    // Destructor virtual
    virtual ~Criatura();

    // Métodos virtuales puros
    virtual void Operacion() = 0;
    virtual void Update() = 0;

    // Métodos virtuales
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
    char getSimbolo()const {
        string tipo = getTipo();
        if (tipo == "Carnivoro") return 'C';
        if (tipo == "Herbivoro") return 'H';
        if (tipo == "Omnivoro") return 'O';
        return '?';
    };

    void setPosicion(int x, int y);
    void consumirEnergia(int cantidad);
    void incrementarEdad();

    // Método para verificar si la criatura está viva
    bool estaViva() const;
};

#endif // CRIATURA_H
