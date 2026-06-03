#ifndef MNJVEHICULO_H
#define MNJVEHICULO_H
#include "Vehiculo.h"
#include <string>
#include <map>
class MnjVehiculo {
    private:
        static MnjVehiculo* instancia;
        std::map<std::string, Vehiculo*> vehiculos;
        MnjVehiculo();
    public:
        static MnjVehiculo* getInstancia();
        ~MnjVehiculo();
        void agregarVehiculo(Vehiculo* v);
        Vehiculo* getVehiculo(std::string matricula);
        bool existeVehiculo(std::string matricula);
        Vehiculo* nuevoVehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);     
};
#endif
