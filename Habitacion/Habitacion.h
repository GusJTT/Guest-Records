//
// Created by Jerbo on 18/06/2020.
//

#ifndef PS_HABITACION_H
#define PS_HABITACION_H
#include "string"
#include "../TipoHabitacion/TipoHabitacion.h"
#include "../ReciboHospedaje/ReciboHospedaje.h"

using namespace std;

class Habitacion {
    int numHabitacion;
    int numPiso;
    TipoHabitacion tipoHabitacion;
    ReciboHospedaje *reciboHospedaje[100];
public:
    int getNumHabitacion() const;

    void setNumHabitacion(int numHabitacion);

    int getNumPiso() const;

    void setNumPiso(int numPiso);

    const TipoHabitacion &getTipoHabitacion() const;

    void setTipoHabitacion(const TipoHabitacion &tipoHabitacion);

    void consultaHabitaciones();

    ReciboHospedaje *const *getReciboHospedaje() const;

    virtual ~Habitacion();

    Habitacion(int numHabitacion, int numPiso, const TipoHabitacion &tipoHabitacion);

    Habitacion();


};


#endif //PS_HABITACION_H
