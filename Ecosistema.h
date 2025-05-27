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

#ifndef ECOSISTEMA_H
#define ECOSISTEMA_H

#include "Observer.h"
#include "ColeccionT.h"
#include "Criatura.h"
#include "Recurso.h"
#include "FabricaElementos.h"
#include <string>

// Clase Ecosistema usando Singleton Pattern
class Ecosistema : public Observable {
private:
    static Ecosistema* instancia;

    // Dimensiones del ecosistema
    int ancho;
    int alto;

    // Colecciones de elementos
    ColeccionT<Criatura> criaturas;
    ColeccionT<Recurso> recursos;

    // Estado del ecosistema
    int tickActual;
    int ticksMaximos;
    int nivelEnergiaTotalSistema;
    bool simulacionActiva;

    // Matriz para representar el espacio (nullptr = vacío, puntero = ocupado)
    void*** espacioVirtual;

    // Fábricas
    FabricaCriaturas* fabricaCriaturas;
    FabricaRecursos* fabricaRecursos;

    // Constructor privado (Singleton)
    Ecosistema(int anchoInicial = 50, int altoInicial = 50);

    // Métodos privados de utilidad
    void inicializarEspacio();
    void limpiarEspacio();
    bool posicionValida(int x, int y) const;
    void eliminarCriaturasMaricuello();
    void regenerarRecursos();
    void procesarReproduccion();

public:
    // Destructor
    ~Ecosistema();

    // Método estático para obtener la instancia (Singleton)
    static Ecosistema* obtenerInstancia(int ancho = 50, int alto = 50);
    static void destruirInstancia();

    // Métodos principales de la simulación
    void iniciarSimulacion(int ticksMaximos = 1000);
    void detenerSimulacion();
    void ejecutarTick();
    void reiniciarEcosistema();

    // Métodos para manejar elementos
    bool agregarCriatura(const string& tipo, int x, int y);
    bool agregarRecurso(const string& tipo, int x, int y);
    bool eliminarElemento(int x, int y);
    bool moverCriatura(Criatura* criatura, int nuevaX, int nuevaY);

    // Métodos de consulta
    void* obtenerElementoEnPosicion(int x, int y) const;
    ColeccionT<Criatura>* obtenerCriaturas();
    ColeccionT<Recurso>* obtenerRecursos();
    Criatura* buscarCriaturaCercana(int x, int y, const string& tipo) const;
    Recurso* buscarRecursoCercano(int x, int y, const string& tipo) const;

    // Getters
    int getAncho() const { return ancho; }
    int getAlto() const { return alto; }
    int getTickActual() const { return tickActual; }
    int getTicksMaximos() const { return ticksMaximos; }
    int getNivelEnergiaTotalSistema() const { return nivelEnergiaTotalSistema; }
    bool estaSimulacionActiva() const { return simulacionActiva; }

    // Setters
    void setNivelEnergiaTotalSistema(int nivel);
    void modificarEnergiaSistema(int cambio);

    // Métodos de persistencia
    bool guardarEstado(const string& nombreArchivo) const;
    bool cargarEstado(const string& nombreArchivo);

    // Método para mostrar el estado actual
    void mostrarEstado() const;
    void mostrarEstadoDetallado() const;

    // Método para verificar si una posición está ocupada
    bool posicionOcupada(int x, int y) const;

    // Método para obtener estadísticas
    void obtenerEstadisticas(int& numHerbivoros, int& numCarnivoros, int& numOmnivoros,
        int& numAgua, int& numPlantas, int& numCarne) const;
};

#endif // ECOSISTEMA_H