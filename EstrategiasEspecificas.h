#ifndef ESTRATEGIAS_ESPECIFICAS_H
#define ESTRATEGIAS_ESPECIFICAS_H

#include "Movimiento.h"
#include "Alimentacion.h"

// declarations
class Herbivoro;
class Omnivoro;

// ============================================================================
// ESTRATEGIAS DE ALIMENTACIÓN ESPECÍFICAS
// ============================================================================

// Estrategia para que carnívoros depreden herbívoros
class DepredaHerbivoro : public Alimentacion {
private:
    int fuerzaAtaque;

public:
    DepredaHerbivoro(int rango = 1, int fuerza = 50);
    virtual ~DepredaHerbivoro();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "DepredaHerbivoro"; }

    bool atacarHerbivoro(Criatura* carnivoro, Herbivoro* herbivoro);
    Herbivoro* buscarHerbivoro(Criatura* carnivoro);

    int getFuerzaAtaque() const { return fuerzaAtaque; }
    void setFuerzaAtaque(int fuerza) { fuerzaAtaque = fuerza; }
};

// Estrategia para que carnívoros depreden omnívoros
class DepredaOmnivoro : public Alimentacion {
private:
    int fuerzaAtaque;

public:
    DepredaOmnivoro(int rango = 1, int fuerza = 40);
    virtual ~DepredaOmnivoro();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "DepredaOmnivoro"; }

    bool atacarOmnivoro(Criatura* carnivoro, Omnivoro* omnivoro);
    Omnivoro* buscarOmnivoro(Criatura* carnivoro);

    int getFuerzaAtaque() const { return fuerzaAtaque; }
    void setFuerzaAtaque(int fuerza) { fuerzaAtaque = fuerza; }
};

// Estrategia para comer plantas
class ComePlanta : public Alimentacion {
public:
    ComePlanta(int rango = 2);
    virtual ~ComePlanta();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "ComePlanta"; }
    virtual bool esRecursoCompatible(Recurso* recurso) override;
};

// Estrategia para tomar agua
class TomaAgua : public Alimentacion {
public:
    TomaAgua(int rango = 3);
    virtual ~TomaAgua();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "TomaAgua"; }
    virtual bool esRecursoCompatible(Recurso* recurso) override;
};

// ============================================================================
// ESTRATEGIAS DE MOVIMIENTO ESPECÍFICAS
// ============================================================================

// Estrategia de huida para herbívoros y omnívoros
class Huida : public Movimiento {
private:
    int rangoPeligro;

public:
    Huida(int distancia = 2, int rango = 3);
    virtual ~Huida();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "Huida"; }

    bool hayPeligroCerca(Criatura* criatura);
    void huirDePeligro(Criatura* criatura);

    int generarDireccionAleatoria();

    int getRangoPeligro() const { return rangoPeligro; }
    void setRangoPeligro(int rango) { rangoPeligro = rango; }
};

// Estrategia de depredación (movimiento hacia presas)
class Depredacion : public Movimiento {
private:
    int rangoDeteccion;

public:
    Depredacion(int distancia = 2, int rango = 4);
    virtual ~Depredacion();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "Depredacion"; }

    Criatura* buscarPresa(Criatura* depredador);
    bool moverHaciaPresa(Criatura* depredador, Criatura* presa);

    int getRangoDeteccion() const { return rangoDeteccion; }
    void setRangoDeteccion(int rango) { rangoDeteccion = rango; }
};

// Estrategia de cambio de dirección aleatorio
class CambiaDireccion : public Movimiento {
public:
    CambiaDireccion(int distancia = 1);
    virtual ~CambiaDireccion();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "CambiaDireccion"; }

private:
    void moverAleatoriamente(Criatura* criatura);
    int generarDireccionAleatoria();
};

// ============================================================================
// ESTRATEGIA DE REPRODUCCIÓN
// ============================================================================

// Estrategia de reproducción
class Reproduccion : public Estrategia {
private:
    int energiaMinima;
    int edadMinima;
    int rangoPareja;

public:
    Reproduccion(int energiaMin = 150, int edadMin = 10, int rango = 2);
    virtual ~Reproduccion();

    virtual bool ejecutar(Criatura* criatura) override;
    virtual string getTipo() const override { return "Reproduccion"; }

    bool puedeReproducirse(Criatura* criatura);
    Criatura* buscarPareja(Criatura* criatura);
    bool intentarReproduccion(Criatura* criatura, Criatura* pareja);

    // Getters y setters
    int getEnergiaMinima() const { return energiaMinima; }
    int getEdadMinima() const { return edadMinima; }
    int getRangoPareja() const { return rangoPareja; }
    void setEnergiaMinima(int energia) { energiaMinima = energia; }
    void setEdadMinima(int edad) { edadMinima = edad; }
    void setRangoPareja(int rango) { rangoPareja = rango; }

private:
    bool sonCompatibles(Criatura* criatura1, Criatura* criatura2);
    int calcularDistancia(int x1, int y1, int x2, int y2);
};

#endif // ESTRATEGIAS_ESPECIFICAS_H
