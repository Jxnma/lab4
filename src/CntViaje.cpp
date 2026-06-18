#include "../include/CntViaje.h"
#include "../include/MnjUsuario.h"
#include "../include/MnjVehiculo.h"
#include "../include/MnjViaje.h"
#include "../include/Calificacion.h"
#include "../include/Pasajero.h"
#include "../include/Viaje.h"
#include "../include/Vehiculo.h"
#include <vector>

CntViaje* CntViaje::instancia = nullptr;
CntViaje::CntViaje() {
    codigoViaje = 0;
}
CntViaje* CntViaje::getInstance(){
    if (instancia == nullptr) {
        instancia = new CntViaje();
    }
    return instancia;
}
CntViaje::~CntViaje() {
        delete MnjViaje::getInstance();
        delete MnjVehiculo::getInstancia();
}

std::set<DTVehiculosConductor> CntViaje::listarVehiculosConductor(std::string nick){
    MnjUsuario* m = MnjUsuario::getInstance();
    Conductor* c = dynamic_cast<Conductor*>(m->getUsuario(nick));
    std::set<DTVehiculosConductor> listaVehiculos = c->listarVehiculos();
    return listaVehiculos;
}

bool CntViaje::altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio){
    MnjVehiculo* mv = MnjVehiculo::getInstancia();
    Vehiculo* vei = mv->getVehiculo(matricula);
    int capacidad = vei->getCapacidad();
    bool hayViajesFecha = vei->hayViajesConductor(fecha);
    if(capacidad < asientos || hayViajesFecha) 
    return false;
    MnjViaje* mvi = MnjViaje::getInstance();
    Viaje* vi = mvi->crearViaje(vei,fecha, origen, destino, asientos, precio);

    vi->setVehiculo(vei);
    vei->asociarViaje(vi);

    return true;
}

void CntViaje::cancelarEliminarViaje() {
    codigoViaje = 0;                         
}

std::vector<DTListarViaje> CntViaje::listarViajes() {
    std::vector<DTListarViaje> resultado;
    MnjViaje* m = MnjViaje::getInstance();
    
    for (auto& [codigo, vi] : m->getViajes()) {
        Vehiculo* v = vi->getVehiculo();
        Conductor* c = v->getConductor();
        DTListarViaje dtv(
            vi->getCodigo(),
            vi->getFecha(),
            vi->getOrigen(),
            vi->getDestino(),
            c->getNickname()
        );
        resultado.push_back(dtv);
    }
    return resultado;
}

DTDetalleViaje* CntViaje::detalleViaje(int codigo) {
    // guardar en memoria
    this->codigoViaje = codigo;
    MnjViaje* m = MnjViaje::getInstance();
    Viaje* vi = m->getViaje(codigo);
    Vehiculo* v = vi->getVehiculo();

    DTDetalleVehiculo dtv(
        v->getMatricula(),
        v->getCapacidad(),
        v->getMarca(),
        v->getModelo(),
        v->getTipo()
    );

    std::vector<DTDetalleReserva> reservas;
    for (Reserva* r : vi->getReservas()) {
        DTDetalleReserva dtr(
            r->getAsientosReservados(),
            r->getFecha(),
            r->getPasajero()->getNickname()
        );
        reservas.push_back(dtr);
    }

    return new DTDetalleViaje(
        vi->getCodigo(),
        vi->getFecha(),
        vi->getOrigen(),
        vi->getDestino(),
        vi->getAsientosPublicados(),
        vi->getPrecio(),
        dtv,
        reservas
    );
}


void CntViaje::eliminarViaje() {
    MnjViaje* m = MnjViaje::getInstance();
    Viaje* vi = m->getViaje(codigoViaje);
    Vehiculo* v = vi->getVehiculo();

    // recorrer reservas del viaje
    for (Reserva* r : vi->getReservas()) {

        // eliminar links de calificaciones a usuarios
        for (Calificacion* c : r->getCalificaciones()) {
            Usuario* calificador = c->getCalificador();
            Usuario* calificado = c->getUsuarioCalificado();

            if (calificador != nullptr)
                calificador->removeCalificacionRealizada(c);
            if (calificado != nullptr)
                calificado->removeCalificacionRecibida(c);

            
                
        }

        Pasajero* p = r->getPasajero();
        if (p != nullptr)
            p->removeReserva(r);

        
            
    }

    v->removeViaje(vi);
    m->eliminarViaje(codigoViaje);
    codigoViaje = 0;
}

