#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
#include <vector>

class Conductor;
class Viaje;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    Conductor* conductor;
    std::vector<Viaje*> viajes;

public:
    //Constructor - Destructor
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();
    //Getters
    Conductor* getConductor() const;
    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
    std::vector<Viaje*> getViajes();
    //Setters de asociacion
    void setConductor(Conductor* conductor);
};

#endif