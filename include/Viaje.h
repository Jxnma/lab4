#ifndef VIAJE_H
#define VIAJE_H

#include "DTUsuarioViaje.h"
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
    Vehiculo* getVehiculo();
    void setVehiculo(Vehiculo* v);
    int getCodigo() const;
    void agregarReserva(Reserva* r);
    std::set<DTUsuarioViaje> getParticipantes(std::string nicknameCalificador) ;
};

#endif
