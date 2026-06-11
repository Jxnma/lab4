#include "../include/CntReserva.h"
#include "../include/MnjViaje.h"
#include "../include/MnjUsuario.h"

CntReserva* CntReserva::instancia = nullptr;

CntReserva* CntReserva::getInstancia() {
    if (instancia == nullptr) {
        instancia = new CntReserva();
    }
    return instancia;
}
CntReserva::~CntReserva() {
}

bool CntReserva::generarReserva(std::string nickname, int codigoViaje, int asientos) {
    MnjViaje* mnjv = MnjViaje::getInstance();
    Viaje* vi = mnjv->getViaje(codigoViaje);
    if(!mnjv->asientosDisp(vi,asientos)) //no hay asientos disponibles
        return false;
    MnjUsuario* mnju =MnjUsuario::getInstance();
    Pasajero* p = dynamic_cast<Pasajero*>(mnju->getUsuario(nickname));
    
    if(p == nullptr || p->tieneReserva(vi))   // el pasajero ya tiene una reserva para ese viaje
        return false;

    Reserva* r = new Reserva(asientos, mnjv->getViaje(codigoViaje)->getFecha());
    mnjv->agregarReserva(vi, r);
    mnju->agregarReserva(nickname, r);
    return true;
}
