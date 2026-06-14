#ifndef IGenerarReserva_H
#define IGenerarReserva_H

#include "DTFecha.h"
#include "DTConsultaViaje.h"
#include <string>
#include <set>

class IGenerarReserva {
public:
    virtual bool generarReserva(std::string nicknamePasajero,int codigoViaje, int cantidadAsientos) = 0;
    virtual std::set<std::string> listarPasajeros() = 0;
    virtual std::set<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int cantidadAsientos) = 0;
    virtual ~IGenerarReserva(){}
};

#endif
