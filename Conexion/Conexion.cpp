#include "Conexion.h"
#include <string>
#define convertToString(x) #x
using namespace std;

MYSQL mysql,*connection;
MYSQL_RES *result;
MYSQL_ROW row;
int query_state;

Conexion::Conexion() {
    iniciarConexion();
}
void Conexion::iniciarConexion() {
    mysql_init(&mysql);
    connection = mysql_real_connect(&mysql, ip, usr, pass, db, 3306, NULL, 0);
    if (connection==NULL){
        cout<<mysql_error(&mysql)<<endl;
    }
}

void Conexion::finalizarConexion() {
    mysql_close(&mysql);
}

Hotel Conexion::getDatosHotel(int id) {
    Hotel aux;
    string query ="SELECT * FROM hotel WHERE id_hotel="+to_string(id);
    query_state=mysql_query(connection, query.c_str());
    if(!query_state){
        result = mysql_store_result(connection);
        row = mysql_fetch_row(result);
        aux.id_hotel=atoi(row[0]);
        aux.nombre=row[1];
        aux.direccion=row[2];
        aux.telefono=row[3];
    }
    return aux;
}

bool Conexion::inicioSesion(Administrador &admin, string username, string contra) {
    string query ="SELECT * FROM administrador WHERE username='"+username+"' AND contra='"+contra+"'";
    query_state=mysql_query(connection, query.c_str());
    if(!query_state){
        result = mysql_store_result(connection);
        if(result->row_count==0)
            return false;
        else{
            row = mysql_fetch_row(result);
            admin.id_administrador=atoi(row[0]);
            admin.id_hotel=atoi(row[1]);
            admin.nombre=row[2];
            admin.apellidos=row[3];
            admin.username=row[4];
            admin.contra=row[5];
            admin.telefono=row[6];
        return true;
        }
    }
    return false;
}

void Conexion::consultaReservaciones(){
    try {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* resultado;
        conn = mysql_init(nullptr);
        conn = mysql_real_connect(conn,  ip, usr, pass, db, 3306,
                                  nullptr, 0);
        if (conn) {
            const char* sql = "SELECT reservacion.id_reservacion, reservacion.id_habitacion, cliente.nombre, cliente.apellidos, reservacion.fecha, reservacion.estado "
                              "FROM reservacion INNER JOIN cliente ON reservacion.id_cliente = cliente.id_cliente";
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
                    cout << "ID reservacion: " << row[0] << endl;
                    cout << "Numero habitacion: " << row[1] <<endl;
                    cout << "Cliente: " << row[2] << " " << row[3] << endl;
                    cout << "Fecha: " << row[4] << endl;
                    cout << "Estado registro: " << row[5] << endl;
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

void Conexion::agregarReservacion(string idReservacion, string idHabitacion, string idCliente, string fecha){

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
    string sql = "INSERT INTO `reservacion`(`id_reservacion`, `id_habitacion`, `id_cliente`, `fecha`, `estado`) VALUES ("+ idReservacion +","+idHabitacion+","+idCliente+",'"+fecha+"',"+est+")";
    query_state = mysql_query(conn, sql.c_str());
    if (query_state != 0){
        cout << mysql_error(conn) << endl << endl;
    } else {
        cout << "Agregado exitosamente" << endl;
    }
    mysql_close(conn);
}

void Conexion::buscarReservacion(string id){
    try {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* resultado;
        conn = mysql_init(nullptr);
        conn = mysql_real_connect(conn,  ip, usr, pass, db, 3306,
                                  nullptr, 0);
        if (conn) {
            string sql = "SELECT reservacion.id_reservacion, reservacion.id_habitacion, cliente.nombre, cliente.apellidos, reservacion.fecha, reservacion.estado "
                         "FROM reservacion INNER JOIN cliente ON reservacion.id_cliente = cliente.id_cliente WHERE id_reservacion = " + id;
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
                    cout << "ID reservacion: " << row[0] << endl;
                    cout << "Numero habitacion: " << row[1] <<endl;
                    cout << "Cliente: " << row[2] << " " << row[3] << endl;
                    cout << "Fecha: " << row[4] << endl;
                    cout << "Estado registro: " << row[5] << endl;
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
void Conexion::modificarReservacion(string idReservacion, string idHabitacion, string idCliente, string fecha){
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
    string sql = "UPDATE `reservacion` SET `id_habitacion`="+idHabitacion+",`id_cliente`="+idCliente+",`fecha`='"+fecha+"',`estado`="+est+" WHERE `id_reservacion`="+ idReservacion;
    query_state = mysql_query(conn, sql.c_str());
    if (query_state != 0){
        cout << mysql_error(conn) << endl << endl;
    } else {
        cout << "Agregado exitosamente" << endl;
    }
    mysql_close(conn);
}
void Conexion::eliminarReservacion(string idReservacion){
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
    string sql = "DELETE FROM `reservacion` WHERE `id_reservacion`="+ idReservacion;
    query_state = mysql_query(conn, sql.c_str());
    if (query_state != 0){
        cout << mysql_error(conn) << endl << endl;
    } else {
        cout << "Eliminado exitosamente" << endl;
    }
    mysql_close(conn);
}