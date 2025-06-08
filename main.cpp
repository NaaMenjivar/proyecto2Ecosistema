#include "Ecosistema.h"
#include "CriaturaFactory.h"

void mostrarMenuPrincipal() {
    cout << "\n=== SIMULADOR DE ECOSISTEMA ===" << endl;
    cout << "1. Poblar ecosistema automaticamente" << endl;
    cout << "2. Crear criatura individual" << endl;
    cout << "3. Cambiar clima" << endl;
    cout << "4. Simular ciclo" << endl;
    cout << "5. Mostrar estado del ecosistema" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarMenuCrearCriatura() {
    cout << "\n=== CREAR CRIATURA ===" << endl;
    cout << "1. Carnivoro" << endl;
    cout << "2. Herbivoro" << endl;
    cout << "3. Omnivoro" << endl;
    cout << "Seleccione tipo: ";
}

void mostrarMenuClima() {
    cout << "\n=== CAMBIAR CLIMA ===" << endl;
    cout << "D - Dia" << endl;
    cout << "T - Tarde" << endl;
    cout << "N - Noche" << endl;
    cout << "Seleccione clima: ";
}

void mostrarEstadoEcosistema(Ecosistema* eco) {
    cout << "\n=== ESTADO DEL ECOSISTEMA ===" << endl;
    cout << "Clima actual: ";
    char clima = eco->getClima();
    switch (clima) {
    case 'D': cout << "Dia"; break;
    case 'T': cout << "Tarde"; break;
    case 'N': cout << "Noche"; break;
    default: cout << "Desconocido"; break;
    }
    cout << endl;

    cout << "Total de criaturas: " << eco->getTamanioC() << endl;

    // Contar tipos de criaturas
    int carnivoros = 0, herbivoros = 0, omnivoros = 0;
    for (int i = 0; i < eco->getTamanioC(); i++) {
        Criatura* c = eco->obtenerC(i);
        if (c != nullptr) {
            string tipo = c->getTipo();
            if (tipo == "Carnivoro") carnivoros++;
            else if (tipo == "Herbivoro") herbivoros++;
            else if (tipo == "Omnivoro") omnivoros++;
        }
    }

    cout << "Carnivoros: " << carnivoros << endl;
    cout << "Herbivoros: " << herbivoros << endl;
    cout << "Omnivoros: " << omnivoros << endl;
    cout << "Total de criaturas: " << eco->getTamanioC() << endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    // Crear ecosistema
    Ecosistema* ecosistema = new Ecosistema();

    cout << "¡Bienvenido al Simulador de Ecosistema!" << endl;

    int opcion;
    bool continuar = true;

    while (continuar) {
        mostrarMenuPrincipal();
        cin >> opcion;
        switch (opcion) {
        case 1: {
            cout << "\nPoblando ecosistema automaticamente..." << endl;
            ecosistema->poblarEcosistema(3, 5, 2); // 3 carnívoros, 5 herbívoros, 2 omnívoros default...
            break;
        }
        case 2: {
            mostrarMenuCrearCriatura();
            int tipoCriatura;
            cin >> tipoCriatura;

            int x, y, energia;
            cout << "Ingrese posicion X: ";
            cin >> x;
            cout << "Ingrese posicion Y: ";
            cin >> y;
            cout << "Ingrese energia inicial: ";
            cin >> energia;

            switch (tipoCriatura) {
            case 1:
                ecosistema->crearCarnivoro(x, y, energia);
                break;
            case 2:
                ecosistema->crearHerbivoro(x, y, energia);
                break;
            case 3:
                ecosistema->crearOmnivoro(x, y, energia);
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
            }
            break;
        }
        case 3: {
            mostrarMenuClima();
            char nuevoClima; cin >> nuevoClima;

            if (nuevoClima == 'D' || nuevoClima == 'T' || nuevoClima == 'N') {
                cout << "\nCambiando clima..." << endl;
                ecosistema->setClima(nuevoClima);
                cout << "¡Clima cambiado! Todas las criaturas han sido notificadas." << endl;
            }
            else {
                cout << "Clima invalido." << endl;
            }
            break;
        }
        case 4: {
            cout << "\nSimulando un ciclo del ecosistema..." << endl;
            ecosistema->simularCiclo();
            break;
        }
        case 5: {
            mostrarEstadoEcosistema(ecosistema);
            break;
        }
        case 6: {
            continuar = false;
            cout << "\n¡Gracias por usar el Simulador de Ecosistema!" << endl;
            break;
        }
        default: {
            cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
            break;
        }
        }
    }
    // Limpiar memoria
    delete ecosistema;
    system("pause");
    return 0;
}