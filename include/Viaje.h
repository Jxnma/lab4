#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include <string>
#include <set>

class Reserva; 
class Vehiculo;

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    std::set<Reserva*> reservas;
    Vehiculo* vehiculo;

public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();
    std::set<DTUsuarioViaje> getParticipantes(); // el grueso del diagrama de comunicación
    Vehiculo* getVehiculo();
    int getCodigo();
};

#endif
