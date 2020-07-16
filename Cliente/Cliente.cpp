//
// Created by Jerbo on 18/06/2020.
//

#include "Cliente.h"
#include <mysql.h>
#include <iostream>
#include "../Conexion/Conexion.h"

Cliente::~Cliente() {

}

Cliente::Cliente() {}

Cliente::Cliente(int identificacion, int telefono, const string &nombre, const string &apellidos,
                 const string &direccion) : identificacion(identificacion), telefono(telefono), nombre(nombre),
                                            apellidos(apellidos), direccion(direccion) {}

int Cliente::getIdentificacion() const {
    return identificacion;
}

void Cliente::setIdentificacion(int identificacion) {
    Cliente::identificacion = identificacion;
}

int Cliente::getTelefono() const {
    return telefono;
}

void Cliente::setTelefono(int telefono) {
    Cliente::telefono = telefono;
}

const string &Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const string &nombre) {
    Cliente::nombre = nombre;
}

void Cliente::consultaNombres() {
    try {
        Conexion c;
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* resultado;
        conn = mysql_init(nullptr);
        conn = mysql_real_connect(conn,"sql10.freemysqlhosting.net","sql10352889","ug7jc4mGXp","sql10352889", 3306,
                                  nullptr, 0);
        if (conn) {
            string sql = "SELECT id_cliente, nombre, apellidos FROM `cliente`";
            int qstate = mysql_query(conn , sql.c_str());
            if(qstate == 0){
                resultado = mysql_store_result(conn);
                unsigned long filas = mysql_num_rows(resultado);
                cout << (unsigned long)filas << endl;
                if (filas == 0) {
                    cout << "No hay datos" << endl;
                }
                for (int i = 0; i < filas; i++){
                    row = mysql_fetch_row(resultado);
                    cout << "   " << row[0] << "->" << row[1] << " " << row[2] << endl;
                }
                mysql_free_result(resultado);
            }
            mysql_close(conn);
        }
        else {
            cout << "Error: no se pudo conectar" << endl;
        }
    }
    catch (exception& e) {
        cout << e.what();
    }
}

const string &Cliente::getApellidos() const {
    return apellidos;
}

void Cliente::setApellidos(const string &apellidos) {
    Cliente::apellidos = apellidos;
}

const string &Cliente::getDireccion() const {
    return direccion;
}

void Cliente::setDireccion(const string &direccion) {
    Cliente::direccion = direccion;
}
