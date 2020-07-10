//
// Created by Jerbo on 18/06/2020.
//

#include "Reservacion.h"
#include <iostream>
#include "../Conexion/Conexion.h"

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
    int cant = 0, op = 0;
    //Conexion cx;
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
                //agregarReservacion(reservaciones,cant);
                break;
            case 2:
                system("cls");
                //verReservaciones(reservaciones, cant);
                //cx.consultaBD();
                break;
            case 3:
                system("cls");
                //buscarReservacion(reservaciones, cant);
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
