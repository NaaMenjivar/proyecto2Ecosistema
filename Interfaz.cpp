#include "Interfaz.h"
#include <conio.h>         // Para _getch() en Windows
#include <ctime>
#include <cstdlib>      // Para system("cls") y system("pause")

int Interfaz::mostrarMenuPrincipal(){
    cout << "Bienvenido al Simulador de Ecosistema\n";
    int op;
    cout << "\n=== SIMULADOR DE ECOSISTEMA ===\n";
    cout << "1. Poblar ecosistema automaticamente\n";
    cout << "2. Crear criatura individual\n";
    cout << "3. Crear recurso individual\n";
    cout << "4. Cambiar clima\n";
    cout << "5. Mostrar estado del ecosistema\n";
    cout << "6. Simulacion por ticks (interactiva)\n";
    cout << "7. Guardar Archivos\n";
    cout << "8. Lectura Archivos\n";
    cout << "9. Salir\n";
    cout << "Seleccione una opcion: ";
    op = Interfaz::ingresarInt(1, 9);
    return op;
}
void Interfaz::mostrarMenuCrearCriatura(){
    cout << "\n=== CREAR CRIATURA ===\n";
    cout << "1. Carnivoro\n";
    cout << "2. Herbivoro\n";
    cout << "3. Omnivoro\n";
    cout << "Seleccione tipo: ";
}
void Interfaz::mostrarMenuCrearRecurso()
{
    cout << "\n=== CREAR RECURSO ===\n";
    cout << "1. Agua\n";
    cout << "2. Planta\n";
    cout << "3. Carne\n";
    cout << "Seleccione tipo: "; 
}
void Interfaz::mostrarMenuClima(){
    cout << "\n=== CAMBIAR CLIMA ===\n";
    cout << "D - Dia\n";
    cout << "T - Tarde\n";
    cout << "N - Noche\n";
    cout << "Seleccione clima: ";
}
void Interfaz::mostrarEstadoEcosistema(Ecosistema* eco){
    cout << "\n=== ESTADO DEL ECOSISTEMA ===\n";
    cout << "Clima actual: ";
    switch (eco->getClima()) {
    case 'D': cout << "Dia"; break;
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
void Interfaz::mostrarEstadoSimulacion(Ecosistema* eco, int tick){
    cout << "=== TICK " << tick << " ===\n";
    cout << "Clima: ";
    switch (eco->getClima()) {
    case 'D': cout << "Dia"; break;
    case 'T': cout << "Tarde"; break;
    case 'N': cout << "Noche"; break;
    default:  cout << "Desconocido"; break;
    }
    cout << " | Criaturas: " << eco->getCantMatCriaturas()
        << " | Recursos: " << eco->getCantMatRecursos() << "\n\n";
}

void Interfaz::poblarEcosistemaAutomaticamente(Ecosistema* eco) {
    system("cls");
    cout << "\nPoblando ecosistema automaticamente...\n";
    eco->poblarEcosistema(3, 2, 2);
    system("pause");
    system("cls");
}

int Interfaz::ingresarInt(int min)
{
    int x;
    bool valido = true;
    do {
        try {
            valido = true;
            cin >> x;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                valido = false;
                throw(ExcValInvalido());
            }
            if (x < min) {
                valido = false;
                throw(ExcValInf(min, x));
            }
        }
        catch (Excepcion& e) {
            cerr << "Error:" << e.porque() << endl;
            cin.ignore(1, '\n');
        }
        catch (const char* e) {
            cerr << e << endl;
        }
        catch (...) {
            cerr << "Error inesperado." << endl;
        }
    } while (!valido);
    return x;
}

int Interfaz::ingresarInt(int min, int max)
{
    int x;
    bool valido = true;
    do {
        try {
            valido = true;
            cin >> x;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                valido = false;
                throw(ExcValInvalido());
            }
            if (x < min) {
                valido = false;
                throw(ExcValInf(min, max, x));
            }
            if (x > max) {
                valido = false;
                throw(ExcValSup(min, max, x));
            }
        }
        catch (Excepcion& e) {
            cerr << "Error: " << e.porque() << endl;
        }
        catch (...) {
            cerr << "Error inesperado." << endl;
        }
    } while (!valido);
    return x;
}

string Interfaz::ingresarString()
{
    string s;
    getline(cin, s, '\n');
    return s;
}

