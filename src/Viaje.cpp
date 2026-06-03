#include "../include/Viaje.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}

Viaje::~Viaje() {};

int Viaje::getCodigo(){ 
    return this->codigo; 
}
DTFecha Viaje::getFecha(){
    return this->fecha; 
}
std::string Viaje::getOrigen(){ 
    return this->origen; 
}
std::string Viaje::getDestino() { 
    return this->destino; 
}
int Viaje::getAsientosPublicados(){ 
    return this->asientosPublicados; 
}
float Viaje::getPrecio() { 
    return this->precio; 
}

Vehiculo* Viaje::getVehiculo() { 
    return this->vehiculo; 
}

bool Viaje::AsientosDisponibles(int asientosSolicitados) {
}


