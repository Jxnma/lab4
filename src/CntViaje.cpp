#include "../include/CntViaje.h"
CntViaje* CntViaje::instancia = nullptr;
CntViaje::CntViaje() {
    mnjUsuario = MnjUsuario::getInstance();
    mnjViaje = MnjViaje::getInstance();
    mnjVehiculo = MnjVehiculo::getInstancia();
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
    Conductor* c = dynamic_cast<Conductor*>(mnjUsuario->getUsuario(nick));
    std::set<DTVehiculosConductor> listaVehiculos = c->listarVehiculos();
    return listaVehiculos;
}

bool CntViaje::altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio){
    Vehiculo* v = mnjVehiculo->getVehiculo(matricula);
    int capacidad = v->getCapacidad();
    bool hayViajesFecha = v->hayViajesConductor(fecha);
    if(capacidad < asientos || hayViajesFecha) 
    return false;
    
    Viaje* vi = mnjViaje->crearViaje(v,fecha, origen, destino, asientos, precio);

    vi->setVehiculo(v);
    v->asociarViaje(vi);

    return true;
}

