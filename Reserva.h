#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTUsuarioViaje.h"
#include <set>

class Pasajero;
class Viaje; 

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero* pasajero;  // la reserva pertenece a un pasajero
    Viaje* viaje;       // la reserva pertenece a un viaje

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();
    std::set<DTUsuarioViaje> getDTUPasajeros(); // retorna el pasajero de esta reserva como DTUsuarioViaje
    int getCodigoViaje();
};

#endif
