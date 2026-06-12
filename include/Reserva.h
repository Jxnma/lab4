#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTUsuarioViaje.h"
#include <vector>

class Pasajero;
class Viaje; 
class Calificacion;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero* pasajero;  // la reserva pertenece a un pasajero
    Viaje* viaje;       // la reserva pertenece a un viaje
    std::vector<Calificacion*> calificaciones; // para eliminarViaje

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();
    std::vector<DTUsuarioViaje> getDTUPasajeros(); // se crea un DTUsuarioViaje para cada pasajero asociado a la reserva y los retorna en un Vector
    int getCodigoViaje();
    int getAsientosReservados();
    Viaje* getViaje();
    DTFecha getFecha();
    Pasajero* getPasajero();
    void setPasajero(Pasajero* p);
    void setViaje(Viaje* v);
    void addCalificacion(Calificacion* c);
    std::vector<Calificacion*> getCalificaciones();
};

#endif
