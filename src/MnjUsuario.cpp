#include "../include/MnjUsuario.h"

MnjUsuario* MnjUsuario::instancia = nullptr;
MnjUsuario :: MnjUsuario(){}

MnjUsuario* MnjUsuario::getInstance(){
    if (instancia == nullptr) {
        instancia = new MnjUsuario();
    }
    return instancia;
}

std::set<DTUsuario> MnjUsuario::getUsuarios() {
    std::set<DTUsuario> dtus;
    for (auto const& [nickname, u] : this->usuarios) {
        TipoUsuario t = (dynamic_cast<Conductor*>(u) != nullptr)
                            ? TipoUsuario::Conductor
                            : TipoUsuario::Pasajero;
        DTUsuario dtu(u->getNickname(), u->getNombre(), t);
        dtus.insert(dtu);
    }
    return dtus;
}

Usuario* MnjUsuario::getUsuario(std::string nickname) {
    if (usuarios.count(nickname) > 0) {
        return usuarios[nickname];
    }
    return nullptr;
}

std::set<std::string> MnjUsuario::getPasajeros() {
    std::set<std::string> pasajeros;

    for (auto const& [nickname, u] : this->usuarios) {
        Pasajero* p = dynamic_cast<Pasajero*>(u);

        if (p != nullptr) {
            pasajeros.insert(nickname);
        }
    }

    return pasajeros;
}

Usuario* MnjUsuario::registVehiCond(std::string nick, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
   Conductor* u = dynamic_cast<Conductor*>(getUsuario(nick));
    if (u != nullptr) {
        bool libretaOK = false;
        if (tipo == TipoVehiculo::Auto) {
            libretaOK = u->tieneLibreta(AutoProfesional) || u->tieneLibreta(AutoAmateur);
        } else if (tipo == TipoVehiculo::Moto) {
            libretaOK = u->tieneLibreta(MotoProfesional) || u->tieneLibreta(MotoAmateur);
        }
        if (!libretaOK) {
            return nullptr;
        }
        MnjVehiculo* mv = MnjVehiculo::getInstancia();
        Vehiculo* v = mv->nuevoVehiculo(matricula, capacidad, marca, modelo, tipo);
        v->setConductor(u); 
        u->agregarVehiculo(v);
    }
    return u;
}

bool MnjUsuario::tieneReserva(Pasajero* p, Viaje* vi) {
    return p->tieneReserva(vi);
}

void MnjUsuario::agregarReserva(std::string nick, Reserva* r) {
    Pasajero* p = dynamic_cast<Pasajero*>(getUsuario(nick));
    if (p != nullptr) 
        p->addReserva(r);
}

MnjUsuario::~MnjUsuario(){
    std::map<std::string, Usuario*>::iterator it;
    for (it = usuarios.begin(); it != usuarios.end(); ++it) {
        delete it->second;
    }
    usuarios.clear();
    instancia = nullptr;
}


bool MnjUsuario::nuevoConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas){
     if(existeUsuario(nickname)) return false;
     Usuario* c = new Conductor(nickname, nombre, contrasena, email, libretas);
     agregarUsuario(c);
     return true;
}


bool MnjUsuario::nuevoPasajero(std::string nickname,std::string nombre, std::string contrasena, std::string email, std::string ci){
    if (existeUsuario(nickname)) return false;
    Usuario* p = new Pasajero(nickname, nombre, contrasena, email, ci);
    agregarUsuario(p);
    return true;
}


bool MnjUsuario::existeUsuario(std::string nickname){
    return ((usuarios.count(nickname)) > 0);
}


void MnjUsuario :: agregarUsuario(Usuario* u){
    usuarios.insert({u->getNickname(), u});
}
