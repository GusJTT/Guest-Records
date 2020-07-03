#include <iostream>
#include "Funciones/funciones.cpp"
#include "Conexion/Conexion.h"
#include "Administrador/Administrador.h"
using namespace std;

int main() {
    Conexion bd_conexion;
    Hotel hotel=bd_conexion.getDatosHotel(2);
    Administrador administrador;
    char op;
    do {
        cout <<"Hotel "<<hotel.nombre<< endl;
        cout <<"Direccion "<<hotel.direccion<< endl;
        cout <<"Telefono "<<hotel.telefono<< endl;
        cout<<"Seleccione la opcion"<<endl;
        cout<<"(1) Iniciar Sesion"<<endl;
        cout<<"(2) Cerrar"<<endl;
        cout<<"Opcion : ";
        cin>>op;

        switch (op) {

            case '1':
                system("cls");
                if(iniciarSesion(administrador,bd_conexion)){
                    cout<<"Bienvenido al sistema "+administrador.nombre<<" "<<administrador.apellidos<<endl;
                    menu_principal(administrador,bd_conexion);
                }
                break;

            case '2':
                system("cls");
                cout<<"Fin del programa"<<endl;
                break;

            default:
                system("cls");
                cin.ignore(256,'\n');
                cout<< "Opcion Invalida";
                break;
        }
    }while (op!='2');
    bd_conexion.finalizarConexion();
    return 0;
}




