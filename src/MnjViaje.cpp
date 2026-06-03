#include "../include/MnjViaje.h"
#include "../include/Viaje.h"    
#include "../include/Reserva.h"

MnjViaje* MnjViaje::instancia = nullptr;
MnjViaje::MnjViaje() {}

MnjViaje* MnjViaje::getInstancia(){
    if (instancia == nullptr) {
        instancia = new MnjViaje();
    }
    return instancia;
}
MnjViaje::~MnjViaje() {
    std::map<int, Viaje*>::iterator it;
    for (it = viajes.begin(); it != viajes.end(); ++it) {
        delete it->second;
    }
    viajes.clear();
    instancia = nullptr;
}

Viaje* MnjViaje::getViaje(int codigo) {
    auto it = viajes.find(codigo);
    if (it != viajes.end()) {
        return it->second;
    }
    return nullptr;
}

bool MnjViaje::existeViaje(int codigo) {
    return viajes.find(codigo) != viajes.end();
}

bool MnjViaje::asientosDisp(int codigo, int asientosSolicitados) {
        return viajes[codigo]->AsientosDisponibles(asientosSolicitados);
}






