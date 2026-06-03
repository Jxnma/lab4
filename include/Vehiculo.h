#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
<<<<<<< HEAD
#include <set>

=======
>>>>>>> main
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
    std::set<Viaje*> viajes;

public:
    //Constructor - Destructor
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();
<<<<<<< HEAD
    Conductor* getConductor() const;
    void setConductor(Conductor* c);
=======
    //Getters
    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
    Conductor* getConductor();
    //Setters de asociacion
    void setConductor(Conductor* conductor);
>>>>>>> main
};

#endif