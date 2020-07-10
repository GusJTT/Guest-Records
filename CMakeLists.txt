cmake_minimum_required(VERSION 3.5)
project(PS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ejecutable")

include_directories("C:\\Program Files\\MySQL\\Connector C++ 8.0\\include")
include_directories("C:\\Program Files\\MySQL\\MySQL Server 8.0\\include")
link_directories("C:\\Program Files\\MySQL\\MySQL Server 8.0\\lib")
link_directories("C:\\Program Files\\MySQL\\Connector C++ 8.0\\lib64\\vs14")
#add_executable(ga "mysqlcppconn.lib")
#add_dependencies(PS libmysql.lib)
set(P_S main.cpp
#        Servicio/Servicio.cpp Servicio/Servicio.h
#        Hotel/Hotel.cpp Hotel/Hotel.h
#        Usuario/Usuario.cpp Usuario/Usuario.h
#        Cliente/Cliente.cpp Cliente/Cliente.h
#        Administrador/Administrador.h Administrador/Administrador.cpp
#        Turno/Turno.cpp Turno/Turno.h
#        Reservacion/Reservacion.cpp Reservacion/Reservacion.h
#        TipoHabitacion/TipoHabitacion.cpp TipoHabitacion/TipoHabitacion.h
#        ReciboHospedaje/ReciboHospedaje.cpp ReciboHospedaje/ReciboHospedaje.h
#        AdquirirServicio/AdquirirServicio.cpp AdquirirServicio/AdquirirServicio.h
#        Habitacion/Habitacion.cpp Habitacion/Habitacion.h
        TipoHabitacion/TipoHabitacion.cpp TipoHabitacion/TipoHabitacion.h
        Reservacion/Reservacion.h Reservacion/Reservacion.cpp Habitacion/Habitacion.cpp Habitacion/Habitacion.h
        Funciones/funciones.cpp Conexion/Conexion2.cpp Conexion/Conexion.cpp Conexion/Conexion.h)
add_executable(PS ${P_S})
target_link_libraries(PS mysqlcppconn.lib)
target_link_libraries(PS libmysql)

#add_executable(PS main.cpp
#        Servicio/Servicio.cpp Servicio/Servicio.h
#        Hotel/Hotel.cpp Hotel/Hotel.h
#        Usuario/Usuario.cpp Usuario/Usuario.h
#        Cliente/Cliente.cpp Cliente/Cliente.h
#        Administrador/Administrador.h Administrador/Administrador.cpp
#        Turno/Turno.cpp Turno/Turno.h
#        Reservacion/Reservacion.cpp Reservacion/Reservacion.h
#        TipoHabitacion/TipoHabitacion.cpp TipoHabitacion/TipoHabitacion.h
#        ReciboHospedaje/ReciboHospedaje.cpp ReciboHospedaje/ReciboHospedaje.h
#        AdquirirServicio/AdquirirServicio.cpp AdquirirServicio/AdquirirServicio.h
#        Habitacion/Habitacion.cpp Habitacion/Habitacion.h
#        )