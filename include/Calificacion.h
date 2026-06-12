#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Usuario;
class Reserva;

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;
    Usuario* calificador;
    Usuario* calificado;
    Reserva* reserva;

public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();
    void addCalificador(Usuario* u);
    void addCalifica(Usuario* u);
    void addSobreReserva(Reserva* r);
    bool calificaA(Usuario* u, int codigoViaje);
    Usuario* getUsuarioCalificado();
    Usuario* getCalificador();
    Reserva* getReserva();
};

#endif
