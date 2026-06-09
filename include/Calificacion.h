#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Usuario;
class Reserva;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* calificado;
    Reserva* reserva;

public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();
    void addCalifica(Usuario* u);
    void addSobreReserva(Reserva* r);
    bool calificaA(Usuario* u, int codigoViaje);
    Usuario* getUsuarioCalificado();
    Reserva* getReserva();
};

#endif
