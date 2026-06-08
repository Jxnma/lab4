#ifndef IALTADEUSUARIO_H
#define IALTADEUSUARIO_H
 
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include <string>
#include <set>
 
class IAltaDeUsuario {
public:
    virtual bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) = 0;
    virtual bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) = 0;
    virtual int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) = 0;
    virtual ~IAltaDeUsuario() {}
};
 
#endif