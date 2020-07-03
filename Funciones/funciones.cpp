#include <iostream>
#include <afxres.h>
#include <conio.h>
#define ENTER 13
#define BACKSPACE 8
#include "../Administrador/Administrador.h"
#include "../Conexion/Conexion.h"


using namespace std;
bool iniciarSesion(Administrador& admin,Conexion bd_conexion);
void menu_principal(Administrador& admin,Conexion bd_conexion);

inline bool iniciarSesion(Administrador& admin,Conexion bd_conexion) {
    string user;
    string password;
    char op;
    bool autentificacion=false;
    do {
        cout << "Ingrese usuario" << endl;
        cin.ignore(256, '\n');
        getline(cin, user);
        cout << "Ingrese Contraseña" << endl;
        char caracter;
        caracter = getch();
        password = "";
        while (caracter != ENTER) {
            if (caracter != BACKSPACE) {
                password.push_back(caracter);
                cout << "*";
            }
            else {
                if (password.length() > 0) {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = getch();
        }
        //getline(cin, password);
        if(bd_conexion.inicioSesion(admin,user,password)) {
            cout<<endl<<endl<<"Cuenta valida"<<endl;
            cout<<"Espere un momento";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            Sleep(1000);
            cout<<".";
            autentificacion=true;
        }
        else{
            cout<<endl<<endl<<"Usuario o contraseña invalidos"<<endl;
            cout<<"Desea intertar nuevamente (1)Si (2)No"<<endl;
            cout<<"Opcion: ";
            cin>>op;
        }
        system("cls");
    }while (!autentificacion ^ op=='2');
    if(autentificacion){
        return true;
    }
    if(op=='2'){
        return false;
    }
    return false;
}

inline void menu_principal(Administrador& admin,Conexion bd_conexion) {
    char op;
    do{
        cout<<"Menu Principal"<< endl;
        cout<<"(1) Reservaciones"<<endl;
        cout<<"(2) Servicio de Hotel"<<endl;
        cout<<"(3) Turnos"<<endl;
        cout<<"(4) Administradores"<<endl;
        cout<<"(5) Clientes"<<endl;
        cout<<"(6) Servicios"<<endl;
        cout<<"Opcion : ";
        cin>>op;
        switch (op) {

            case '1':
                system("cls");
                cout<<"SERVICIO DE RESERVACIONES"<<endl;
                system("pause");
                break;

            case '2':
                system("cls");
                cout<<"SERVICIO DE HOTEL"<<endl;
                system("pause");
                break;

            case '3':
                system("cls");
                cout<<"TURNOS"<<endl;
                system("pause");
                break;

            case '4':
                system("cls");
                cout<<"ADMINISTRADORES"<<endl;
                system("pause");
                break;

            case '5':
                system("cls");
                cout<<"CLIENTES"<<endl;
                system("pause");
                break;

            case '6':
                system("cls");
                cout<<"SERVICIOS"<<endl;
                system("pause");
                break;

            case '7':
                system("cls");
                cout<<"Salio del menu principal"<<endl;
                system("pause");
                break;

            default:
                system("cls");
                cin.ignore(256,'\n');
                cout<< "Opcion Invalida";
                break;
        }

    }while(op!='7');
}

