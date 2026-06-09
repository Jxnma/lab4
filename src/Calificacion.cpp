#include "../include/Calificacion.h"
#include "../include/Usuario.h"
#include "../include/Reserva.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->calificado = nullptr;
    this->reserva = nullptr;
}

Calificacion::~Calificacion() {}

void Calificacion::addCalifica(Usuario* u) {
    this->calificado = u;
}

void Calificacion::addSobreReserva(Reserva* r) {
    this->reserva = r;
}

bool Calificacion::calificaA(Usuario* u, int codigoViaje) {
    return (calificado == u && reserva->getCodigoViaje() == codigoViaje);
}

Usuario* Calificacion::getUsuarioCalificado() {
    return calificado;
}

Reserva* Calificacion::getReserva() {
    return reserva;
}