#ifndef CNTVIAJE_H
#define CNTVIAJE_H
#include <set>
#include "IAltaViaje.h"
#include "DTDetalleViaje.h"
#include "DTVehiculosConductor.h"
#include "MnjUsuario.h"
#include "MnjVehiculo.h"
#include "MnjViaje.h"



class CntViaje: public IAltaViaje {
private:
    static CntViaje* instancia;
    MnjViaje* mnjViaje;
    MnjVehiculo* mnjVehiculo;
    MnjUsuario* mnjUsuario;
    CntViaje();
public:
    static CntViaje* getInstancia();
    ~CntViaje();
    std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nick);
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);
    DTDetalleViaje* detalleViaje(int codigo);
    void eliminarViaje();
    void cancelarEliminarViaje();
};

#endif