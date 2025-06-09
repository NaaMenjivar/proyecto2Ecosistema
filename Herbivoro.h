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
#ifndef HERBIVORO_H
#define HERBIVORO_H
#include"Criatura.h"

// Clase Herb�voro
class Herbivoro : public Criatura {
public:
    Herbivoro(int x, int y, int energiaInicial, Ecosistema* e = nullptr, char cl = 'D');
    virtual ~Herbivoro();

    void Operacion() override;
    void Update() override;
    Criatura* reproducirse() override;

    void Guardar(ofstream& arch)override;
    static Criatura* Lectura(ifstream& arch, Ecosistema* eco);

private:
    void buscarPlantas();
    void pastar();
};

#endif // HERBIVORO_H