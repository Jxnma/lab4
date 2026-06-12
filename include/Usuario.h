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
    std::set<Calificacion*> calificacionesRealizadas;
    std::set<Calificacion*> calificacionesRecibidas;
public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();
    std::string getNickname() const;
    std::string getNombre();
    virtual std::set<DTListarViaje> getViajes()=0;
    bool existeCalificacion(Usuario* uCalif, int codVi);
    bool crearCalificacion(Usuario* uCalif, int vi, int cal, DTFecha fecha);
    void addRealiza(Calificacion* c);
    void addCalificacionRecibida(Calificacion* c);
    float getCalificacionPromedio();
};

#endif
