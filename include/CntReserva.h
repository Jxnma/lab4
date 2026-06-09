
#ifndef CNTRESERVA_H
#define CNTRESERVA_H

#include "IAltaViaje.h"
#include "IGenerarReserva.h"
#include "MnjViaje.h"
#include "MnjUsuario.h"
#include "Reserva.h"
#include "DTConsultaViaje.h"
#include <set>

class CntReserva: public IGenerarReserva {
private:
    static CntReserva* instancia;
    MnjViaje* mnjViaje;
    MnjUsuario* mnjUsuario;
    CntReserva();

public:
    static CntReserva* getInstancia();
    ~CntReserva();
    bool generarReserva(std::string nickname, int codigoViaje, int asientos);
    std::set<std::string> listarPasajeros();
    std::set<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);

};          
#endif