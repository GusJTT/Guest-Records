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

void Conexion::consultaBD(){
    try {
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* resultado;
        conn = mysql_init(nullptr);
        conn = mysql_real_connect(conn, "sql10.freemysqlhosting.net", "sql10352889", "ug7jc4mGXp", "sql10352889", 3306,
                                  nullptr, 0);
        if (conn) {
            const char* sql = "SELECT * FROM `reservacion`";
            int qstate = mysql_query(conn , sql);
            cout << qstate << endl;
            if(qstate == 0){
                resultado = mysql_store_result(conn);
                unsigned long filas = mysql_num_rows(resultado);
                cout << (unsigned long)filas << endl;
                if (filas == 0) {
                    cout << "No hay datos" << endl;
                }
                for (int i = 0; i < filas; i++){
                    row = mysql_fetch_row(resultado);
                    cout << row[0] << " " << row[1] <<" "<< row[2] <<" "<< row[3] << endl;
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

