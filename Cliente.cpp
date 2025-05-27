#include "Cliente.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Cliente::Cliente() : Observer(), ecosistema(nullptr), programaEnEjecucion(false),
modoAutomatico(false), ticksEntreComandos(1) {
    ecosistema = Ecosistema::obtenerInstancia();
    ecosistema->AddObserver(this);
}

Cliente::~Cliente() {
    if (ecosistema) {
        ecosistema->RemObserver(this);
    }
}

void Cliente::ejecutar() {
    inicializar();
    mostrarBienvenida();

    while (programaEnEjecucion) {
        mostrarMenuPrincipal();
        string comando;
        cout << "Ingrese comando: ";
        getline(cin, comando);
        procesarComandoPrincipal(comando);
    }

    mostrarDespedida();
    finalizar();
}

void Cliente::Update() {
    if (modoAutomatico) {
        mostrarEstadoGeneral();
    }
}

void Cliente::inicializar() {
    programaEnEjecucion = true;
    modoAutomatico = false;
    ticksEntreComandos = 10;
}

void Cliente::finalizar() {
    if (ecosistema) {
        ecosistema->detenerSimulacion();
    }
}

void Cliente::mostrarBienvenida() {
    limpiarPantalla();
    cout << "=====================================" << endl;
    cout << "  SIMULADOR DE ECOSISTEMA v1.0.0" << endl;
    cout << "=====================================" << endl;
    cout << "Bienvenido al simulador de ecosistema" << endl;
    cout << "Presione ENTER para continuar...";
    esperarEnter();
}

void Cliente::mostrarDespedida() {
    limpiarPantalla();
    cout << "=====================================" << endl;
    cout << "   GRACIAS POR USAR EL SIMULADOR" << endl;
    cout << "=====================================" << endl;
    cout << "�Hasta la pr�xima!" << endl;
}

void Cliente::mostrarMenuPrincipal() {
    limpiarPantalla();
    cout << "\n=== MEN� PRINCIPAL ===" << endl;
    cout << "1. Configuraci�n" << endl;
    cout << "2. Simulaci�n" << endl;
    cout << "3. Visualizaci�n" << endl;
    cout << "4. Persistencia" << endl;
    cout << "5. Ayuda" << endl;
    cout << "0. Salir" << endl;
    cout << "======================" << endl;
}

void Cliente::procesarComandoPrincipal(const string& comando) {
    if (comando == "1") {
        mostrarMenuConfiguracion();
    }
    else if (comando == "2") {
        iniciarSimulacionAutomatica();
    }
    else if (comando == "3") {
        mostrarMenuVisualizacion();
    }
    else if (comando == "4") {
        guardarEstado();
    }
    else if (comando == "5") {
        mostrarAyuda();
    }
    else if (comando == "0") {
        if (confirmarAccion("�Est� seguro que desea salir?")) {
            programaEnEjecucion = false;
        }
    }
    else {
        cout << "Comando no v�lido. Presione ENTER para continuar...";
        esperarEnter();
    }
}

void Cliente::mostrarMenuConfiguracion() {
    bool enConfiguracion = true;
    while (enConfiguracion) {
        limpiarPantalla();
        cout << "\n=== CONFIGURACI�N ===" << endl;
        cout << "1. Agregar elementos" << endl;
        cout << "2. Modificar par�metros" << endl;
        cout << "3. Configurar simulaci�n" << endl;
        cout << "0. Volver al men� principal" << endl;
        cout << "=====================" << endl;

        string comando;
        cout << "Ingrese comando: ";
        getline(cin, comando);

        if (comando == "1") {
            agregarElementos();
        }
        else if (comando == "2") {
            modificarParametros();
        }
        else if (comando == "3") {
            configurarSimulacion();
        }
        else if (comando == "0") {
            enConfiguracion = false;
        }
    }
}

