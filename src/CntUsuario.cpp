#include "../include/CntUsuario.h"

CntUsuario* CntUsuario::instancia = nullptr;
CntUsuario::CntUsuario() {}

CntUsuario* CntUsuario::getInstance(){
    if (instancia == nullptr) {
        instancia = new CntUsuario();
    }
    return instancia;
}
CntUsuario::~CntUsuario() {}

bool CntUsuario::altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
    MnjUsuario* mu = MnjUsuario::getInstance();                          
    return mu->nuevoPasajero(nickname, nombre, contrasena, email, ci); 
}

bool CntUsuario::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email,std::set<TipoLibreta> libretas) {
    MnjUsuario* mu = MnjUsuario::getInstance();                          
    return mu->nuevoConductor(nickname, nombre, contrasena, email, libretas); 
}

int CntUsuario::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    MnjVehiculo* mv = MnjVehiculo::getInstancia();
    if(mv->existeVehiculo(matricula)) {
        return -1; 
    }
    MnjUsuario* mu = MnjUsuario::getInstance();
    Usuario* u = mu->registVehiCond(nickname, matricula, capacidad, marca, modelo, tipo);
    if (u == nullptr) {
        return -2; 
    }
    return 0;
}