//
// Created by Jerbo on 18/06/2020.
//

#include "Reservacion.h"

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

Reservacion::Reservacion() {}

Reservacion::~Reservacion() {

}