void Cliente::mostrarMenuVisualizacion() {
    bool enVisualizacion = true;
    while (enVisualizacion) {
        limpiarPantalla();
        cout << "\n=== VISUALIZACI�N ===" << endl;
        cout << "1. Estado general" << endl;
        cout << "2. Estado detallado" << endl;
        cout << "3. Estad�sticas" << endl;
        cout << "4. Mostrar mapa" << endl;
        cout << "0. Volver al men� principal" << endl;
        cout << "=====================" << endl;

        string comando;
        cout << "Ingrese comando: ";
        getline(cin, comando);

        if (comando == "1") {
            mostrarEstadoGeneral();
            esperarEnter();
        }
        else if (comando == "2") {
            mostrarEstadoDetallado();
            esperarEnter();
        }
        else if (comando == "3") {
            mostrarEstadisticas();
            esperarEnter();
        }
        else if (comando == "4") {
            mostrarMapa();
            esperarEnter();
        }
        else if (comando == "0") {
            enVisualizacion = false;
        }
    }
}

void Cliente::agregarElementos() {
    cout << "\n=== AGREGAR ELEMENTOS ===" << endl;
    cout << "Tipos disponibles:" << endl;
    cout << "Criaturas: herbivoro, carnivoro, omnivoro" << endl;
    cout << "Recursos: agua, planta, carne" << endl;

    string tipo = leerCadena("Tipo de elemento: ");
    int x = leerEntero("Posici�n X: ", 0, ecosistema->getAncho() - 1);
    int y = leerEntero("Posici�n Y: ", 0, ecosistema->getAlto() - 1);

    bool exito = false;
    if (tipo == "herbivoro" || tipo == "carnivoro" || tipo == "omnivoro") {
        exito = ecosistema->agregarCriatura(tipo, x, y);
    }
    else if (tipo == "agua" || tipo == "planta" || tipo == "carne") {
        exito = ecosistema->agregarRecurso(tipo, x, y);
    }

    if (exito) {
        cout << "Elemento agregado exitosamente!" << endl;
    }
    else {
        cout << "Error al agregar elemento (posici�n ocupada o tipo inv�lido)" << endl;
    }
    esperarEnter();
}

void Cliente::mostrarEstadoGeneral() {
    limpiarPantalla();
    cout << "\n=== ESTADO DEL ECOSISTEMA ===" << endl;
    cout << "Tick actual: " << ecosistema->getTickActual() << endl;
    cout << "Energ�a del sistema: " << ecosistema->getNivelEnergiaTotalSistema() << endl;

    int herbivoros, carnivoros, omnivoros, agua, plantas, carne;
    ecosistema->obtenerEstadisticas(herbivoros, carnivoros, omnivoros, agua, plantas, carne);

    cout << "Criaturas - H:" << herbivoros << " C:" << carnivoros << " O:" << omnivoros << endl;
    cout << "Recursos - Agua:" << agua << " Plantas:" << plantas << " Carne:" << carne << endl;
    cout << "============================" << endl;
}

void Cliente::mostrarEstadoDetallado() {
    ecosistema->mostrarEstadoDetallado();
}

void Cliente::mostrarEstadisticas() {
    int herbivoros, carnivoros, omnivoros, agua, plantas, carne;
    ecosistema->obtenerEstadisticas(herbivoros, carnivoros, omnivoros, agua, plantas, carne);

    cout << "\n=== ESTAD�STICAS DETALLADAS ===" << endl;
    cout << "Total de criaturas: " << (herbivoros + carnivoros + omnivoros) << endl;
    cout << "  - Herb�voros: " << herbivoros << endl;
    cout << "  - Carn�voros: " << carnivoros << endl;
    cout << "  - Omn�voros: " << omnivoros << endl;
    cout << "Total de recursos: " << (agua + plantas + carne) << endl;
    cout << "  - Agua: " << agua << endl;
    cout << "  - Plantas: " << plantas << endl;
    cout << "  - Carne: " << carne << endl;
    cout << "===============================" << endl;
}

