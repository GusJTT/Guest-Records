//
// Created by Jerbo on 18/06/2020.
//

#include "Servicio.h"
#include <iostream>
#include "../Conexion/Conexion.h"
#include "../Habitacion/Habitacion.h"
#include <utility>
#include <mysql.h>
#include "string"

using namespace std;

Servicio::Servicio(string nombre, double precio) : nombre(std::move(nombre)), precio(precio) {

}

Servicio::~Servicio() {

}

const string &Servicio::getNombre() const {
    return nombre;
}

void Servicio::setNombre(const string &nombre) {
    Servicio::nombre = nombre;
}

double Servicio::getPrecio() const {
    return precio;
}

void Servicio::setPrecio(double precio) {
    Servicio::precio = precio;
}

Servicio::Servicio() {}

void Servicio::consultaServicios(){
    try {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* resultado;
        conn = mysql_init(nullptr);
        conn = mysql_real_connect(conn,"sql10.freemysqlhosting.net","sql10352889","ug7jc4mGXp","sql10352889", 3306,
                                  nullptr, 0);
        if (conn) {
            const char* sql = "SELECT servicio.id_servicio, servicio.nombre, servicio.precioxpersona "
                              "FROM servicio";
            int qstate = mysql_query(conn , sql);
            if(qstate == 0){
                resultado = mysql_store_result(conn);
                unsigned long filas = mysql_num_rows(resultado);
                if (filas == 0) {
                    cout << "No hay datos" << endl;
                }
                for (int i = 0; i < filas; i++){
                    row = mysql_fetch_row(resultado);
                    cout << "------------------------------------" << endl;
                    cout << "ID servicio: " << row[0] << endl;
                    cout << "Nombre servicio: " << row[1] <<endl;
                    cout << "Precio: " << row[2] << endl;
                    cout << "------------------------------------" << endl;
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

void Servicio::agregarServicio(string idServicio, string nombre, string precio){

    MYSQL* conn, mysql;

    int query_state;
    const char* server = "sql10.freemysqlhosting.net";
    const char* user = "sql10352889";
    const char* password = "ug7jc4mGXp";
    const char* database = "sql10352889";
    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);
    if (conn == NULL){
        cout << mysql_error(&mysql) << endl << endl;
    }
    string hotel = "1";
    string sql = "INSERT INTO `servicio`(`id_servicio`, `id_Hotel`, `nombre`, `precioxpersona`) VALUES ("+ idServicio +","+hotel+",'"+nombre+"',"+precio+")";
    query_state = mysql_query(conn, sql.c_str());
    if (query_state != 0){
        cout << mysql_error(conn) << endl << endl;
    } else {
        cout << "Agregado exitosamente" << endl;
    }
    mysql_close(conn);
}

void Servicio::buscarServicios(string id){
    try {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* resultado;
        conn = mysql_init(nullptr);
        conn = mysql_real_connect(conn,"sql10.freemysqlhosting.net","sql10352889","ug7jc4mGXp","sql10352889", 3306,
                                  nullptr, 0);
        if (conn) {
            string sql = "SELECT servicio.id_servicio, servicio.nombre, servicio.precioxpersona "
                         "FROM servicio WHERE id_servicio = " + id;
            int qstate = mysql_query(conn , sql.c_str());
            if(qstate == 0){
                resultado = mysql_store_result(conn);
                unsigned long filas = mysql_num_rows(resultado);
                if (filas == 0) {
                    cout << "No hay datos" << endl;
                }
                for (int i = 0; i < filas; i++){
                    row = mysql_fetch_row(resultado);
                    cout << "------------------------------------" << endl;
                    cout << "ID servicio: " << row[0] << endl;
                    cout << "Nombre servicio: " << row[1] <<endl;
                    cout << "Precio: " << row[2] << endl;
                    cout << "------------------------------------" << endl;
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
void Servicio::modificarServicio(string idServicio, string nombre, string precio){
    MYSQL* conn, mysql;

    int query_state;
    const char* server = "sql10.freemysqlhosting.net";
    const char* user = "sql10352889";
    const char* password = "ug7jc4mGXp";
    const char* database = "sql10352889";
    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);
    if (conn == NULL){
        cout << mysql_error(&mysql) << endl << endl;
    }
    string est = "1";
    string sql = "UPDATE `servicio` SET `nombre`= '"+nombre+"',`precioxpersona`= "+precio+" WHERE `id_servicio`= "+ idServicio;
    query_state = mysql_query(conn, sql.c_str());
    if (query_state != 0){
        cout << mysql_error(conn) << endl << endl;
    } else {
        cout << "Agregado exitosamente" << endl;
    }
    mysql_close(conn);
}
void Servicio::eliminarServicio(string idServicio){
    MYSQL* conn, mysql;

    int query_state;
    const char* server = "sql10.freemysqlhosting.net";
    const char* user = "sql10352889";
    const char* password = "ug7jc4mGXp";
    const char* database = "sql10352889";
    mysql_init(&mysql);
    conn = mysql_real_connect(&mysql, server, user, password, database, 0, 0, 0);
    if (conn == NULL){
        cout << mysql_error(&mysql) << endl << endl;
    }
    string sql = "DELETE FROM `servicio` WHERE `id_servicio`="+idServicio;
    query_state = mysql_query(conn, sql.c_str());
    if (query_state != 0){
        cout << mysql_error(conn) << endl << endl;
    } else {
        cout << "Eliminado exitosamente" << endl;
    }
    mysql_close(conn);
}

void Servicio::menuServicio() {
    setlocale(LC_ALL,"Spanish");
    int cant = 0, op = 0;
    string aux,aux1,aux2;
    while(op != 4) {
        cout << "--Administracion de servicios--" << endl;
        cout << "  Seleccione una opcion:" << endl;
        cout << "  (1)Añadir servicio" << endl;
        cout << "  (2)Ver servicio" << endl;
        cout << "  (3)Buscar servicios" << endl;
        cout << "  (4)Volver" << endl;
        cin >> op;
        switch(op) {
            case 1:
                system("cls");
                cout << "-Añadir servicio" << endl;
                cout << "  Ingrese ID del servicio: ";
                cin >> aux;
                cout << "  Ingrese el nombre del servicio: ";
                cin >> aux1;
                cout << "  Ingrese el precio: ";
                cin >> aux2;
                agregarServicio(aux,aux1,aux2);
                break;
            case 2:
                system("cls");
                //verReservaciones(reservaciones, cant);
                consultaServicios();
                break;
            case 3:
                system("cls");
                cout << "-Buscar servicio-" << endl;
                cout << "  Ingrese ID del servicio: ";
                cin >> aux;
                //buscarReservacion(reservaciones, cant);
                buscarServicios(aux);
                cout << " ¿Que desea hacer?, seleccione una opcion:" << endl;
                cout << " (1)Modificar servicio" << endl;
                cout << " (2)Eliminar servicio" << endl;
                cout << " (3)Volver" << endl;
                cin >> op;
                if(op == 1){
                    cout << "  Ingrese los nuevos datos" << endl;
                    cout << "   Ingrese el nombre del servicio: ";
                    cin >> aux1;
                    cout << "   Ingrese el precio: ";
                    cin >> aux2;
                    modificarServicio(aux,aux1,aux2);
                }else if(op == 2){
                    eliminarServicio(aux);
                }else if(op == 3){
                    break;
                }else{
                    cout << "Opcion incorrecta" << endl;
                }
                break;
            case 4:
                break;
            default:
                cout << "Opcion incorrecta: Ingrese una valida o 4 para volver" << endl;
                break;
        }
    }
}