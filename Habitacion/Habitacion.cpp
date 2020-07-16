//
// Created by Jerbo on 18/06/2020.
//

#include "Habitacion.h"
#include <mysql.h>
#include <iostream>
#include "../Conexion/Conexion.h"

Habitacion::Habitacion() {}

Habitacion::Habitacion(int numHabitacion, int numPiso, const TipoHabitacion &tipoHabitacion) : numHabitacion(numHabitacion), numPiso(numPiso),
                                                            tipoHabitacion(tipoHabitacion) {}

Habitacion::~Habitacion() {

}

int Habitacion::getNumHabitacion() const {
    return numHabitacion;
}

void Habitacion::setNumHabitacion(int numHabitacion) {
    Habitacion::numHabitacion = numHabitacion;
}

int Habitacion::getNumPiso() const {
    return numPiso;
}

void Habitacion::setNumPiso(int numPiso) {
    Habitacion::numPiso = numPiso;
}

void Habitacion::consultaHabitaciones(){
    try {
        Conexion c;
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* resultado;
        conn = mysql_init(nullptr);
        conn = mysql_real_connect(conn,"sql10.freemysqlhosting.net","sql10352889","ug7jc4mGXp","sql10352889", 3306,
                                  nullptr, 0);
        if (conn) {
            string sql = "SELECT habitacion.`id_habitacion`, habitacion.`piso`, tipohabitacion.`nombre`, tipohabitacion.`precioxhora` FROM habitacion INNER JOIN tipohabitacion ON habitacion.id_tipohabitacion = tipohabitacion.id_tipohabitacion";
            int qstate = mysql_query(conn , sql.c_str());
            if(qstate == 0){
                resultado = mysql_store_result(conn);
                unsigned long filas = mysql_num_rows(resultado);
                if (filas == 0) {
                    cout << "No hay datos" << endl;
                }
                for (int i = 0; i < filas; i++){
                    row = mysql_fetch_row(resultado);
                    cout << "   nº habitacion: " << row[0] << "  piso: " << row[1] << "  tipo: " << row[2] << "  precio: " << row[3] << endl;
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

const TipoHabitacion &Habitacion::getTipoHabitacion() const {
    return tipoHabitacion;
}

void Habitacion::setTipoHabitacion(const TipoHabitacion &tipoHabitacion) {
    Habitacion::tipoHabitacion = tipoHabitacion;
}


ReciboHospedaje *const *Habitacion::getReciboHospedaje() const {
    return reciboHospedaje;
}
