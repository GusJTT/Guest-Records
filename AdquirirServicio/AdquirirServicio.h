//
// Created by Jerbo on 19/06/2020.
//

#ifndef PS_ADQUIRIRSERVICIO_H
#define PS_ADQUIRIRSERVICIO_H


#include "../Servicio/Servicio.h"

class AdquirirServicio {
    Servicio servicio;
    time_t fecha;
public:
    const Servicio &getServicio() const;

    AdquirirServicio(const Servicio &servicio, time_t fecha);

    virtual ~AdquirirServicio();

    AdquirirServicio();

    void setServicio(const Servicio &servicio);

    time_t getFecha() const;

    void setFecha(time_t fecha);

};


#endif //PS_ADQUIRIRSERVICIO_H
