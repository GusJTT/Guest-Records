//
// Created by Jerbo on 18/06/2020.
//

#include "TipoHabitacion.h"

const string &TipoHabitacion::getNombre() const {
    return nombre;
}

void TipoHabitacion::setNombre(const string &nombre) {
    TipoHabitacion::nombre = nombre;
}

const string &TipoHabitacion::getCaracteristicas() const {
    return caracteristicas;
}

void TipoHabitacion::setCaracteristicas(const string &caracteristicas) {
    TipoHabitacion::caracteristicas = caracteristicas;
}

double TipoHabitacion::getPrecioPorHora() const {
    return precioPorHora;
}

void TipoHabitacion::setPrecioPorHora(double precioPorHora) {
    TipoHabitacion::precioPorHora = precioPorHora;
}

TipoHabitacion::TipoHabitacion() {}

TipoHabitacion::TipoHabitacion(const string &nombre, const string &caracteristicas, double precioPorHora) : nombre(
        nombre), caracteristicas(caracteristicas), precioPorHora(precioPorHora) {}

TipoHabitacion::~TipoHabitacion() {

}
