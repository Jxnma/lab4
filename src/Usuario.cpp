#include "../include/Usuario.h"
#include "../include/Calificacion.h"
#include "../include/Reserva.h"
#include "../include/Pasajero.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

Usuario::~Usuario() {}

std::string Usuario::getNickname() const {
    return nickname;
}

std::string Usuario::getNombre() {
    return nombre;
}

void Usuario::addCalificacionRecibida(Calificacion* c) {
    calificacionesRecibidas.insert(c);
}

bool Usuario::existeCalificacion(Usuario* uCalificado, int codVi) {
    for (Calificacion* c : calificacionesRealizadas) {
        if (c->calificaA(uCalificado, codVi)) return true;
    }
    return false;
}
void Usuario::addRealiza(Calificacion* c) {
    calificacionesRealizadas.insert(c);
}
// paso 5 del diagrama de comunicacion calificarUsuario
bool Usuario::crearCalificacion(Usuario* uCalificado, int codigoViaje, int cal, DTFecha fecha) {
    Calificacion* c = new Calificacion(fecha, cal);
    this->addRealiza(c);
    c->addCalifica(uCalificado);
    uCalificado->addCalificacionRecibida(c);

    // 5.4a si calificador es pasajero, busca su propia reserva
    Reserva* r = nullptr;
    Pasajero* calificadorPasajero = dynamic_cast<Pasajero*>(this);
    if (calificadorPasajero != nullptr) {
        r = calificadorPasajero->getReserva(codigoViaje);
    } else {
        // 5.4b si calificador es conductor, busca reserva del calificado
        Pasajero* calificadoPasajero = dynamic_cast<Pasajero*>(uCalificado);
        if (calificadoPasajero != nullptr) {
            r = calificadoPasajero->getReserva(codigoViaje);
        }
    }

    c->addSobreReserva(r);
    return true;
}

float Usuario::getCalificacionPromedio() {
    if (this->calificacionesRecibidas.empty()) {
        return 0;
    }

    int suma = 0;

    for (Calificacion* c : this->calificacionesRecibidas) {
        suma += c->getPuntaje();
    }

    return (float)suma / this->calificacionesRecibidas.size();
}