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

Conductor* Vehiculo::getConductor() const{
    return conductor;
}
void Vehiculo::setConductor(Conductor* c) {
    this->conductor = c;
}
