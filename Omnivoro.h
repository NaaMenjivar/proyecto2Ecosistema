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
#ifndef OMNIVORO_H
#define OMNIVORO_H
#include"Criatura.h"

// Clase Omn�voro
class Omnivoro : public Criatura {
public:
    Omnivoro(int x, int y, int energiaInicial, Ecosistema* e = nullptr, char cl = 'D');
    virtual ~Omnivoro();

    void Operacion(Matriz* mat) override;
    void Update() override;
    Criatura* reproducirse() override;
    virtual char getSimbolo() const; 

    void Guardar(ofstream& arch)override;
    static Criatura* Lectura(ifstream& arch, Ecosistema* eco);

private:
    void buscarAlimento();
    void cazarOPastar();
};

#endif // OMNIVORO_H