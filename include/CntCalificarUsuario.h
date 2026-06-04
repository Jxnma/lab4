#ifndef CNT_CALIFICAR_USUARIO_H
#define CNT_CALIFICAR_USUARIO_H

#include "ICalificarUsuario.h"
#include "DTFecha.h"
#include <string>

class CntCalificarUsuario : public ICalificarUsuario {
private:
    static CntCalificarUsuario* instancia;
    std::string nicknameCalificador;
    int codigoViaje;
    DTFecha fechaActual;

    CntCalificarUsuario();

public:
    static CntCalificarUsuario* getInstance();
    ~CntCalificarUsuario();

    std::set<DTUsuario> listarUsuarios() override;
    std::set<DTListarViaje> listarViajes(std::string nickname) override;
    std::vector<DTUsuarioViaje> listarUsuariosViaje(int codigo) override;
    bool calificarUsuario(std::string nicknameCalificado, int calificacion) override;
};

#endif