void Cliente::mostrarMapa() {
    cout << "\n=== MAPA DEL ECOSISTEMA ===" << endl;
    for (int y = 0; y < ecosistema->getAlto() && y < 20; y++) {
        for (int x = 0; x < ecosistema->getAncho() && x < 40; x++) {
            if (ecosistema->posicionOcupada(x, y)) {
                cout << "X";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << "===========================" << endl;
}

void Cliente::iniciarSimulacionAutomatica() {
    cout << "\n=== SIMULACI�N AUTOM�TICA ===" << endl;
    int ticks = leerEntero("N�mero de ticks (0 = infinito): ", 0, 10000);

    modoAutomatico = true;
    ecosistema->iniciarSimulacion(ticks == 0 ? 99999 : ticks);

    cout << "Presione ENTER para continuar..." << endl;
    esperarEnter();

    modoAutomatico = false;
    ecosistema->detenerSimulacion();
    cout << "Simulaci�n detenida." << endl;
}

void Cliente::guardarEstado() {
    string archivo = leerCadena("Nombre del archivo: ");
    if (ecosistema->guardarEstado(archivo + ".txt")) {
        cout << "Estado guardado exitosamente." << endl;
    }
    else {
        cout << "Error al guardar el archivo." << endl;
    }
    esperarEnter();
}

void Cliente::cargarEstado() {
    string archivo = leerCadena("Nombre del archivo: ");
    if (ecosistema->cargarEstado(archivo + ".txt")) {
        cout << "Estado cargado exitosamente." << endl;
    }
    else {
        cout << "Error al cargar el archivo." << endl;
    }
    esperarEnter();
}

void Cliente::limpiarPantalla() {
    // Implementaci�n multiplataforma b�sica
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

void Cliente::esperarEnter() {
    cout << "Presione ENTER para continuar...";
    string temp;
    getline(cin, temp);
}

bool Cliente::confirmarAccion(const string& mensaje) {
    cout << mensaje << " (s/n): ";
    string respuesta;
    getline(cin, respuesta);
    return (respuesta == "s" || respuesta == "S" || respuesta == "si" || respuesta == "SI");
}

int Cliente::leerEntero(const string& mensaje, int minimo, int maximo) {
    while (true) {
        cout << mensaje;
        string entrada;
        getline(cin, entrada);
        stringstream ss(entrada);
        int valor;
        if (ss >> valor && valor >= minimo && valor <= maximo) {
            return valor;
        }
        cout << "Valor inv�lido. Debe estar entre " << minimo << " y " << maximo << endl;
    }
}

string Cliente::leerCadena(const string& mensaje) {
    cout << mensaje;
    string valor;
    getline(cin, valor);
    return valor;
}

bool Cliente::esComandoValido(const string& comando, const string& contexto) {
    // Implementaci�n b�sica de validaci�n
    return !comando.empty();
}

void Cliente::mostrarComandosDisponibles(const string& contexto) {
    cout << "Comandos disponibles para " << contexto << endl;
}

// M�todos stub para completar la interfaz
void Cliente::mostrarAyuda() {
    cout << "\n=== AYUDA ===" << endl;
    cout << "1. Use el men� de configuraci�n para agregar elementos" << endl;
    cout << "2. Use simulaci�n para iniciar el ecosistema" << endl;
    cout << "3. Use visualizaci�n para ver el estado" << endl;
    cout << "4. Use persistencia para guardar/cargar" << endl;
    esperarEnter();
}

void Cliente::modificarParametros() {
    cout << "=== MODIFICAR PAR�METROS ===" << endl;
    int energia = leerEntero("Nueva energ�a del sistema: ", 1000, 50000);
    ecosistema->setNivelEnergiaTotalSistema(energia);
    cout << "Par�metros modificados exitosamente" << endl;
    esperarEnter();
}

void Cliente::configurarSimulacion() {
    cout << "=== CONFIGURAR SIMULACI�N ===" << endl;
    int ticks = leerEntero("Ticks entre comandos: ", 1, 100);
    setTicksEntreComandos(ticks);
    cout << "Configuraci�n guardada" << endl;
    esperarEnter();
}

void Cliente::ejecutarSimulacionManual() { cout << "Simulaci�n manual no implementada" << endl; esperarEnter(); }
void Cliente::pausarSimulacion() { ecosistema->detenerSimulacion(); }
void Cliente::reanudarSimulacion() { cout << "Reanudar simulaci�n no implementado" << endl; }
void Cliente::reiniciarSimulacion() { ecosistema->reiniciarEcosistema(); }
void Cliente::exportarDatos() { cout << "Exportar datos no implementado" << endl; esperarEnter(); }