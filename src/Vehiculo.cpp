#include "../include/Conductor.h"
#include "../include/Vehiculo.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

Vehiculo::~Vehiculo() {}

//Getters
std::string Vehiculo::getMatricula() {
    return this->matricula;
}

int Vehiculo::getCapacidad() {
    return this->capacidad;
}

std::string Vehiculo::getMarca() {
    return this->marca;
}

std::string Vehiculo::getModelo() {
    return this->modelo;
}

TipoVehiculo Vehiculo::getTipo() {  
    return this->tipo;
}

Conductor* Vehiculo::getConductor() const{
    return this->conductor;
}

void Vehiculo::setConductor(Conductor* conductor) {
    this->conductor = conductor;
}
std::vector<Viaje*> Vehiculo::getViajes(){
    return this->viajes;
}

bool Vehiculo::hayViajesConductor(DTFecha fecha){
    return conductor->hayViajesFechaConductor(fecha);
}
void Vehiculo::asociarViaje(Viaje* vi){
    viajes.push_back(vi);
}
bool Vehiculo::hayViajesFecha(DTFecha fecha){
    for(Viaje* v : viajes){
        if(v!=nullptr and (v->getFecha() == fecha)) 
        return true;
    }
    return false;
    }

