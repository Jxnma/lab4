#include "../include/MnjViaje.h"

MnjViaje* MnjViaje::instancia = nullptr;
MnjViaje::MnjViaje() {}

MnjViaje* MnjViaje::getInstancia(){
    if (instancia == nullptr) {
        instancia = new MnjViaje();
    }
    return instancia;
}
MnjViaje::~MnjViaje() {
    std::map<int, Viaje>::iterator it;
    for (it = viajes.begin(); it != viajes.end(); ++it) {
        viajes.erase(it);
    }
    viajes.clear();
    delete instancia;
    instancia = nullptr;
};

void MnjViaje::agregarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    Viaje nuevoViaje(codigo, fecha, origen, destino, asientosPublicados, precio);
    viajes[codigo] = nuevoViaje;
}
bool MnjViaje::existeViaje(int codigo) {
    return viajes.find(codigo) != viajes.end();
}
Viaje* MnjViaje::getViaje(int codigo) {
    if (existeViaje(codigo)) {
        return &viajes[codigo];
    }
    return nullptr;
}




