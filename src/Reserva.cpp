#include "../include/Reserva.h"
#include "../include/Pasajero.h"
#include "../include/Viaje.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = nullptr;
    this->viaje = nullptr;
}

Reserva::~Reserva() {}

std::vector<DTUsuarioViaje> Reserva::getDTUPasajeros() {
    std::vector<DTUsuarioViaje> resultado;
    if (pasajero != nullptr) {
        resultado.push_back(DTUsuarioViaje(pasajero->getNickname(), TipoUsuario::Pasajero));
    }
    return resultado;
}

int Reserva::getCodigoViaje() {
    return viaje->getCodigo();
}

int Reserva::getAsientosReservados() {
    return this->asientosReservados;
}

Viaje* Reserva::getViaje() {
    return this->viaje;
}
DTFecha Reserva::getFecha() {
    return fecha;
}
Pasajero* Reserva::getPasajero() {
    return pasajero;
}
void Reserva::setPasajero(Pasajero* p) {
    this->pasajero = p;
}
void Reserva::setViaje(Viaje* v) {
    this->viaje = v;
}
void Reserva::addCalificacion(Calificacion* c) {
    calificaciones.push_back(c);
}

std::vector<Calificacion*> Reserva::getCalificaciones() {
    return calificaciones;
}