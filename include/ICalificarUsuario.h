#ifndef ICALIFICAR_USUARIO_H
#define ICALIFICAR_USUARIO_H

#include "DTUsuario.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include <vector>
#include <set>
#include <string>

class ICalificarUsuario {
public:
    virtual ~ICalificarUsuario() {}
    virtual std::set<DTUsuario> listarUsuarios() = 0;
    virtual std::set<DTListarViaje> listarViajes(std::string nickname) = 0;
    virtual std::vector<DTUsuarioViaje> listarUsuariosViaje(int codigo) = 0;
    virtual bool calificarUsuario(std::string nicknameCalificado, int calificacion) = 0;
};

#endif