#ifndef CNTVIAJE_H
#define CNTVIAJE_H
#include <set>
#include "DTDetalleViaje.h"
#include "DTVehiculosConductor.h"
#include "MnjVehiculo.h"
#include "MnjViaje.h"



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

#endif