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

<<<<<<< HEAD
Conductor* Vehiculo::getConductor() const{
    return conductor;
}
void Vehiculo::setConductor(Conductor* c) {
    this->conductor = c;
}
=======
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

Conductor* Vehiculo::getConductor() {
    return this->conductor;
}

void Vehiculo::setConductor(Conductor* conductor) {
    this->conductor = conductor;
}
>>>>>>> main
