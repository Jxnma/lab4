#include "../include/CntViaje.h"
CntViaje* CntViaje::instancia = nullptr;
CntViaje::CntViaje() {
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
    mnjViaje->~MnjViaje();
    mnjVehiculo->~MnjVehiculo();
  
}