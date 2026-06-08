#ifndef MNJVIAJE_H
#define MNJVIAJE_H

#include "DTVehiculosConductor.h"
#include "DTFecha.h"
#include <string>
#include <map>

class Viaje;
class Reserva;

class MnjViaje {
private:
    static MnjViaje* instancia;
    std::map<int, Viaje*> viajes;
    MnjViaje();

public:
    static MnjViaje* getInstance();
    ~MnjViaje();
    Viaje* crearViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    void agregarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    void agregarReserva(Viaje* vi, Reserva* reserva);
    Viaje* getViaje(int codigo);
    bool existeViaje(int codigo);
    bool asientosDisp(Viaje* vi, int asientosSolicitados);
    bool chequearViaje(DTFecha fecha, std::string origen, std::string destino);
};

#endif