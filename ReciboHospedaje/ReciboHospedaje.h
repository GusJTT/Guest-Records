// --
// Created by Jerbo on 18/06/2020.
//

#ifndef PS_RECIBOHOSPEDAJE_H
#define PS_RECIBOHOSPEDAJE_H

#include "string"
#include "../Cliente/Cliente.h"
#include "../Administrador/Administrador.h"
#include "../AdquirirServicio/AdquirirServicio.h"

using namespace std;

class ReciboHospedaje {
    Cliente *clientes;
    int idreservacion;
    Administrador administrador;
    AdquirirServicio *adquirirServicio;
public:
    virtual ~ReciboHospedaje();

    ReciboHospedaje();

    Cliente *getClientes() const;

    void setClientes(Cliente *clientes);

    const int &getReservacion() const;

    void setReservacion(const int &reservacion);

    const Administrador &getAdministrador() const;

    void setAdministrador(Administrador administrador);

    AdquirirServicio *getAdquirirServicio() const;

    void setAdquirirServicio(AdquirirServicio *adquirirServicio);

};


#endif //PS_RECIBOHOSPEDAJE_H
