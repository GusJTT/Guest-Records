/*#include <mysql.h>
#include <iostream>
using namespace std;

MYSQL mysql,*connection;
MYSQL_RES *result;
MYSQL_ROW row;

/*char * ip = (char*)"localhost";
char * usr = (char*)"root";
char * pass = (char*)"";
char * db = (char*)"test";

char * ip = (char*)"sql10.freemysqlhosting.net";
char * usr = (char*)"sql10351188";
char * pass = (char*)"FCWP53Cz47";
char * db = (char*)"sql10351188";

int query_state;
void iniciarConexion();
void finalizarConexion();
void agregar();

void iniciarConexion(){

}

void finalizarConexion(){

}

void agregar (){
    try {
        mysql_init(&mysql);
        connection = mysql_real_connect(&mysql, ip, usr, pass, db, 3306, NULL, 0);
        if (connection==NULL){
            cout<<mysql_error(&mysql)<<endl;
        }
        else{
            string k="Gustavo";
            string k2="Torres";
            string k3="gustavo";
            string k4="123";
            string k5="936599914";
            //(mysql_query(&mysql, "INSERT INTO administrador (id_hotel,nombre,apellidos,username,contra,telefono) VALUES (1,"+k+","+k2+","+k3+","+k4+","+k5+")"));
            string query="INSERT INTO administrador (id_hotel,nombre,apellidos,username,contra,telefono) VALUES (1,'"+k+"','"+k2+"','"+k3+"','"+k4+"','"+k5+"')";
            //string query ="SELECT * FROM hotel WHERE id_hotel=1";
            query_state=mysql_query(connection, query.c_str());
            cout<<query_state<<endl;
            if (!query_state) {
                result = mysql_store_result(connection);
                if(result->row_count==0){
                    cout <<"vacio"<<endl;
                }
                else{
                    while(row = mysql_fetch_row(result)){
                        cout<<"id:" <<row[0]<< " nombre: "<< row[1]<<" direccion: "<<row[2]<<" telefono: "<<row[3]<<endl;
                    }
                }

            }
            else {
                cout << mysql_error(connection) << endl;
            }
        }
        mysql_close(&mysql);
    }
    catch (exception &e) {
        cout <<e.what();
    }
}
*/
/*int main() {
    try{
//HU
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES *res;
        conn = mysql_init(nullptr);
        conn = mysql_real_connect(conn, "sql10.freemysqlhosting.net", "sql10351188", "FCWP53Cz47", "sql10351188", 3306,
                                  nullptr, 0);
        if (conn) {
            string query = "INSERT INTO administrador (id_administrador, id_hotel, nombre, apellidos, username, contraseña, telefono) VALUES (NULL, 1, 'Christian David' , 'Sullca Puma', 'cdsp_2020', '123456789', '996017617')";
            const char* q = query.c_str();
            int qstate = mysql_query(conn , q);
            cout<<qstate;
            //if(!qstate){
                //res = mysql_store_result(conn);
                //row = mysql_fetch_row(res);
                //cout<<"nombre"<<row[0]<<endl;
                //while(row = mysql_fetch_row(res)){
                    //cout<<"id:" <<row[0]<< "nombre: "<< row[1]<<"direccion: "<<row[2]<<" telefono: "<<row[3]<<endl;
                //}
            //}
            cout << "conexion exitosa";
        } else {
            cout << "conexion no exitosa";
        }
    } catch (exception &e) {
        cout <<e.what();
    }
    return 0;
}
*/
