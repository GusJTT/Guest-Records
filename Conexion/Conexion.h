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
        char * usr = (char*)"sql10352889";
        char * pass = (char*)"ug7jc4mGXp";
        char * db = (char*)"sql10352889";

    public:
        Conexion();
        void iniciarConexion();
        void finalizarConexion();
        void consultaReservaciones();
        void buscarReservacion(string id);
        void agregarReservacion(string idReservacion, string idHabitacion, string idCliente, string fecha);
        void modificarReservacion(string idReservacion, string idHabitacion, string idCliente, string fecha);
        void eliminarReservacion(string idReservacion);
        Hotel getDatosHotel(int id);
        bool inicioSesion(Administrador &admin,string username,string contra);
};
#endif //PS_CONEXION_H
