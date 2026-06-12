#include "../include/MnjViaje.h"
#include "../include/Viaje.h"    
#include "../include/Reserva.h"

MnjViaje* MnjViaje::instancia = nullptr;
MnjViaje::MnjViaje() {}

MnjViaje* MnjViaje::getInstance(){
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

Viaje* MnjViaje::crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio){
    int numCodigo = 1;
    if(viajes.empty()){
        numCodigo = viajes.rbegin()->first + 1;
    }
    Viaje* vi = new Viaje(numCodigo, fecha, origen, destino, asientosPublicados, precio);
    viajes[numCodigo] = vi;
    return vi;
}

void MnjViaje::agregarReserva(Viaje* vi, Reserva* reserva) {
    vi->agregarReserva(reserva);
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

bool MnjViaje::asientosDisp(Viaje* vi, int asientosSolicitados) {
    return vi->AsientosDisponibles(asientosSolicitados);
}

bool MnjViaje::chequearViajes(DTFecha fecha, std::string origen, std::string destino) {
    for (auto it = viajes.begin(); it != viajes.end(); ++it) {
        Viaje* vi = it->second;
        if (vi->getFecha().getDia() == fecha.getDia() &&
            vi->getFecha().getMes() == fecha.getMes() &&
            vi->getFecha().getAnio() == fecha.getAnio() &&
            vi->getOrigen() == origen &&
            vi->getDestino() == destino) {
    return true;
}
    }
    return false;
}
std::map<int, Viaje*>& MnjViaje::getViajes() {
    return viajes;
}




