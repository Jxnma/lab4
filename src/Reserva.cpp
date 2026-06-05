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