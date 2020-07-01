// --
// Created by Jerbo on 18/06/2020.
//

#include "Administrador.h"

Administrador::Administrador(const string &contrasena, const string &correo, const string &direccion,
                             const Turno &turno) : contrasena(contrasena), correo(correo), direccion(direccion),
                                                   turno(turno) {}

Administrador::~Administrador() {

}

const string &Administrador::getContrasena() const {
    return contrasena;
}

void Administrador::setContrasena(const string &contrasena) {
    Administrador::contrasena = contrasena;
}

const string &Administrador::getCorreo() const {
    return correo;
}

void Administrador::setCorreo(const string &correo) {
    Administrador::correo = correo;
}

const string &Administrador::getDireccion() const {
    return direccion;
}

void Administrador::setDireccion(const string &direccion) {
    Administrador::direccion = direccion;
}

const Turno &Administrador::getTurno() const {
    return turno;
}

void Administrador::setTurno(const Turno &turno) {
    Administrador::turno = turno;
}

Administrador::Administrador() = default;
