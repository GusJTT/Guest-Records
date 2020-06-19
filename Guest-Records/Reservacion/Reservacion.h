//
// Created by Jerbo on 18/06/2020.
//

#ifndef PS_RESERVACION_H
#define PS_RESERVACION_H
#include "string"
using namespace std;

#include "../Habitacion/Habitacion.h"



class Reservacion {
    Habitacion habitacion;
    int codigo;
    int cantidadPErsonas;
    time_t fechaIngreso;
    time_t fechaSalida;
public:
    virtual ~Reservacion();

    Reservacion();

    int getCodigo() const;

    void setCodigo(int codigo);

    int getCantidadPErsonas() const;

    void setCantidadPErsonas(int cantidadPErsonas);

    time_t getFechaIngreso() const;

    void setFechaIngreso(time_t fechaIngreso);

    time_t getFechaSalida() const;

    void setFechaSalida(time_t fechaSalida);

    const Habitacion &getHabitacion() const;

    void setHabitacion(const Habitacion &habitacion);


};


#endif //PS_RESERVACION_H
