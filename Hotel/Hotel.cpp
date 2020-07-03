//
// Created by Jerbo on 18/06/2020.
//

#include "Hotel.h"


Hotel::~Hotel() {

}

const Servicio *Hotel::getServicios() const {
    return servicios;
}

const Habitacion *Hotel::getHabitaciones() const {
    return habitaciones;
}

const Cliente *Hotel::getClientes() const {
    return clientes;
}

const Administrador *Hotel::getAdministradores() const {
    return administradores;
}

const Turno *Hotel::getTurnos() const {
    return turnos;
}

const TipoHabitacion *Hotel::getTipoHabitaciones() const {
    return tipoHabitaciones;
}

void Hotel::setServicios(Servicio *servicios) {
    Hotel::servicios = servicios;
}

void Hotel::setHabitaciones(Habitacion *habitaciones) {
    Hotel::habitaciones = habitaciones;
}

void Hotel::setClientes(Cliente *clientes) {
    Hotel::clientes = clientes;
}

void Hotel::setAdministradores(Administrador *administradores) {
    Hotel::administradores = administradores;
}

void Hotel::setTurnos(Turno *turnos) {
    Hotel::turnos = turnos;
}

void Hotel::setTipoHabitaciones(TipoHabitacion *tipoHabitaciones) {
    Hotel::tipoHabitaciones = tipoHabitaciones;
}
