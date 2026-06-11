#ifndef CNTVIAJE_H
#define CNTVIAJE_H
#include <set>
#include "IAltaViaje.h"
#include "DTDetalleViaje.h"
#include "DTVehiculosConductor.h"


class CntViaje: public IAltaViaje {
private:
    static CntViaje* instancia;
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