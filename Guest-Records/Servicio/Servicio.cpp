//
// Created by Jerbo on 18/06/2020.
//

#include "Servicio.h"

#include <utility>

#include "string"

using namespace std;

Servicio::Servicio(string nombre, double precio) : nombre(std::move(nombre)), precio(precio) {

}

Servicio::~Servicio() {

}

const string &Servicio::getNombre() const {
    return nombre;
}

void Servicio::setNombre(const string &nombre) {
    Servicio::nombre = nombre;
}

double Servicio::getPrecio() const {
    return precio;
}

void Servicio::setPrecio(double precio) {
    Servicio::precio = precio;
}

Servicio::Servicio() {}
