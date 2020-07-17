//
// Created by Jerbo on 18/06/2020.
//

#include "Reservacion.h"
#include <iostream>
#include "../Conexion/Conexion.h"
#include "../Habitacion/Habitacion.h"

int Reservacion::getCodigo() const {
    return codigo;
}

void Reservacion::setCodigo(int codigo) {
    Reservacion::codigo = codigo;
}

int Reservacion::getCantidadPErsonas() const {
    return cantidadPErsonas;
}

void Reservacion::setCantidadPErsonas(int cantidadPErsonas) {
    Reservacion::cantidadPErsonas = cantidadPErsonas;
}

time_t Reservacion::getFechaIngreso() const {
    return fechaIngreso;
}

void Reservacion::setFechaIngreso(time_t fechaIngreso) {
    Reservacion::fechaIngreso = fechaIngreso;
}

time_t Reservacion::getFechaSalida() const {
    return fechaSalida;
}

void Reservacion::setFechaSalida(time_t fechaSalida) {
    Reservacion::fechaSalida = fechaSalida;
}

const Habitacion &Reservacion::getHabitacion() const {
    return habitacion;
}

void Reservacion::setHabitacion(const Habitacion &habitacion) {
    Reservacion::habitacion = habitacion;
}

void Reservacion::menuReservacion() {
    setlocale(LC_ALL,"Spanish");
    int cant = 0, op = 0;
    string aux,aux1,aux2,aux3;
    Conexion cx;
    Habitacion h;
    Cliente cl;
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
                cout << "-Añadir reservacion-" << endl;
                cout << "  Ingrese ID de la reservacion: ";
                cin >> aux;
                cout << "  Lista de habitaciones" << endl;
                h.consultaHabitaciones();
                cout << "  Ingrese el numero de la habitacion: ";
                cin >> aux1;
                cout << "  Lista de clientes" << endl;
                cl.consultaNombres();
                cout << "  Ingrese ID del cliente: ";
                cin >> aux2;
                cout << "  Ingrese fecha (AAAA-MM-DD HH:MM:SS): ";
                getline (cin,aux3);
                cx.agregarReservacion(aux,aux1,aux2,aux3);
                break;
            case 2:
                system("cls");
                //verReservaciones(reservaciones, cant);
                cx.consultaReservaciones();
                break;
            case 3:
                system("cls");
                cout << "-Buscar reservacion-" << endl;
                cout << "  Ingrese ID de la reservacion:";
                cin >> aux;
                //buscarReservacion(reservaciones, cant);
                cx.buscarReservacion(aux);
                cout << " ¿Que desea hacer?, seleccione una opcion:" << endl;
                cout << " (1)Modificar reservacion" << endl;
                cout << " (2)Cancelar reservacion" << endl;
                cout << " (3)Volver" << endl;
                cin >> op;
                if(op == 1){
                    cout << "  Ingrese los nuevos datos" << endl;
                    cout << "   Lista de habitaciones" << endl;
                    h.consultaHabitaciones();
                    cout << "   Ingrese el numero de la habitacion: ";
                    cin >> aux1;
                    cout << "   Lista de clientes" << endl;
                    cl.consultaNombres();
                    cout << "   Ingrese ID del cliente: ";
                    cin >> aux2;
                    cout << "   Ingrese fecha (AAAA-MM-DD HH:MM:SS): ";
                    getline (cin,aux3);
                    cx.modificarReservacion(aux,aux1,aux2,aux3);
                }else if(op == 2){
                    cx.eliminarReservacion(aux);
                }else if(op == 3){
                    break;
                }else{
                    cout << "Opcion incorrecta" << endl;
                }
                break;
            case 4:
                break;
            default:
                cout << "Opcion incorrecta: Ingrese una valida o 4 para volver" << endl;
                break;
        }
    }
}

Reservacion::Reservacion() {}

Reservacion::~Reservacion() {

}
