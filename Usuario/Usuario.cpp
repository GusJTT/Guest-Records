// --
// Created by Jerbo on 18/06/2020.
//

#include "Usuario.h"

const string &Usuario::getNombre() const {
    return nombre;
}

void Usuario::setNombre(const string &nombre) {
    Usuario::nombre = nombre;
}

const string &Usuario::getContrasenia() const {
    return contrasenia;
}

void Usuario::setContrasenia(const string &contrasenia) {
    Usuario::contrasenia = contrasenia;
}

const string &Usuario::getDireccion() const {
    return direccion;
}

void Usuario::setDireccion(const string &direccion) {
    Usuario::direccion = direccion;
}

const string &Usuario::getApellido() const {
    return apellido;
}

void Usuario::setApellido(const string &apellido) {
    Usuario::apellido = apellido;
}

int Usuario::getTelefono() const {
    return telefono;
}

void Usuario::setTelefono(int telefono) {
    Usuario::telefono = telefono;
}

Usuario::Usuario(const string &nombre, const string &contrasenia, const string &direccion, const string &apellido,
                 int telefono) : nombre(nombre), contrasenia(contrasenia), direccion(direccion), apellido(apellido),
                                 telefono(telefono) {}

Usuario::Usuario() {}

Usuario::~Usuario() {

}
