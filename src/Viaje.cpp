#include "../include/Viaje.h"
#include "../include/Reserva.h"    
#include "../include/Vehiculo.h"
#include "../include/Conductor.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}

Viaje::~Viaje() {}

void Viaje::agregarReserva(Reserva* r) {
    reservas.push_back(r);  
}

void Viaje::setVehiculo(Vehiculo* v) {
    vehiculo = v;
}
int Viaje::getCodigo() const{
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
    //falta hacer
    return;
}

std::vector<DTUsuarioViaje> Viaje::getParticipantes(std::string nicknameCalificador) {
    std::vector<DTUsuarioViaje> resultado;
    for (Reserva* r : reservas) {
        auto dts = r->getDTUPasajeros();
        for (const auto& dt : dts) {
            if (dt.getNickname() != nicknameCalificador) {  // filtro acá
                resultado.push_back(dt);
            }
        }
    }
    
    Conductor* c = vehiculo->getConductor();
    DTUsuarioViaje dtConductor = c->getDTUsuarioViaje();
    if (dtConductor.getNickname() != nicknameCalificador) {  // filtro acá también
        resultado.push_back(dtConductor);
    }
    
    return resultado;
}
