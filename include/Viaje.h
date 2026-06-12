#ifndef VIAJE_H
#define VIAJE_H

#include "Reserva.h"
#include "DTUsuarioViaje.h"
#include "DTFecha.h"
#include <string>
#include <vector>
#include "DTUsuarioViaje.h"

class Vehiculo;

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    std::vector<Reserva*> reservas;
    Vehiculo* vehiculo;

public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();
    Vehiculo* getVehiculo();
    void setVehiculo(Vehiculo* v);
    int getCodigo() const;
    void agregarReserva(Reserva* r);
    std::vector<DTUsuarioViaje> getParticipantes(std::string nicknameCalificador);
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    int getAsientosPublicados();
    float getPrecio();
    bool AsientosDisponibles(int asientosSolicitados);
    std::vector<Reserva*> getReservas();
    bool chequearViaje(DTFecha fecha, std::string origen, std::string destino);
};

#endif
