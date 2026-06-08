#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/CntCalificarUsuario.h"
#include "../include/CntUsuario.h"

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
