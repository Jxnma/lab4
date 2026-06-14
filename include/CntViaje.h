#ifndef CNTVIAJE_H
#define CNTVIAJE_H
#include <set>
#include <vector>
#include "IAltaViaje.h"
#include "DTDetalleViaje.h"
#include "DTVehiculosConductor.h"
#include "DTListarViaje.h" 
#include "IEliminarViaje.h"



class CntViaje: public IAltaViaje, public IEliminarViaje {
private:
    static CntViaje* instancia;
    int codigoViaje;
    CntViaje();
public:
    static CntViaje* getInstancia();
    ~CntViaje();
    std::set<DTVehiculosConductor> listarVehiculosConductor(std::string nick);
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);
    DTDetalleViaje* detalleViaje(int codigo);
    void eliminarViaje();
    void cancelarEliminarViaje();
    std::vector<DTListarViaje> listarViajes();
};

#endif