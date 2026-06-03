#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include <string>
#include <set>
#include "DTUsuarioViaje.h"
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
    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    int getAsientosPublicados();
    float getPrecio();
    Vehiculo* getVehiculo();
    std::set<DTUsuarioViaje> getParticipantes();
    bool AsientosDisponibles(int asientosSolicitados);
    Vehiculo* getVehiculo();
};

#endif
