#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "ICalificarUsuario.h"
#include "IAltaDeUsuario.h"
#include "IGenerarReserva.h"
#include "IAltaViaje.h"

class Fabrica {
private:
    static Fabrica* instancia;
 
    Fabrica();

public:
    static Fabrica* getInstance();

    IControladorFechaActual* getIControladorFechaActual();
    ICalificarUsuario* getICalificarUsuario();
    IAltaDeUsuario* getIAltaDeUsuario();
    IGenerarReserva* getIGenerarReserva();
    IAltaViaje* getIAltaViaje();
};

#endif
