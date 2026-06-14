#include "../include/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, std::string nombre, TipoUsuario tipo)
    {
    this->nickname = nickname;
    this->nombre = nombre;
    this->tipo = tipo;
}

std::string DTUsuario::getNickname() const{ return nickname; }
std::string DTUsuario::getNombre() const{ return nombre; }
bool DTUsuario::operator<(const DTUsuario& otro) const {
    if (tipo != otro.tipo) {
        return tipo == TipoUsuario::Conductor;   
    }
    return nickname < otro.nickname;
}
