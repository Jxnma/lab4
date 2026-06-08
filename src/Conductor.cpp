#include "../include/Conductor.h"
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