#ifndef CNTUSUARIO_H
#define CNTUSUARIO_H
 
#include "IAltaDeUsuario.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include <string>
#include <set>
 
class CntUsuario : public IAltaDeUsuario{
private:
    static CntUsuario* instancia;
    CntUsuario();
 
public:
    static CntUsuario* getInstance();
    ~CntUsuario();
    bool altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) override;
    bool altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libretas) override;
    int registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) override;
};

#endif

