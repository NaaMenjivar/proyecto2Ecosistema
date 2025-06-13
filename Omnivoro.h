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
#ifndef OMNIVORO_H
#define OMNIVORO_H
#include"Criatura.h"

// Clase Omnívoro
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