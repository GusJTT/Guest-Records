//
// Created by Jerbo on 19/06/2020.
//

#include "AdquirirServicio.h"

const Servicio &AdquirirServicio::getServicio() const {
    return servicio;
}

void AdquirirServicio::setServicio(const Servicio &servicio) {
    AdquirirServicio::servicio = servicio;
}

time_t AdquirirServicio::getFecha() const {
    return fecha;
}

void AdquirirServicio::setFecha(time_t fecha) {
    AdquirirServicio::fecha = fecha;
}

AdquirirServicio::AdquirirServicio(const Servicio &servicio, time_t fecha) : servicio(servicio), fecha(fecha) {}

AdquirirServicio::AdquirirServicio() {}

AdquirirServicio::~AdquirirServicio() {

}
