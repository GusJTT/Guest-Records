//
// Created by Jerbo on 18/06/2020.
//

#ifndef PS_HOTEL_H
#define PS_HOTEL_H
#include "string"
using namespace std;


#include "../Servicio/Servicio.h"
#include "../Habitacion/Habitacion.h"
#include "../Cliente/Cliente.h"
#include "../Administrador/Administrador.h"

class Hotel {
    Servicio *servicios;
    Habitacion *habitaciones;
    Cliente *clientes;
    Administrador *administradores;
    Turno *turnos;
    TipoHabitacion *tipoHabitaciones;
public:

    const Servicio *getServicios() const;

    const Habitacion *getHabitaciones() const;

    const Cliente *getClientes() const;

    const Administrador *getAdministradores() const;

    const Turno *getTurnos() const;

    const TipoHabitacion *getTipoHabitaciones() const;

    virtual ~Hotel();


};


#endif //PS_HOTEL_H
