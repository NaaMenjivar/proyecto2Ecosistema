#include "Ecosistema.h"
#include "CriaturaFactory.h"
#include <conio.h>         // Para _getch() en Windows
#include <ctime>
#include <cstdlib>      // Para system("cls") y system("pause")


void mostrarMenuPrincipal() {
    cout << "\n=== SIMULADOR DE ECOSISTEMA ===\n";
    cout << "1. Poblar ecosistema automticamente\n";
    cout << "2. Crear criatura individual\n";
    cout << "3. Crear recurso individual\n";
    cout << "4. Cambiar clima\n";
    cout << "5. Mostrar estado del ecosistema\n";
    cout << "6. Simulación por ticks (interactiva)\n";
    cout << "7. Salir\n";
    cout << "Seleccione una opción: ";
}

void mostrarMenuCrearCriatura() {
    cout << "\n=== CREAR CRIATURA ===\n";
    cout << "1. Carnivoro\n";
    cout << "2. Herbivoro\n";
    cout << "3. Omnivoro\n";
    cout << "Seleccione tipo: ";
}

void mostrarMenuClima() {
    cout << "\n=== CAMBIAR CLIMA ===\n";
    cout << "D - Dia\n";
    cout << "T - Tarde\n";
    cout << "N - Noche\n";
    cout << "Seleccione clima: ";
}

void mostrarEstadoEcosistema(Ecosistema* eco) {
    cout << "\n=== ESTADO DEL ECOSISTEMA ===\n";
    cout << "Clima actual: ";
    switch (eco->getClima()) {
    case 'D': cout << "Día"; break;
    case 'T': cout << "Tarde"; break;
    case 'N': cout << "Noche"; break;
    default:  cout << "Desconocido"; break;
    }
    cout << "\n\n";

    // Contar tipos de criaturas
    int carnivoros = 0, herbivoros = 0, omnivoros = 0;
    for (int i = 0; i < eco->getTamanioC(); ++i) {
        Criatura* c = eco->obtenerC(i);
        if (!c) continue;
        string tipo = c->getTipo();
        if (tipo == "Carnivoro") carnivoros++;
        else if (tipo == "Herbivoro") herbivoros++;
        else if (tipo == "Omnivoro")  omnivoros++;
    }

    // Contar tipos de recursos
    int agua = 0, carne = 0, plantas = 0;
    for (int i = 0; i < eco->getTamanioR(); ++i) {
        Recurso* r = eco->obtenerR(i);
        if (!r) continue;
        string tipo = r->getTipo();
        if (tipo == "Agua")   agua++;
        else if (tipo == "Carne")  carne++;
        else if (tipo == "Planta") plantas++;
    }

    cout << "Carnivoros: " << carnivoros << "\n";
    cout << "Herbivoros: " << herbivoros << "\n";
    cout << "Omnivoros:  " << omnivoros << "\n\n";

    cout << "Agua:   " << agua << "\n";
    cout << "Plantas:" << plantas << "\n";
    cout << "Carne:  " << carne << "\n\n";

    cout << "Total de criaturas: " << eco->getTamanioC() << "\n";
    cout << "Total de recursos:  " << eco->getTamanioR() << "\n\n";
}

void mostrarEstadoSimulacion(Ecosistema* eco, int tick) {
    cout << "=== TICK " << tick << " ===\n";
    cout << "Clima: ";
    switch (eco->getClima()) {
    case 'D': cout << "Dia"; break;
    case 'T': cout << "Tarde"; break;
    case 'N': cout << "Noche"; break;
    default:  cout << "Desconocido"; break;
    }
    cout << " | Criaturas: " << eco->getTamanioC()
        << " | Recursos: " << eco->getTamanioR() << "\n\n";
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    Ecosistema* ecosistema = new Ecosistema();
    cout << "Bienvenido al Simulador de Ecosistema\n";

    bool continuar = true;
    while (continuar) {
        mostrarMenuPrincipal();
        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "\nPoblando ecosistema automaticamente...\n";
            ecosistema->poblarEcosistema(3, 2, 2);
            break;
        }
        case 2: {
            mostrarMenuCrearCriatura();
            int tipoCriatura;
            cin >> tipoCriatura;

            int x, y, energia;
            cout << "Ingrese posicion X: "; cin >> x;
            cout << "Ingrese posicion Y: "; cin >> y;
            cout << "Ingrese energia inicial: "; cin >> energia;

            switch (tipoCriatura) {
            case 1: ecosistema->crearCarnivoro(x, y, energia); break;
            case 2: ecosistema->crearHerbivoro(x, y, energia); break;
            case 3: ecosistema->crearOmnivoro(x, y, energia); break;
            default: cout << "Opcion invalida.\n"; break;
            }
            break;
        }
        case 3: {
            cout << "\n=== CREAR RECURSO ===\n";
            cout << "1. Agua\n2. Planta\n3. Carne\nSeleccione tipo: ";
            int tipoR;
            cin >> tipoR;

            int x, y, valor;
            cout << "Ingrese posicion X: ";           cin >> x;
            cout << "Ingrese posicion Y: ";           cin >> y;
            cout << "Ingrese valor nutricional: ";    cin >> valor;

            switch (tipoR) {
            case 1: ecosistema->crearAgua(x, y, valor);  break;
            case 2: ecosistema->crearPlanta(x, y, valor); break;
            case 3: ecosistema->crearCarne(x, y, valor); break;
            default: cout << "Tipo de recurso invalido.\n"; break;
            }
            break;
        }
        case 4: {
            mostrarMenuClima();
            char nuevoClima;
            cin >> nuevoClima;
            if (nuevoClima == 'D' || nuevoClima == 'T' || nuevoClima == 'N') {
                ecosistema->setClima(nuevoClima);
            }
            else {
                cout << "Clima invalido.\n";
            }
            break;
        }
        case 5: {
            mostrarEstadoEcosistema(ecosistema);
            break;
        }
        case 6: {
            int maxTicks;
            cout << "\nIngrese cantidad máxima de ticks: ";
            cin >> maxTicks;
            cin.ignore();

            cout << "\nIniciando simulación interactiva...\n"
                "Controles:\n"
                "[ESPACIO] - un tick\n"
                "[s]       - salir\n"
                << "Presione cualquier tecla para comenzar...";
            _getch();

            int ticks = 0;
            while (ticks < maxTicks) {
                char tecla = _getch();
                if (tecla == 's' || tecla == 'S') {
                    cout << "\nSimulación detenida por el usuario.\n";
                    break;
                }
                if (tecla == ' ') {
                    ++ticks;
                    system("cls");
                    mostrarEstadoSimulacion(ecosistema, ticks);
                    ecosistema->simularxTicks(1);
                    cout << "\n[ESPACIO] siguiente tick | [s] salir";
                }
            }
            if (ticks >= maxTicks) {
                cout << "\nSimulación completada. Presione una tecla...";
                _getch();
            }
            break;
        }
        case 7:
            continuar = false;
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    }

    delete ecosistema;
    system("pause");
    return 0;
}
