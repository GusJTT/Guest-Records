//
// Created by G-t-T on 1/07/2020.
//
#include <iostream>
#include <mysql.h>
#include "Reservacion/Reservacion.h"
#include "TipoHabitacion/TipoHabitacion.h"
#include "Habitacion/Habitacion.h"

static void agregarReservacion(Reservacion r[50], int& cant){
    /*
    Habitacion habitacion;
    int codigo;
    int cantidadPersonas;
    time_t fechaIngreso;
    time_t fechaSalida;
     */
    TipoHabitacion tp("individual", "una persona", 50);
    int ax1;
    time_t ax2;
    cout << "->Agregar Reservaciones" << endl;
    cout << "  Ingrese el codigo de reservacion: ";
    cin >> ax1;
    r[cant].setCodigo(ax1);
    cout << "  Ingrese el numero de habitacion: ";
    cin >> ax1;
    Habitacion hab(ax1,1,tp);
    r[cant].setHabitacion(hab);
    cout << "  Ingrese la cantidad de personas: ";
    cin >> ax1;
    r[cant].setCantidadPersonas(ax1);
    cout << "  Ingrese la fecha de ingreso: ";
    cin >> ax2;
    r[cant].setFechaIngreso(ax2);
    cout << "  Ingrese la fecha de salida: ";
    cin >> ax2;
    r[cant].setFechaSalida(ax2);
    cout << r[cant].getCodigo() << endl;
    cout << r[cant].getCantidadPErsonas() << endl;
    cout << r[cant].getFechaIngreso() << endl;
    cout << r[cant].getFechaSalida() << endl;
    cant++;
}
static void verReservaciones(Reservacion r[50], int cant){
    for (int i = 0; i < cant; i++){
        cout << "-------------------------" << endl;
        cout << "Codigo: " << r[i].getCodigo() << endl;
        cout << "Nº habitacion: " << r[i].getHabitacion().getNumHabitacion() << endl;
        cout << "Cantidad de personas: " << r[i].getCantidadPErsonas() << endl;
        cout << "Fecha de ingreso: " << r[i].getFechaIngreso() << endl;
        cout << "Fecha de salida: " << r[i].getFechaSalida() << endl;
        cout << "-------------------------" << endl;
    }
}
static void buscarReservacion(Reservacion r[50], int cant){
    int aux;
    bool enc = false;
    cout << "->Buscar Reservaciones" << endl;
    cout << "  Ingrese el codigo a buscar: ";
    cin >> aux;
    for (int i = 0; i < cant; i++){
        if(r[i].getCodigo() == aux){
            enc = true;
            cout << "-------------------------" << endl;
            cout << "Codigo: " << r[i].getCodigo() << endl;
            cout << "Nº habitacion: " << r[i].getHabitacion().getNumHabitacion() << endl;
            cout << "Cantidad de personas: " << r[i].getCantidadPErsonas() << endl;
            cout << "Fecha de ingreso: " << r[i].getFechaIngreso() << endl;
            cout << "Fecha de salida: " << r[i].getFechaSalida() << endl;
            cout << "-------------------------" << endl;
            break;
        }
    }
    if(enc == false){
        cout << "No encontrado" << endl;
    }
}
static void agregarBD(int idReservacion, int idHabitacion, int idCliente, int estado){
    try{
        cout << "aqui" << endl;
        #define STRING_SIZE 50
        MYSQL_TIME  ts;
        int int_data;
        unsigned long str_length;
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_BIND bind[5];
        MYSQL_RES* resultado;
        conn = mysql_init(nullptr);
        conn = mysql_real_connect(conn, "sql10.freemysqlhosting.net", "sql10351188", "FCWP53Cz47", "sql10351188", 3306,
                                  nullptr, 0);
        if (conn) {
            MYSQL_STMT* stmt;
            const char* sql = "INSERT INTO `reservacion`(`id_reservacion`, `id_habitacion`, `id_cliente`, `fecha`, `estado`) VALUES (?,?,?,?,?)";
            int qstate = mysql_query(conn , sql);
            cout << qstate << endl;
            if(qstate != 0){
                cout << "Aqui";
                stmt = mysql_stmt_init(conn);
                mysql_stmt_prepare(stmt,sql,strlen(sql));
                memset(bind, 0, sizeof(bind));
                bind[0].buffer_type= MYSQL_TYPE_INT24;
                bind[0].buffer= (char *)&int_data;
                bind[0].is_null= 0;
                bind[0].length= 0;

                bind[1] = bind[2] = bind[4] = bind[0];

                bind[3].buffer_type= MYSQL_TYPE_DATE;
                bind[3].buffer= (char *)&ts;
                bind[3].is_null= 0;
                bind[3].length= 0;
                mysql_stmt_bind_param(stmt, bind);
                int_data=10;
                ts.year = 2020;
                ts.month = 07;
                ts.day = 03;
                ts.hour = 10;
                ts.minute = 45;
                ts.second = 20;
                mysql_stmt_execute(stmt);
                unsigned long afectadas = mysql_stmt_affected_rows(stmt);
                cout << afectadas << endl;
                /*resultado = mysql_store_result(conn);
                unsigned long filas = mysql_num_rows(resultado);
                for (int i = 0; i < filas; i++){
                    row = mysql_fetch_row(resultado);
                    cout << row[0] << " " << row[1] <<" "<< row[2] <<" "<< row[3] << endl;
                }
                mysql_free_result(resultado);*/
                mysql_stmt_close(stmt);
            }
            mysql_close(conn);
        } else {
            cout << "Error: no se pudo conectar" << endl;
        }
    } catch (exception &e) {
        cout << e.what();
    }
}
static void consultaBD(){
    try{
        cout << "aqui" << endl;
#define STRING_SIZE 50
        MYSQL_TIME  ts;
        int int_data;
        unsigned long str_length;
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_BIND bind[5];
        MYSQL_RES* resultado;
        conn = mysql_init(nullptr);
        conn = mysql_real_connect(conn, "sql10.freemysqlhosting.net", "sql10351188", "FCWP53Cz47", "sql10351188", 3306,
                                  nullptr, 0);
        if (conn) {
            MYSQL_STMT* stmt;
            const char* sql = "INSERT INTO `reservacion`(`id_reservacion`, `id_habitacion`, `id_cliente`, `fecha`, `estado`) VALUES ([value-1],[value-2],[value-3],[value-4],[value-5])";
            int qstate = mysql_query(conn , sql);
            cout << qstate << endl;
            if(qstate != 0){
                cout << "Aqui";
                stmt = mysql_stmt_init(conn);
                resultado = mysql_store_result(conn);
                unsigned long filas = mysql_num_rows(resultado);
                for (int i = 0; i < filas; i++){
                    row = mysql_fetch_row(resultado);
                    cout << row[0] << " " << row[1] <<" "<< row[2] <<" "<< row[3] << endl;
                }
                mysql_free_result(resultado);
            }
            mysql_close(conn);
        } else {
            cout << "Error: no se pudo conectar" << endl;
        }
    } catch (exception &e) {
        cout << e.what();
    }
}