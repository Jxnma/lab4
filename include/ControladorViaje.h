#ifndef CONTROLADOR_VIAJE_H
#define CONTROLADOR_VIAJE_H

#include "DTDetalleViaje.h"
#include "DTVehiculosConductor.h"
#include "MnjVehiculo.h"
#include "MnjViaje.h"

#endif

class CntViaje {
private:
    static CntViaje* instancia;
    MnjViaje* mnjViaje;
    MnjVehiculo* mnjVehiculo;
    CntViaje();
public:
    static CntViaje* getInstancia();
    ~CntViaje();
    std::set<DTVehiculosConductor*> listarVehiculosConductor(std::string conductor);
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, float precio);
    DTDetalleViaje* detalleViaje(int codigo);
    void eliminarViaje();
    void cancelarEliminarViaje();
};
