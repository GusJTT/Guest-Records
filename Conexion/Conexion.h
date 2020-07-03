#ifndef PS_CONEXION_H
#define PS_CONEXION_H

#include <mysql.h>
#include <iostream>
#include "../Hotel/Hotel.h"
#include "../Administrador/Administrador.h"

using namespace std;
class Conexion {

    private:
        char * ip = (char*)"sql10.freemysqlhosting.net";
        char * usr = (char*)"sql10351188";
        char * pass = (char*)"FCWP53Cz47";
        char * db = (char*)"sql10351188";

    public:
        Conexion();
        void iniciarConexion();
        void finalizarConexion();
        Hotel getDatosHotel(int id);
        bool inicioSesion(Administrador &admin,string username,string contra);
};
#endif //PS_CONEXION_H
