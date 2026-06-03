#ifndef VIAJE_H
#define VIAJE_H

#include "DTUsuarioViaje.h"
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
<<<<<<< HEAD
    Vehiculo* getVehiculo();
    void setVehiculo(Vehiculo* v);
    int getCodigo() const;
    void agregarReserva(Reserva* r);
    std::set<DTUsuarioViaje> getParticipantes(std::string nicknameCalificador) ;
=======
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
>>>>>>> main
};

#endif
