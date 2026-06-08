#include "../include/MnjUsuario.h"
#include "../include/Conductor.h"
#include "../include/Pasajero.h"

MnjUsuario* MnjUsuario::instancia = nullptr;
MnjUsuario :: MnjUsuario(){}

MnjUsuario* MnjUsuario::getInstance(){
    if (instancia == nullptr) {
        instancia = new MnjUsuario();
    }
    return instancia;
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

std::set<DTUsuario> MnjUsuario::getUsuarios() {
    std::set<DTUsuario> dtus;
    for (auto const& [nickname, u] : this->usuarios) {
        DTUsuario dtu(u->getNickname(), u->getNombre());
        dtus.insert(dtu);
    }
    return dtus;
}