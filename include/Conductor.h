#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "DTUsuarioViaje.h"
#include "Usuario.h"
#include "TipoLibreta.h"
#include "DTVehiculosConductor.h"
#include <set>

class Vehiculo;

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;
    std::set<Vehiculo*> vehiculos; 

public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();
    DTUsuarioViaje getDTUsuarioViaje() const;
    std::set<Vehiculo*> getVehiculos() const;
    DTUsuarioViaje getDTUsuarioViaje();
    bool tieneLibreta(TipoLibreta tipo);
    std::set<DTVehiculosConductor> listarVehiculos();
    void agregarVehiculo(Vehiculo* v); 
    std::set<DTListarViaje> getViajes();
    bool hayViajesFechaConductor(DTFecha fecha);
};

#endif
