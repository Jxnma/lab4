#include "../include/CntReserva.h"
#include "../include/MnjViaje.h"
#include "../include/MnjUsuario.h"

CntReserva* CntReserva::instancia = nullptr;
CntReserva::CntReserva() {}

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

    Reserva* r = new Reserva(asientos, vi->getFecha());
    mnjv->agregarReserva(vi, r);
    mnju->agregarReserva(nickname, r);
    return true;
}

std::set<std::string> CntReserva::listarPasajeros() {
    MnjUsuario* mnjUsuario = MnjUsuario::getInstance();
    return mnjUsuario->getPasajeros();
}

std::set<DTConsultaViaje> CntReserva::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) {
    std::set<DTConsultaViaje> resultado;
    MnjViaje* mnjViaje = MnjViaje::getInstance();
    std::map<int, Viaje*> viajes = mnjViaje->getViajes();

    for (auto const& [codigo, vi] : viajes) {
        if (vi->chequearViaje(fecha, origen, destino) && vi->AsientosDisponibles(asientos))
        {
            Vehiculo* v = vi->getVehiculo();
            Conductor* c = v->getConductor();

            DTConsultaViaje dtcv(
            vi->getCodigo(),
            v->getMarca(),
            v->getModelo(),
            c->getNombre(),
            c->getCalificacionPromedio(),
            vi->getPrecio() * asientos);

            resultado.insert(dtcv);
        }    
    }
    return resultado;
}
