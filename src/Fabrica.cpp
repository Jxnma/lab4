#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/CntCalificarUsuario.h"
#include "../include/CntUsuario.h"
#include "../include/CntReserva.h"
#include "../include/CntViaje.h"

Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
}
ICalificarUsuario* Fabrica::getICalificarUsuario() {
    return CntCalificarUsuario::getInstance();
}
 IAltaDeUsuario* Fabrica::getIAltaDeUsuario(){
    return CntUsuario::getInstance();
 }

 IGenerarReserva* Fabrica::getIGenerarReserva(){
    return CntReserva::getInstancia();
 }

 IAltaViaje* Fabrica::getIAltaViaje(){
    return CntViaje::getInstancia();
}

IEliminarViaje* Fabrica::getIEliminarViaje() {
    return CntViaje::getInstancia();
}
