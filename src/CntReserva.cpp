#include "../include/CntReserva.h"

CntReserva* CntReserva::instancia = nullptr;
CntReserva::CntReserva() {
    mnjViaje = MnjViaje::getInstance();
    mnjUsuario = MnjUsuario::getInstance();
}
CntReserva* CntReserva::getInstancia() {
    if (instancia == nullptr) {
        instancia = new CntReserva();
    }
    return instancia;
}
CntReserva::~CntReserva() {
}

bool CntReserva::generarReserva(std::string nickname, int codigoViaje, int asientos) {
    Viaje* vi = mnjViaje->getViaje(codigoViaje);
    if(!mnjViaje->asientosDisp(vi,asientos)) //no hay asientos disponibles
        return false;
    Pasajero* p = dynamic_cast<Pasajero*>(mnjUsuario->getUsuario(nickname));
    if(p->tieneReserva(vi)) // el pasajero ya tiene una reserva para ese viaje
        return false;

    Reserva* r = new Reserva(asientos, mnjViaje->getViaje(codigoViaje)->getFecha());
    mnjViaje->agregarReserva(vi, r);
    mnjUsuario->agregarReserva(nickname, r);
    return true;
}

std::set<std::string> CntReserva::listarPasajeros() {
    return mnjUsuario->getPasajeros();
}
