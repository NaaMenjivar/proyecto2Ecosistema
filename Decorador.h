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

#ifndef DECORADOR_H
#define DECORADOR_H

#include "Criatura.h"

// Clase base Decorador (Decorator Pattern)
class Decorador : public Criatura {
protected:
    Criatura* criaturaDecorada;

public:
    Decorador(Criatura* criatura);
    virtual ~Decorador();

    // M�todos heredados de Criatura que delegan a la criatura decorada
    virtual void Operacion() override;
    virtual void Update() override;
    virtual void mover(int nuevaX, int nuevaY) override;
    virtual void alimentarse(int energiaObtenida) override;
    virtual bool puedeReproducirse() const override;
    virtual Criatura* reproducirse() override;

    // M�todo para obtener la criatura decorada
    Criatura* getCriaturaDecorada() const;
};

// Decorador espec�fico para velocidad
class DecoradorVelocidad : public Decorador {
private:
    int multiplicadorVelocidad;
    int movimientosExtraPorTick;

public:
    DecoradorVelocidad(Criatura* criatura, int multiplicador = 2);
    virtual ~DecoradorVelocidad();

    // Override de m�todos que se ven afectados por la velocidad
    virtual void Operacion() override;
    virtual void Update() override;
    virtual void mover(int nuevaX, int nuevaY) override;

    // M�todos espec�ficos del decorador de velocidad
    void setMultiplicadorVelocidad(int multiplicador);
    int getMultiplicadorVelocidad() const;
    void realizarMovimientosExtra();

    // Override del m�todo de reproducci�n para mantener la mejora
    virtual Criatura* reproducirse() override;
};

// Decorador espec�fico para resistencia (opcional)
class DecoradorResistencia : public Decorador {
private:
    int resistenciaExtra;
    int reduccionConsumoEnergia;

public:
    DecoradorResistencia(Criatura* criatura, int resistencia = 50);
    virtual ~DecoradorResistencia();

    // Override de m�todos afectados por la resistencia
    virtual void Update() override;
    virtual void alimentarse(int energiaObtenida) override;

    // M�todos espec�ficos del decorador de resistencia
    void setResistenciaExtra(int resistencia);
    int getResistenciaExtra() const;
    void aplicarResistencia();

    // Override del m�todo de reproducci�n para mantener la mejora
    virtual Criatura* reproducirse() override;
};

// Decorador espec�fico para longevidad (opcional)
class DecoradorLongevidad : public Decorador {
private:
    int factorLongevidad;
    int edadMaximaExtra;

public:
    DecoradorLongevidad(Criatura* criatura, int factor = 2);
    virtual ~DecoradorLongevidad();

    // Override de m�todos afectados por la longevidad
    virtual void Update() override;
    virtual bool puedeReproducirse() const override;

    // M�todos espec�ficos del decorador de longevidad
    void setFactorLongevidad(int factor);
    int getFactorLongevidad() const;
    bool deberiaEnvejecer() const;

    // Override del m�todo de reproducci�n para mantener la mejora
    virtual Criatura* reproducirse() override;
};

#endif // DECORADOR_H