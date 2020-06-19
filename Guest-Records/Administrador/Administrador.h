//
// Created by Jerbo on 18/06/2020.
//

#ifndef PS_ADMINISTRADOR_H
#define PS_ADMINISTRADOR_H
#include "string"
#include "../Turno/Turno.h"

using namespace std;

class Administrador {
    string contrasena;
    string correo;
    string direccion;
    Turno turno;
public:
    Administrador(const string &contrasena, const string &correo, const string &direccion, const Turno &turno);

    virtual ~Administrador();

    const string &getContrasena() const;

    void setContrasena(const string &contrasena);

    const string &getCorreo() const;

    void setCorreo(const string &correo);

    const string &getDireccion() const;

    void setDireccion(const string &direccion);

    const Turno &getTurno() const;

    void setTurno(const Turno &turno);

    Administrador();
};


#endif //PS_ADMINISTRADOR_H
