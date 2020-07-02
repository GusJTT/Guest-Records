#include <iostream>
#include "MetodosReservacion.cpp"
int main() {
    int cant = 0, op = 0;
    Reservacion reservaciones[50];
    while(op != 4) {
        cout << "--Administracion de reservaciones--" << endl;
        cout << "  Seleccione una opcion:" << endl;
        cout << "  (1)Añadir reservacion" << endl;
        cout << "  (2)Ver reservaciones" << endl;
        cout << "  (3)Buscar reservaciones" << endl;
        cout << "  (4)Volver" << endl;
        cin >> op;
        switch(op) {
            case 1:
                system("cls");
                agregarReservacion(reservaciones,cant);
                break;
            case 2:
                system("cls");
                verReservaciones(reservaciones, cant);
                break;
            case 3:
                system("cls");
                buscarReservacion(reservaciones, "");
                break;
            case 4:
                break;
            default:
                cout << "Opcion incorrecta: Ingrese una valida o 4 para volver" << endl;
                break;
        }
    }
    return 0;
}
