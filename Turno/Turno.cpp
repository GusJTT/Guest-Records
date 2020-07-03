//
// Created by Jerbo on 18/06/2020.
//

#include "Turno.h"

Turno::~Turno() {

}

time_t Turno::getFechaInicio() const {
    return fechaInicio;
}

void Turno::setFechaInicio(time_t fechaInicio) {
    Turno::fechaInicio = fechaInicio;
}

time_t Turno::getFechaFin() const {
    return fechaFin;
}

void Turno::setFechaFin(time_t fechaFin) {
    Turno::fechaFin = fechaFin;
}

Turno::Turno(time_t fechaInicio, time_t fechaFin) : fechaInicio(fechaInicio), fechaFin(fechaFin) {}

Turno::Turno() {}
