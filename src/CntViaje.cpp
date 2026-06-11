#include "../include/CntViaje.h"
#include "../include/MnjUsuario.h"
#include "../include/MnjVehiculo.h"
#include "../include/MnjViaje.h"

CntViaje* CntViaje::instancia = nullptr;
CntViaje::CntViaje() {
    mnjUsuario = MnjUsuario::getInstance();
    mnjViaje = MnjViaje::getInstance();
    mnjVehiculo = MnjVehiculo::getInstancia();
    codigoViaje = 0;
}
CntViaje* CntViaje::getInstancia() {
    if (instancia == nullptr) {
        instancia = new CntViaje();
    }
    return instancia;
}
CntViaje::~CntViaje() {
}

std::set<DTVehiculosConductor> CntViaje::listarVehiculosConductor(std::string nick){
    MnjUsuario* m = MnjUsuario::getInstance();
    Conductor* c = dynamic_cast<Conductor*>(m->getUsuario(nick));
    std::set<DTVehiculosConductor> listaVehiculos = c->listarVehiculos();
    return listaVehiculos;
}

bool CntViaje::altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio){
    MnjVehiculo* mv = MnjVehiculo::getInstancia();
    Vehiculo* vei = mv->getVehiculo(matricula);
    int capacidad = vei->getCapacidad();
    bool hayViajesFecha = vei->hayViajesConductor(fecha);
    if(capacidad < asientos || hayViajesFecha) 
    return false;
    MnjViaje* mvi = MnjViaje::getInstance();
    Viaje* vi = mvi->crearViaje(vei,fecha, origen, destino, asientos, precio);

    vi->setVehiculo(vei);
    vei->asociarViaje(vi);

    return true;
}

void CntViaje::cancelarEliminarViaje() {
    codigoViaje = 0;                         
}

std::set<DTListarViaje> CntViaje::listarViajes() {
    // falta hacer
}

DTDetalleViaje* CntViaje::detalleViaje(int codigo) {
    // falta hacer
}


void CntViaje::eliminarViaje() {
    // falta hacer
}

