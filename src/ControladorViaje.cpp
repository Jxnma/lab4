#include "../include/ControladorViaje.h"
CntViaje* CntViaje::instancia = nullptr;
CntViaje::CntViaje() {
    mnjViaje = MnjViaje::getInstancia();
    mnjVehiculo = MnjVehiculo::getInstancia();
}
CntViaje* CntViaje::getInstancia() {
    if (instancia == nullptr) {
        instancia = new CntViaje();
    }
    return instancia;
}
CntViaje::~CntViaje() {
    mnjViaje->~MnjViaje();
    mnjVehiculo->~MnjVehiculo();
  
}