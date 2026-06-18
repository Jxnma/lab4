#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "ICalificarUsuario.h"
#include "IAltaDeUsuario.h"
#include "IGenerarReserva.h"
#include "IAltaViaje.h"
#include "IEliminarViaje.h"

class Fabrica {
private:
    static Fabrica* instancia;
 
    Fabrica();

public:
    static Fabrica* getInstance();
    ~Fabrica();
    IControladorFechaActual* getIControladorFechaActual();
    ICalificarUsuario* getICalificarUsuario();
    IAltaDeUsuario* getIAltaDeUsuario();
    IGenerarReserva* getIGenerarReserva();
    IAltaViaje* getIAltaViaje();
    IEliminarViaje* getIEliminarViaje();
};

#endif
