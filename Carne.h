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
#ifndef CARNE_H
#define CARNE_H
#include"Recurso.h"

// Clase Carne
class Carne : public Recurso {
public:
    Carne(int x = 0, int y = 0, int valor = 50, Ecosistema* e = NULL, char cli = 'i');
    virtual ~Carne();

    virtual void Operacion(Matriz* mat) override;
    virtual void Update() override;
    virtual char getSimbolo() const;

    virtual void Guardar(ofstream& arch)override;
    static Recurso* Lectura(ifstream& arch, Ecosistema* eco);

    void setTiempoDescomposicion(int t) { tiempoDescomposicion = t; }

private:
    int tiempoDescomposicion;
    void descomponer();
};

#endif // CARNE_H