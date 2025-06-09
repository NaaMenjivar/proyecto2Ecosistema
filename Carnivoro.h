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
#ifndef CARNIVORO_H
#define CARNIVORO_H
#include"Criatura.h"

// Clase Carnívoro
class Carnivoro : public Criatura {
public:
    Carnivoro(int x, int y, int energiaInicial, Ecosistema* e = nullptr, char cl = 'D'); 
    virtual ~Carnivoro();

    void Operacion(Matriz* mat) override;
    void Update() override;
    Criatura* reproducirse() override;

    void Guardar(ofstream& arch)override;
    static Criatura* Lectura(ifstream& arch, Ecosistema* eco);

private:
    void cazarPresa();
};

#endif // CARNIVORO_H
