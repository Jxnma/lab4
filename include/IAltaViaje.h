#ifndef IAltaViaje_H
#define IAltaViaje_H

#include "DTFecha.h"
#include "DTVehiculosConductor.h"
#include <string>
#include <set>

class IAltaViaje {
public:
        virtual std::set<DTVehiculosConductor> listarVehiculosConductor(std::string conductor) = 0;
        virtual bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) = 0;
        virtual ~IAltaViaje() {}
};

#endif
