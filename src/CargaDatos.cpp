#include "../include/CargaDatos.h"
#include "../include/Fabrica.h"
#include "../include/IAltaDeUsuario.h"
#include "../include/IAltaViaje.h"
#include "../include/IGenerarReserva.h"
#include "../include/ICalificarUsuario.h"
#include "../include/DTFecha.h"
#include "../include/TipoLibreta.h"
#include "../include/TipoVehiculo.h"
#include <iostream>
#include <set>

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }
    
    // Aquí iría la lógica de carga de datos harcodeados
    std::cout << "Cargando datos harcodeados del sistema...\n";
    // ... (inserción de usuarios, vehículos, viajes, reservas) ...
    Fabrica* f = Fabrica::getInstance();
    IAltaDeUsuario* cntUsuario = f->getIAltaDeUsuario();
    IAltaViaje* cntViaje = f->getIAltaViaje();
    IGenerarReserva* cntReserva = f->getIGenerarReserva();
    ICalificarUsuario* cntCalificar = f->getICalificarUsuario();

    cntUsuario->altaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", {AutoAmateur});
    cntUsuario->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", {AutoProfesional});
    cntUsuario->altaConductor("greg_m", "Diego Rodriguez", "drodriguez88", "diegorodriguez@fing.edu.uy", {MotoAmateur});
    cntUsuario->altaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", {MotoProfesional});
    cntUsuario->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", {AutoProfesional, MotoAmateur});

    cntUsuario->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "1.492.304-2");
    cntUsuario->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto0", "mari.barreto@outlook.com", "4.103.859-1");
    cntUsuario->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "3.847.112-5");
    cntUsuario->altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "2.956.403-0");
    cntUsuario->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "5.021.784-3");

    cntUsuario->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", Auto);
    cntUsuario->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", Auto);
    cntUsuario->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", Auto);
    cntUsuario->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", Auto);
    cntUsuario->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twist", Moto);
    cntUsuario->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", Moto);
    cntUsuario->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", Auto);
    cntUsuario->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", Moto);

    cntViaje->altaViaje("ABJ4586", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 200);
    cntViaje->altaViaje("ACM4455", DTFecha(20, 10, 2026), "young", "montevideo", 5, 250);
    cntViaje->altaViaje("BAS7895", DTFecha(20, 10, 2026), "young", "montevideo", 4, 200);
    cntViaje->altaViaje("BCS4105", DTFecha(21, 10, 2026), "montevideo", "mercedes", 9, 200);
    cntViaje->altaViaje("LDA4875", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 300);
    cntViaje->altaViaje("PDB1205", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 350);
    cntViaje->altaViaje("SBJ4874", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 260);
    cntViaje->altaViaje("SCF2469", DTFecha(20, 10, 2026), "montevideo", "cerro chato", 1, 150);
    cntViaje->altaViaje("ABJ4586", DTFecha(15, 3, 2026), "montevideo", "colonia", 4, 140);
    cntViaje->altaViaje("BCS4105", DTFecha(15, 3, 2026), "montevideo", "colonia", 9, 180);
    cntViaje->altaViaje("SBJ4874", DTFecha(15, 3, 2026), "montevideo", "colonia", 1, 100);
    cntViaje->altaViaje("SBJ4874", DTFecha(14, 3, 2026), "montevideo", "colonia", 4, 600);
    cntViaje->altaViaje("LDA4875", DTFecha(20, 10, 2026), "young", "montevideo", 1, 250);

    // viaje 9: ABJ4586, 15/3/2026
    cntReserva->generarReserva("santi_90", 9, 2);
    cntReserva->generarReserva("mari_b", 9, 1);
    // viaje 10: BCS4105, 15/3/2026
    cntReserva->generarReserva("nacho_f", 10, 5);
    cntReserva->generarReserva("valen_uy", 10, 3);
    cntReserva->generarReserva("joaco_r", 10, 1);
    // viaje 12: SBJ4874, 14/3/2026
    cntReserva->generarReserva("mari_b", 12, 1);
    cntReserva->generarReserva("nacho_f", 12, 1);
    // viaje 1: ABJ4586, 21/10/2026
    cntReserva->generarReserva("mari_b", 1, 2);
    // viaje 9 de nuevo
    cntReserva->generarReserva("nacho_f", 9, 1);

    // santi_90 califica a matil92 en viaje 9
    cntCalificar->listarUsuarios();
    cntCalificar->listarViajes("santi_90");
    cntCalificar->listarUsuariosViaje(9);
    cntCalificar->calificarUsuario("matil92", 4);

    // mari_b califica a matil92 en viaje 9
    cntCalificar->listarUsuarios();
    cntCalificar->listarViajes("mari_b");
    cntCalificar->listarUsuariosViaje(9);
    cntCalificar->calificarUsuario("matil92", 4);

    // matil92 califica a mari_b en viaje 9
    cntCalificar->listarUsuarios();
    cntCalificar->listarViajes("matil92");
    cntCalificar->listarUsuariosViaje(9);
    cntCalificar->calificarUsuario("mari_b", 3);

    // ana_silva califica a valen_uy en viaje 10
    cntCalificar->listarUsuarios();
    cntCalificar->listarViajes("ana_silva");
    cntCalificar->listarUsuariosViaje(10);
    cntCalificar->calificarUsuario("valen_uy", 5);

    // ana_silva califica a joaco_r en viaje 10
    cntCalificar->listarUsuarios();
    cntCalificar->listarViajes("ana_silva");
    cntCalificar->listarUsuariosViaje(10);
    cntCalificar->calificarUsuario("joaco_r", 5);

    // mari_b califica a carlos_r en viaje 12
    cntCalificar->listarUsuarios();
    cntCalificar->listarViajes("mari_b");
    cntCalificar->listarUsuariosViaje(12);
    cntCalificar->calificarUsuario("carlos_r", 5);

    // carlos_r califica a nacho_f en viaje 12
    cntCalificar->listarUsuarios();
    cntCalificar->listarViajes("carlos_r");
    cntCalificar->listarUsuariosViaje(12);
    cntCalificar->calificarUsuario("nacho_f", 5);

    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
