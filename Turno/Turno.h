//
// Created by Jerbo on 18/06/2020.
//

#ifndef PS_TURNO_H
#define PS_TURNO_H
#include "ctime"


class Turno {
    time_t fechaInicio;
    time_t fechaFin;
public:
    virtual ~Turno();

    Turno();

    Turno(time_t fechaInicio, time_t fechaFin);

    time_t getFechaInicio() const;

    void setFechaInicio(time_t fechaInicio);

    time_t getFechaFin() const;

    void setFechaFin(time_t fechaFin);
};


#endif //PS_TURNO_H
