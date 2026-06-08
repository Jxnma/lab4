#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTUsuarioViaje.h"
#include <vector>

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
    std::vector<DTUsuarioViaje> getDTUPasajeros(); // se crea un DTUsuarioViaje para cada pasajero asociado a la reserva y los retorna en un Vector
    int getCodigoViaje();
    int getAsientosReservados();
};

#endif
