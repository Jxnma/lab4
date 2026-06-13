#ifndef IELIMINARVIAJE_H
#define IELIMINARVIAJE_H
#include <vector>
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"

class IEliminarViaje {
public:
    virtual std::vector<DTListarViaje> listarViajes() = 0;
    virtual DTDetalleViaje* detalleViaje(int codigo) = 0;
    virtual void eliminarViaje() = 0;
    virtual void cancelarEliminarViaje() = 0;
    virtual ~IEliminarViaje() {}
};
#endif
