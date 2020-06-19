//
// Created by Jerbo on 18/06/2020.
//

#ifndef PS_USUARIO_H
#define PS_USUARIO_H

#include "string"

using namespace std;

class Usuario {
    string nombre;
    string contrasenia;
    string direccion;
    string apellido;
    int telefono;
public:
    const string &getNombre() const;

    Usuario(const string &nombre, const string &contrasenia, const string &direccion, const string &apellido,
            int telefono);

    Usuario();

    void setNombre(const string &nombre);

    virtual ~Usuario();

    const string &getContrasenia() const;

    void setContrasenia(const string &contrasenia);

    const string &getDireccion() const;

    void setDireccion(const string &direccion);

    const string &getApellido() const;

    void setApellido(const string &apellido);

    int getTelefono() const;

    void setTelefono(int telefono);
};


#endif //PS_USUARIO_H
