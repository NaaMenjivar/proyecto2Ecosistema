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

#ifndef OBSERVER_H
#define OBSERVER_H

#include "ColeccionT.h"

// Forward declaration
class Ecosistema;

// Clase Observer (Observer Pattern)
class Observer {
protected:
    Ecosistema* ecosistema;

public:
    Observer(Ecosistema* eco = nullptr);
    virtual ~Observer();

    // Método que será llamado cuando el ecosistema notifique cambios
    virtual void Update() = 0;

    // Setter para el ecosistema
    void setEcosistema(Ecosistema* eco);
    Ecosistema* getEcosistema() const;
};

// Clase Subject/Observable (parte del Observer Pattern)
class Observable {
private:
    ColeccionT<Observer> observadores;

public:
    Observable();
    virtual ~Observable();

    // Métodos para manejar observadores
    void AddObserver(Observer* observer);
    void RemObserver(Observer* observer);
    void NotifyAll();
};

#endif // OBSERVER_H