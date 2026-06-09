#include "../include/CntCalificarUsuario.h"
#include "../include/MnjViaje.h"
#include "../include/MnjUsuario.h"
#include "../include/Viaje.h"
#include "../include/Usuario.h"
#include "../include/ControladorFechaActual.h"

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

std::set<DTListarViaje> CntCalificarUsuario::listarViajes(std::string nickname){
    this->nicknameCalificador = nickname;
    MnjUsuario* m = MnjUsuario::getInstance();
    Usuario* us = m->getUsuario(nickname); 
    std::set<DTListarViaje> dtvis = us->getViajes();
    return dtvis;
}

std::vector<DTUsuarioViaje> CntCalificarUsuario::listarUsuariosViaje(int codigo) {
    // se guarda en memoria
    this->codigoViaje = codigo;

    MnjViaje* m = MnjViaje::getInstance();

    Viaje* vi = m->getViaje(codigo);

    return vi->getParticipantes(this->nicknameCalificador);
}
bool CntCalificarUsuario::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    MnjUsuario* m = MnjUsuario::getInstance();

    Usuario* uCal = m->getUsuario(this->nicknameCalificador);
    Usuario* uCalificado = m->getUsuario(nicknameCalificado);

    // 4. verificar si ya existe calificacion
    bool existe = uCal->existeCalificacion(uCalificado, this->codigoViaje);

    if (existe) {
        // liberar memoria y retornar false
        this->nicknameCalificador = "";
        this->codigoViaje = -1;
        return false;
    }

    DTFecha fecha = ControladorFechaActual::getInstance()->getFecha();

    // 5. crear calificacion
    bool resultado = uCal->crearCalificacion(uCalificado, this->codigoViaje, calificacion, fecha);

    this->nicknameCalificador = "";
    this->codigoViaje = -1;

    return resultado;
}