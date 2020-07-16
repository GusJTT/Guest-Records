//
// Created by Jerbo on 18/06/2020.
//

#ifndef PS_CLIENTE_H
#define PS_CLIENTE_H
#include "string"

using namespace std;

class Cliente {
    int identificacion;
    int telefono;
    string nombre;
    string apellidos;
    string direccion;
public:
    virtual ~Cliente();

    int getIdentificacion() const;

    void setIdentificacion(int identificacion);

    int getTelefono() const;

    void setTelefono(int telefono);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getApellidos() const;

    void setApellidos(const string &apellidos);

    const string &getDireccion() const;

    void setDireccion(const string &direccion);

    void consultaNombres();

    Cliente(int identificacion, int telefono, const string &nombre, const string &apellidos, const string &direccion);

    Cliente();

};


#endif //PS_CLIENTE_H
