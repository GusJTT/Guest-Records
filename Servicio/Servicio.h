//
// Created by Jerbo on 18/06/2020.
//

#ifndef PS_SERVICIO_H
#define PS_SERVICIO_H

#include "string"

using namespace std;

class Servicio {
    string nombre;
    double precio;
public:
    Servicio(string nombre, double precio);

    virtual ~Servicio();

    const string &getNombre() const;

    void setNombre(const string &nombre);

    double getPrecio() const;

    void setPrecio(double precio);

    Servicio();

};


#endif //PS_SERVICIO_H
