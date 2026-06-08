#include "../include/MnjVehiculo.h"

MnjVehiculo* MnjVehiculo::instancia = nullptr;
MnjVehiculo::MnjVehiculo() {}

MnjVehiculo* MnjVehiculo::getInstancia(){
    if (instancia == nullptr) {
        instancia = new MnjVehiculo();
    }
    return instancia;
}

MnjVehiculo::~MnjVehiculo(){
    std::map<std::string, Vehiculo*>::iterator it;
    for (it = vehiculos.begin(); it != vehiculos.end(); ++it) {
        delete it->second;
    }
    vehiculos.clear();
    instancia = nullptr;
}
    
 

void MnjVehiculo::agregarVehiculo(Vehiculo* v) {
    vehiculos[v->getMatricula()] = v;
}

Vehiculo* MnjVehiculo::getVehiculo(std::string matricula) {
    return vehiculos[matricula];
}

bool MnjVehiculo::existeVehiculo(std::string matricula) {
    return vehiculos.find(matricula) != vehiculos.end();
}

Vehiculo* MnjVehiculo::nuevoVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    Vehiculo* v = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
    agregarVehiculo(v);
    return v;
}