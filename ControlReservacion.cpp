//
// Created by G-t-T on 1/07/2020.
//
#include <iostream>
#include "Reservacion/Reservacion.h"
#include "TipoHabitacion/TipoHabitacion.h"
#include "Habitacion/Habitacion.h"

static void agregarReservacion(Reservacion r[50], int& cant){
    /*
    Habitacion habitacion;
    int codigo;
    int cantidadPersonas;
    time_t fechaIngreso;
    time_t fechaSalida;
     */
    TipoHabitacion tp("individual", "una persona", 50);
    int ax1;
    time_t ax2;
    cout << "->Agregar Reservaciones" << endl;
    cout << "  Ingrese el codigo de reservacion: ";
    cin >> ax1;
    r[cant].setCodigo(ax1);
    cout << "  Ingrese el numero de habitacion: ";
    cin >> ax1;
    Habitacion hab(ax1,1,tp);
    r[cant].setHabitacion(hab);
    cout << "  Ingrese la cantidad de personas: ";
    cin >> ax1;
    r[cant].setCantidadPersonas(ax1);
    cout << "  Ingrese la fecha de ingreso: ";
    cin >> ax2;
    r[cant].setFechaIngreso(ax2);
    cout << "  Ingrese la fecha de salida: ";
    cin >> ax2;
    r[cant].setFechaSalida(ax2);
    cout << r[cant].getCodigo() << endl;
    cout << r[cant].getCantidadPErsonas() << endl;
    cout << r[cant].getFechaIngreso() << endl;
    cout << r[cant].getFechaSalida() << endl;
    cant++;
}
static void verReservaciones(Reservacion r[50]){
    string aux;
    cout << "Ver Reservaciones" << endl;
    cin >> aux;
}
static void buscarReservacion(Reservacion r[50], string busqueda){
    string aux;
    cout << "Buscar Reservaciones" << endl;
    cin >> aux;
}