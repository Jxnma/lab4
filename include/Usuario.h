#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include "DTFecha.h"          
#include "DTListarViaje.h"  

class Calificacion;   
class Reserva;        
class Pasajero;

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    std::set<Calificacion*> calificaciones;
public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();
    std::string getNickname() const;
    std::string getNombre();
    float getCalificacionPromedio();
    virtual std::set<DTListarViaje> getViajes()=0;
    bool existeCalificacion(Usuario* uCalif, int codVi);
    bool crearCalificacion(Usuario* uCalif, int vi, int cal, DTFecha fecha);
    Reserva* getReserva(Pasajero* p, int codigoViaje);
    void addRealiza(Calificacion* c);
};

#endif
