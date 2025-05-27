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

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Ecosistema.h"
#include "Observer.h"
#include <string>

// Clase Cliente que maneja la interfaz de usuario y controla el programa
class Cliente : public Observer {
private:
    Ecosistema* ecosistema;
    bool programaEnEjecucion;
    bool modoAutomatico;
    int ticksEntreComandos;

    // Métodos privados para el menú
    void mostrarMenuPrincipal();
    void mostrarMenuConfiguracion();
    void mostrarMenuVisualizacion();
    void mostrarAyuda();

    // Métodos para manejar comandos
    void procesarComandoPrincipal(const string& comando);
    void procesarComandoConfiguracion(const string& comando);
    void procesarComandoVisualizacion(const string& comando);

    // Métodos de configuración
    void configurarEcosistema();
    void agregarElementos();
    void modificarParametros();
    void configurarSimulacion();

    // Métodos de visualización
    void mostrarEstadoGeneral();
    void mostrarEstadoDetallado();
    void mostrarEstadisticas();
    void mostrarMapa();

    // Métodos de simulación
    void iniciarSimulacionAutomatica();
    void ejecutarSimulacionManual();
    void pausarSimulacion();
    void reanudarSimulacion();
    void reiniciarSimulacion();

    // Métodos de persistencia
    void guardarEstado();
    void cargarEstado();
    void exportarDatos();

    // Métodos de utilidad
    void limpiarPantalla();
    void esperarEnter();
    bool confirmarAccion(const string& mensaje);
    int leerEntero(const string& mensaje, int minimo = 0, int maximo = 1000);
    string leerCadena(const string& mensaje);

    // Métodos para validación de entrada
    bool esComandoValido(const string& comando, const string& contexto);
    void mostrarComandosDisponibles(const string& contexto);

public:
    // Constructor y Destructor
    Cliente();
    virtual ~Cliente();

    // Método principal para ejecutar el programa
    void ejecutar();

    // Override del método Update del Observer
    virtual void Update() override;

    // Métodos públicos de control
    void inicializar();
    void finalizar();
    void mostrarBienvenida();
    void mostrarDespedida();

    // Getters y Setters
    bool estaProgramaEnEjecucion() const { return programaEnEjecucion; }
    void setProgramaEnEjecucion(bool estado) { programaEnEjecucion = estado; }

    bool esModoAutomatico() const { return modoAutomatico; }
    void setModoAutomatico(bool modo) { modoAutomatico = modo; }

    int getTicksEntreComandos() const { return ticksEntreComandos; }
    void setTicksEntreComandos(int ticks) { ticksEntreComandos = ticks; }
};

#endif // CLIENTE_H