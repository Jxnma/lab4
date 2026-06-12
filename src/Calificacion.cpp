#include "../include/Calificacion.h"
#include "../include/Usuario.h"
#include "../include/Reserva.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->calificador = nullptr;
    this->calificado = nullptr;
    this->reserva = nullptr;
}

Calificacion::~Calificacion() {}

void Calificacion::addCalificador(Usuario* u) {
    this->calificador = u;
}

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
Usuario* Calificacion::getCalificador() {
    return calificador;
}

Reserva* Calificacion::getReserva() {
    return reserva;
}