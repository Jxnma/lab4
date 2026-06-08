#include "../include/CntUsuario.h"
#include "../include/MnjUsuario.h"

CntUsuario* CntUsuario::instancia = nullptr;

CntUsuario* CntUsuario::getInstance(){
    if (instancia == nullptr) {
        instancia = new CntUsuario();
    }
    return instancia;
}

bool CntUsuario::altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
    MnjUsuario* mu = MnjUsuario::getInstance();                          
    return mu->nuevoPasajero(nickname, nombre, contrasena, email, ci); 
}

bool CntUsuario::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email,std::set<TipoLibreta> libretas) {
    MnjUsuario* mu = MnjUsuario::getInstance();                          
    return mu->nuevoConductor(nickname, nombre, contrasena, email, libretas); 
}

