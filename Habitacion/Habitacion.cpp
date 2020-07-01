// --
// Created by Jerbo on 18/06/2020.
//

#include "Habitacion.h"

Habitacion::Habitacion() {}

Habitacion::Habitacion(int numHabitacion, int numPiso, const TipoHabitacion &tipoHabitacion) : numHabitacion(numHabitacion), numPiso(numPiso),
                                                            tipoHabitacion(tipoHabitacion) {}

Habitacion::~Habitacion() {

}

int Habitacion::getNumHabitacion() const {
    return numHabitacion;
}

void Habitacion::setNumHabitacion(int numHabitacion) {
    Habitacion::numHabitacion = numHabitacion;
}

int Habitacion::getNumPiso() const {
    return numPiso;
}

void Habitacion::setNumPiso(int numPiso) {
    Habitacion::numPiso = numPiso;
}

const TipoHabitacion &Habitacion::getTipoHabitacion() const {
    return tipoHabitacion;
}

void Habitacion::setTipoHabitacion(const TipoHabitacion &tipoHabitacion) {
    Habitacion::tipoHabitacion = tipoHabitacion;
}


ReciboHospedaje *const *Habitacion::getReciboHospedaje() const {
    return reciboHospedaje;
}
