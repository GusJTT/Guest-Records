//
// Created by Jerbo on 18/06/2020.
//

#include "Cliente.h"

Cliente::~Cliente() {

}

Cliente::Cliente() {}

Cliente::Cliente(int identificacion, int telefono, const string &nombre, const string &apellidos,
                 const string &direccion) : identificacion(identificacion), telefono(telefono), nombre(nombre),
                                            apellidos(apellidos), direccion(direccion) {}

int Cliente::getIdentificacion() const {
    return identificacion;
}

void Cliente::setIdentificacion(int identificacion) {
    Cliente::identificacion = identificacion;
}

int Cliente::getTelefono() const {
    return telefono;
}

void Cliente::setTelefono(int telefono) {
    Cliente::telefono = telefono;
}

const string &Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const string &nombre) {
    Cliente::nombre = nombre;
}

const string &Cliente::getApellidos() const {
    return apellidos;
}

void Cliente::setApellidos(const string &apellidos) {
    Cliente::apellidos = apellidos;
}

const string &Cliente::getDireccion() const {
    return direccion;
}

void Cliente::setDireccion(const string &direccion) {
    Cliente::direccion = direccion;
}