char Interfaz::ingresarChar()
{
    char x;
    bool valido = true;
    do {
        try {
            valido = true;
            cin >> x;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(100, '\n');
                valido = false;
                throw(ExcValInvalido());
            }
            // Verificar si es uno de los caracteres permitidos para los tipos de materiales
            if (x != 'D' && x != 'N' &&
                x != 'T') {
                valido = false;
                throw(ExcCharInvalido(x, "D, T, N"));
            }
        }
        catch (Excepcion& e) {
            cerr << "Error: " << e.porque() << endl;
            cin.ignore(100, '\n');
        }
        catch (const char* e) {
            cerr << e << endl;
        }
        catch (...) {
            cerr << "Error inesperado." << endl;
        }
    } while (!valido);
    return x;
}

void Interfaz::crearCriatura(Ecosistema* eco) {
    system("cls");
    mostrarMenuCrearCriatura();
    int tipoCriatura = Interfaz::ingresarInt(1, 3);

    int x, y, energia;
    cout << "Ingrese posicion X: "; x = Interfaz::ingresarInt(0, 9);
    cout << "Ingrese posicion Y: "; y= Interfaz::ingresarInt(0, 9);
    cout << "Ingrese energia inicial: "; energia = Interfaz::ingresarInt(1);

    switch (tipoCriatura) {
    case 1: eco->crearCarnivoro(x, y, energia); break;
    case 2: eco->crearHerbivoro(x, y, energia); break;
    case 3: eco->crearOmnivoro(x, y, energia); break;
    default: cout << "Opcion invalida.\n"; break;
    }
    system("pause");
    system("cls");
}

void Interfaz::crearRecurso(Ecosistema* eco) {
    system("cls");
    mostrarMenuCrearRecurso();
    int tipoR = Interfaz::ingresarInt(1, 3);

    int x, y, valor;
    cout << "Ingrese posicion X: "; x = Interfaz::ingresarInt(0, 9); 
    cout << "Ingrese posicion Y: "; y = Interfaz::ingresarInt(0, 9); 
    cout << "Ingrese valor nutricional: "; valor = Interfaz::ingresarInt(1); 

    switch (tipoR) {
    case 1: eco->crearAgua(x, y, valor);  break;
    case 2: eco->crearPlanta(x, y, valor); break;
    case 3: eco->crearCarne(x, y, valor); break;
    default: cout << "Tipo de recurso invalido.\n"; break;
    }
    system("pause");
    system("cls");
}


void Interfaz::cambiarClima(Ecosistema* eco) {
    system("cls");
    mostrarMenuClima();
    char nuevoClima = Interfaz::ingresarChar();
    if (nuevoClima == 'D'||nuevoClima =='d' || nuevoClima == 'T'||nuevoClima =='t' || nuevoClima == 'N'||nuevoClima == 'n') {
        eco->setClima(nuevoClima);
    }
    else {
        cout << "Clima invalido.\n";
    }
    system("pause");
    system("cls");
}

void Interfaz::mostrarEstadoEcosis(Ecosistema* eco) {
    system("cls");
    mostrarEstadoEcosistema(eco);
    system("pause");
    system("cls");
}

void Interfaz::simulacionPorTicks(Ecosistema* eco) {
    system("cls");
    int maxTicks;
    cout << "\nIngrese cantidad maxima de ticks: ";
    maxTicks = Interfaz::ingresarInt(1);
    cin.ignore();

    cout << "\nIniciando simulacion interactiva...\n"
        "Controles:\n"
        "[ESPACIO] - un tick\n"
        "[s]       - salir\n"
        << "Presione cualquier tecla para comenzar...";
    _getch();

    int ticks = 0;
    while (ticks < maxTicks) {
        char tecla = _getch();
        if (tecla == 's' || tecla == 'S') {
            cout << "\nSimulacion detenida por el usuario.\n";
            break;
        }
        if (tecla == ' ') {
            ++ticks;
            system("cls");
            mostrarEstadoSimulacion(eco, ticks);
            eco->simularxTicks(1);
            cout << "\n[ESPACIO] siguiente tick | [s] salir";
        }
    }
    if (ticks >= maxTicks) {
        cout << "\nSimulacion completada. Presione una tecla...";
        _getch();
    }
    system("pause");
    system("cls");
}

void Interfaz::GuardadoArchivos(Ecosistema* eco) {
    system("cls");
    eco->GuardarCriaturas("Criaturas");
    eco->GuardarRecrusos("Recursos");
    cout << "Recursos guardados...";
    system("pause");
    system("cls");
}
void Interfaz::LecturaArchivos(Ecosistema* eco){
    system("cls");
    eco->LecturaCriaturas("Criaturas");
    eco->LecturaRecursos("Recursos");
    system("pause");
    system("cls");
}
