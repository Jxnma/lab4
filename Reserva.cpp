#include "../include/Reserva.h"
#include "../include/Pasajero.h"
#include "../include/Viaje.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}

Reserva::~Reserva() {}
