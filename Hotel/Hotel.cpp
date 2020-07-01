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
