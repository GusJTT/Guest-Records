//
// Created by Jerbo on 18/06/2020.
//

#include "ReciboHospedaje.h"

ReciboHospedaje::ReciboHospedaje() {}

ReciboHospedaje::~ReciboHospedaje() {

}

Cliente *ReciboHospedaje::getClientes() const {
    return clientes;
}

void ReciboHospedaje::setClientes(Cliente *clientes) {
    ReciboHospedaje::clientes = clientes;
}

const int &ReciboHospedaje::getReservacion() const {
    return idreservacion;
}

void ReciboHospedaje::setReservacion(const int &reservacion) {
    ReciboHospedaje::idreservacion = reservacion;
}

const Administrador &ReciboHospedaje::getAdministrador() const {
    return administrador;
}

void ReciboHospedaje::setAdministrador(Administrador administrador) {
    ReciboHospedaje::administrador =  administrador;
}

AdquirirServicio *ReciboHospedaje::getAdquirirServicio() const {
    return adquirirServicio;
}

void ReciboHospedaje::setAdquirirServicio(AdquirirServicio *adquirirServicio) {
    ReciboHospedaje::adquirirServicio = adquirirServicio;
}
