#include "../include/Pasajero.h"
#include "../include/Reserva.h"
#include "../include/Viaje.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}

Pasajero::~Pasajero() {}

 bool Pasajero::tieneReserva(Viaje* vi) {
    bool encontrada = false;
    for (Reserva* r : this->Reservas) {
        if (r->getCodigoViaje() == vi->getCodigo()) {
            encontrada = true;
        }
    }
    return encontrada;
 }

 void Pasajero::addReserva(Reserva* r) {
    this->Reservas.insert(r);
 }
 std::set<Reserva*> Pasajero::getReservas() {
    return this->Reservas;
}

 Reserva* Pasajero::getReserva(int codigoViaje) {
    for (Reserva* r : this->Reservas) {
        if (r->getCodigoViaje() == codigoViaje) {
            return r;
        }
    }
    return nullptr; // Si no se encuentra la reserva para el viaje dado
}