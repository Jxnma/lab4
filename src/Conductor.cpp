#include "../include/Conductor.h"
#include "../include/Vehiculo.h"
#include "../include/Viaje.h"
#include "../include/DTUsuarioViaje.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

Conductor::~Conductor() {}

DTUsuarioViaje Conductor::getDTUsuarioViaje() const {
    return DTUsuarioViaje(getNickname(), TipoUsuario::Conductor);
}

std::set<Vehiculo*> Conductor:: getVehiculos() const{
    return vehiculos;
}

void Conductor :: agregarVehiculo(Vehiculo* v){
     vehiculos.insert(v);
}

bool Conductor::tieneLibreta(TipoLibreta tipo) {
    return libretas.count(tipo) > 0;
}

std::set<DTListarViaje> Conductor::getViajes() {
    std::set<DTListarViaje> dtvis;
    
    std::set<Vehiculo*> vehiculos = this->getVehiculos(); 
    std::set<Vehiculo*>::iterator it;
    
    for (it = vehiculos.begin(); it != vehiculos.end(); ++it) {
        Vehiculo* v = *it; 

        std::vector<Viaje*> viajes= v->getViajes();
        
        std::vector<Viaje*>::iterator itViaje;
        
        for (itViaje = viajes.begin(); itViaje != viajes.end(); ++itViaje) {
            Viaje* vi = *itViaje;
            
            std::string nickConductor = this->getNickname();
            
            DTListarViaje dtvi(
                vi->getCodigo(),
                vi->getFecha(),
                vi->getOrigen(),
                vi->getDestino(),
                nickConductor
            );
            
            dtvis.insert(dtvi);
        }
    }  
    return dtvis;
}