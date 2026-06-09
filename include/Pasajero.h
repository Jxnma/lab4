#ifndef PASAJERO_H
#define PASAJERO_H

#include "Reserva.h"
#include "Viaje.h"
#include "Usuario.h"
#include "DTListarViaje.h"
#include <string>
#include <set>

class Reserva;   
class Viaje;   

class Pasajero : public Usuario {
private:
    std::string ci;
    std::set<Reserva*> Reservas;
    std::set<Reserva> getReservas();

public:

    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    ~Pasajero();
    Reserva* getReserva(int codigoViaje); // para calificarUsuario paso 5.4a
    bool tieneReserva(Viaje* vi);
    std::set<DTListarViaje> getViajes();
    void addReserva(Reserva* r);
};

#endif
