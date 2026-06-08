#ifndef MNJUSUARIO_H
#define MNJUSUARIO_H

#include <string>
#include <set>
#include <map>

#include "DTUsuario.h"
#include "TipoLibreta.h"

class Usuario;
class Pasajero;
class Viaje;
class Reserva;

class MnjUsuario{
private:
    static MnjUsuario* instancia;
    std::map<std::string, Usuario*> usuarios;
    MnjUsuario();
public:
    static MnjUsuario* getInstance();
    std:: set<DTUsuario> getUsuarios();
    Usuario* getUsuario(std::string nickname);
    std::set<std::string> getPasajeros();
    Usuario* registVehiCond(std::string nick);
    bool tieneReserva(Pasajero* p, Viaje* vi);
    void agregarReserva(std::string nick, Reserva* r);
    bool nuevoConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas);
    bool nuevoPasajero(std::string nickname,std::string nombre, std::string contrasena, std::string email, std::string ci);
    bool existeUsuario(std::string nickname);
    void agregarUsuario(Usuario* u);
};

#endif