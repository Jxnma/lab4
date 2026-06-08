#include "../include/CntCalificarUsuario.h"
#include "../include/MnjViaje.h"
#include "../include/MnjUsuario.h"
#include "../include/Viaje.h"

CntCalificarUsuario* CntCalificarUsuario::instancia = nullptr;

CntCalificarUsuario::CntCalificarUsuario() {
    this->codigoViaje = -1;
    this->nicknameCalificador = "";
}

CntCalificarUsuario* CntCalificarUsuario::getInstance() {
    if (instancia == nullptr) {
        instancia = new CntCalificarUsuario();
    }
    return instancia;
}

CntCalificarUsuario::~CntCalificarUsuario() {}

std::set<DTUsuario> CntCalificarUsuario::listarUsuarios(){
    MnjUsuario* m = MnjUsuario::getInstance();
    std::set<DTUsuario> dtus = m->getUsuarios();
    return dtus;
}

std::vector<DTUsuarioViaje> CntCalificarUsuario::listarUsuariosViaje(int codigo) {
    // se guarda en memoria
    this->codigoViaje = codigo;

    MnjViaje* m = MnjViaje::getInstance();

    Viaje* vi = m->getViaje(codigo);

    return vi->getParticipantes(this->nicknameCalificador);
}