#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include <string>

class Pasajero : public Usuario {
private:
    std::string ci;
    std::set<Reserva*> getReservas();

public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    ~Pasajero();
    Reserva* getReserva(int codigoViaje); // para calificarUsuario paso 5.4a
};

#endif
