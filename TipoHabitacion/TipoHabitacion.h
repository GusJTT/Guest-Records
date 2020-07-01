// --
// Created by Jerbo on 18/06/2020.
//

#ifndef PS_TIPOHABITACION_H
#define PS_TIPOHABITACION_H
#include "string"

using namespace std;

class TipoHabitacion {
    string nombre;
    string caracteristicas;
    double precioPorHora;
public:
    const string &getNombre() const;

    virtual ~TipoHabitacion();

    TipoHabitacion(const string &nombre, const string &caracteristicas, double precioPorHora);

    TipoHabitacion();

    void setNombre(const string &nombre);

    const string &getCaracteristicas() const;

    void setCaracteristicas(const string &caracteristicas);

    double getPrecioPorHora() const;

    void setPrecioPorHora(double precioPorHora);

};


#endif //PS_TIPOHABITACION_H
