cmake_minimum_required(VERSION 3.16)
project(PS)

set(CMAKE_CXX_STANDARD 14)

add_executable(PS main.cpp
        Servicio/Servicio.cpp Servicio/Servicio.h
        Hotel/Hotel.cpp Hotel/Hotel.h
        Usuario/Usuario.cpp Usuario/Usuario.h
        Cliente/Cliente.cpp Cliente/Cliente.h
        Administrador/Administrador.h Administrador/Administrador.cpp
        Turno/Turno.cpp Turno/Turno.h
        Reservacion/Reservacion.cpp Reservacion/Reservacion.h
        TipoHabitacion/TipoHabitacion.cpp TipoHabitacion/TipoHabitacion.h
        ReciboHospedaje/ReciboHospedaje.cpp ReciboHospedaje/ReciboHospedaje.h
        AdquirirServicio/AdquirirServicio.cpp AdquirirServicio/AdquirirServicio.h
        Habitacion/Habitacion.cpp Habitacion/Habitacion.h
        ControlReservacion.cpp)