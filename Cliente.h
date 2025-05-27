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

    // M�todos privados para el men�
    void mostrarMenuPrincipal();
    void mostrarMenuConfiguracion();
    void mostrarMenuVisualizacion();
    void mostrarAyuda();

    // M�todos para manejar comandos
    void procesarComandoPrincipal(const string& comando);
    void procesarComandoConfiguracion(const string& comando);
    void procesarComandoVisualizacion(const string& comando);

    // M�todos de configuraci�n
    void configurarEcosistema();
    void agregarElementos();
    void modificarParametros();
    void configurarSimulacion();

    // M�todos de visualizaci�n
    void mostrarEstadoGeneral();
    void mostrarEstadoDetallado();
    void mostrarEstadisticas();
    void mostrarMapa();

    // M�todos de simulaci�n
    void iniciarSimulacionAutomatica();
    void ejecutarSimulacionManual();
    void pausarSimulacion();
    void reanudarSimulacion();
    void reiniciarSimulacion();

    // M�todos de persistencia
    void guardarEstado();
    void cargarEstado();
    void exportarDatos();

    // M�todos de utilidad
    void limpiarPantalla();
    void esperarEnter();
    bool confirmarAccion(const string& mensaje);
    int leerEntero(const string& mensaje, int minimo = 0, int maximo = 1000);
    string leerCadena(const string& mensaje);

    // M�todos para validaci�n de entrada
    bool esComandoValido(const string& comando, const string& contexto);
    void mostrarComandosDisponibles(const string& contexto);

public:
    // Constructor y Destructor
    Cliente();
    virtual ~Cliente();

    // M�todo principal para ejecutar el programa
    void ejecutar();

    // Override del m�todo Update del Observer
    virtual void Update() override;

    // M�todos p�blicos de control
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