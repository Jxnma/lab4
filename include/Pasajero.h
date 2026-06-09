#ifndef PASAJERO_H
#define PASAJERO_H

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

public:

    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    ~Pasajero();
    bool tieneReserva(Viaje* vi);
    std::set<DTListarViaje> getViajes();
    void addReserva(Reserva* r);
    Reserva* getReserva(int codigoViaje);// para calificarUsuario paso 5.4a movi para pasajero.h, por ende no lleva parametro del pasajero
    std::set<Reserva*> getReservas();
};

#endif
