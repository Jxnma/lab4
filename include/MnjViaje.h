#ifndef MNJVIAJE_H
#define MNJVIAJE_H

<<<<<<< HEAD
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
    bool asientosDisp(int codigo, int asientosSolicitados);
    bool chequearViaje(DTFecha fecha, std::string origen, std::string destino);
};

=======
#include "Reserva.h"
#include "Viaje.h"
#include "DTVehiculosConductor.h"
#include <string>
#include <map>
#include <set>
class MnjViaje{
    private:
        static MnjViaje* instancia;
        std::map<int, Viaje*> viajes;
        MnjViaje();
    public:
        static MnjViaje* getInstancia();
        ~MnjViaje();
        Viaje crearViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
        void agregarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
        void agregarReserva(Viaje* vi, Reserva* reserva);
        Viaje* getViaje(int codigo);
        bool existeViaje(int codigo);
        bool asientosDisp(int codigo, int asientosSolicitados);
        bool chequearViaje(DTFecha fecha, std::string origen, std::string destino);
};
>>>>>>> main
#endif