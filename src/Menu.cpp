#include "../include/Menu.h"
#include "../include/Fabrica.h"
#include "../include/IControladorFechaActual.h"
#include "../include/ICalificarUsuario.h"
#include "../include/DTListarViaje.h"
#include "../include/IAltaDeUsuario.h"
#include "../include/CargaDatos.h"
#include "../include/DTFecha.h"
#include "../include/TipoLibreta.h"
#include "../include/TipoVehiculo.h"
#include "../include/IGenerarReserva.h"
#include "../include/DTConsultaViaje.h"
#include <iostream>
#include <limits>
#include <string>

void Menu::altaUsuario() {
    int tipoUsuario;
    std::cout << "1. Alta Pasajero\n";
    std::cout << "2. Alta Conductor\n";
    std::cout << "Seleccione: ";
    std::cin >> tipoUsuario;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipoUsuario != 1 && tipoUsuario != 2) {
        std::cout << "Opcion invalida.\n";
        return;
    }

    std::string nickname, nombre, contrasena, email;
    std::cout << "Ingrese nickname: "; std::getline(std::cin, nickname);
    std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
    std::cout << "Ingrese contrasena: "; std::getline(std::cin, contrasena);
    std::cout << "Ingrese email: "; std::getline(std::cin, email);

    Fabrica* fabrica = Fabrica::getInstance();
    IAltaDeUsuario* controlador = fabrica->getIAltaDeUsuario();
    
    bool usuarioOk = false;


    if (tipoUsuario == 1) {
        std::string ci;
        std::cout << "Ingrese CI: "; std::getline(std::cin, ci);
        usuarioOk = controlador->altaPasajero(nickname, nombre, contrasena, email, ci);
    }  else if (tipoUsuario == 2) {
    std::set<TipoLibreta> libretas;
    int lib;
    int continuar = 1;
    while (continuar == 1) {
        std::cout << "=== Registrar Libreta ===\n";
        std::cout << "0. Moto (Profesional)\n";
        std::cout << "1. Moto (Amateur)\n";
        std::cout << "2. Auto (Profesional)\n";
        std::cout << "3. Auto (Amateur)\n";
        std::cout << "Seleccione el tipo de libreta: ";
        std::cin >> lib;
        libretas.insert((TipoLibreta)lib);
        std::cout << "Libreta agregada.\n";
        std::cout << "¿Desea agregar otra libreta? (1: Si, 0: No): ";
        std::cin >> continuar;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    usuarioOk = controlador->altaConductor(nickname, nombre, contrasena, email, libretas);
    int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1) {
            std::string matricula, marca, modelo;
            int capacidad, tipo;
            std::cout << "\n=== Registrar Vehiculo ===\n";
            std::cout << "Ingrese matricula: "; std::getline(std::cin, matricula);
            std::cout << "Ingrese capacidad: "; std::cin >> capacidad;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese marca: "; std::getline(std::cin, marca);
            std::cout << "Ingrese modelo: "; std::getline(std::cin, modelo);
            std::cout << "Ingrese tipo (0: Auto, 1: Moto): "; std::cin >> tipo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int resultadoRegistrarVehiculo = -3;
            TipoVehiculo tipoVehiculo = (tipo == 0) ? Auto : Moto;
            resultadoRegistrarVehiculo = controlador->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, tipoVehiculo);
            if (resultadoRegistrarVehiculo == -1) {
                std::cout << "Ya existe un vehiculo con esa matricula.\n";
            } else if (resultadoRegistrarVehiculo == -2) {
                std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            } else if (resultadoRegistrarVehiculo == 0) {
                std::cout << "Vehiculo registrado exitosamente.\n";
            }
            std::cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            std::cin >> agregarVehiculo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::altaViaje() {
    std::string nickname, matricula, origen, destino;
    int dia, mes, anio, asientos;
    float precio;
    Fabrica* fabrica = Fabrica::getInstance();
    IAltaViaje* controlador = fabrica->getIAltaViaje();

    std::cout << "Ingrese nickname del conductor: "; std::getline(std::cin, nickname);
    std::set<DTVehiculosConductor> vehiculos = controlador->listarVehiculosConductor(nickname);

    for (DTVehiculosConductor v : vehiculos) {
        std::cout << "> Matricula: " << v.getMatricula()
                  << ", Capacidad: " << v.getCapacidad()
                  << ", Modelo: " << v.getModelo() << "\n";
    }

    std::cout << "Ingrese matricula del vehiculo a utilizar: "; std::getline(std::cin, matricula);
    bool matriculaValida = false;
    for (DTVehiculosConductor v : vehiculos) {
        if (v.getMatricula() == matricula) {
            matriculaValida = true;
            break;
        }
    }  
    if (!matriculaValida) {
        std::cout << "Matricula invalida.\n";
        return;
    }

    std::cout << "Ingrese fecha del viaje (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos: "; std::cin >> asientos;
    std::cout << "Ingrese precio por asiento: "; std::cin >> precio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool viajeOk = false;
    viajeOk = controlador->altaViaje(matricula, DTFecha(dia, mes, anio), origen, destino, asientos, precio);
    if (viajeOk) {
        std::cout << "Viaje registrado exitosamente.\n";
    } else {
        std::cout << "Error al registrar el viaje.\n";
    }
}

void Menu::generarReserva() {
    Fabrica* fabrica = Fabrica::getInstance();
    IGenerarReserva* controlador = fabrica->getIGenerarReserva();
    
    std::set<std::string> pasajeros = controlador->listarPasajeros();
    for (const std::string& p : pasajeros) {
        std::cout << "> " << p << "\n";
    }
    if (pasajeros.empty()) {
        std::cout << "No hay pasajeros registrados.\n";
        return;
    }

    std::string nickname;
    std::cout << "Ingrese nickname del pasajero: "; std::getline(std::cin, nickname);

    bool nicknameValido = false;
    for (const std::string& p : pasajeros) {
        if (p == nickname) {
            nicknameValido = true;
            break;
        }
    }
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    int dia, mes, anio, asientos;
    std::string origen, destino;
    std::cout << "Ingrese fecha del viaje a consultar (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos a reservar: "; std::cin >> asientos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::set<DTConsultaViaje> viajes = controlador->consultarViajes(
    DTFecha(dia, mes, anio),
    origen,
    destino,
    asientos
    );

    for (DTConsultaViaje v : viajes) {
        std::cout << "> Codigo: " << v.getCodigo()
              << ", Marca: " << v.getMarca()
              << ", Modelo: " << v.getModelo()
              << ", Conductor: " << v.getConductor()
              << ", CalificacionPromedio: " << v.getCalificacionProm()
              << ", PrecioTotal: " << v.getPrecioTotal()
              << "\n";
    }
    bool hayViajes = !viajes.empty();
    if (!hayViajes) {
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a reservar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    for (DTConsultaViaje v : viajes) {
        if (v.getCodigo() == codigo) {
            codigoValido = true;
            break;
        }
    }
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    bool reservaOk = false;
    reservaOk = controlador->generarReserva(nickname, codigo, asientos);
    if (reservaOk) {
        std::cout << "Reserva realizada exitosamente.\n";
    } else {
        std::cout << "Error al realizar la reserva.\n";
    }
}

void Menu::calificarUsuario() {
    
    
    Fabrica* fabrica = Fabrica::getInstance();
    ICalificarUsuario* controlador = fabrica->getICalificarUsuario();
    std::set<DTUsuario> usuarios = controlador->listarUsuarios();

    std::cout << "\n Listado de Usuarios \n";
    for (const DTUsuario& u : usuarios) {
        std::cout << "> Nickname: " << u.getNickname() << ", Nombre: " << u.getNombre() << "\n";
    }
    std::cout << "---------------------------\n";

    std::string nickname;
    std::cout << "Ingrese su nickname: "; std::getline(std::cin, nickname);
    bool nicknameValido = false;

    for (const DTUsuario& u : usuarios) {
        if (u.getNickname() == nickname) {
            nicknameValido = true;
            break;
        }
    }

    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    std::set<DTListarViaje> viajes = controlador->listarViajes(nickname);

    std::cout << "\n--- Viajes asociados a " << nickname << " ---\n";
    for (DTListarViaje v : viajes) {
        
        std::cout << "> Codigo: " << v.getCodigo() 
                  << ", Fecha: " << v.getFecha()
                  << ", Origen: " << v.getOrigen() 
                  << ", Destino: " << v.getDestino() 
                  << ", Conductor: " << v.getConductor() << "\n";
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool codigoValido = false;
    for (DTListarViaje v : viajes) {
        if (v.getCodigo() == codigo) {
            codigoValido = true;
            break;
        }
    }
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }
    //listarUsuariosViaje
    std::vector<DTUsuarioViaje> participantes = controlador->listarUsuariosViaje(codigo);
    std::cout << "\n--- Participantes del viaje ---\n";
    for (const DTUsuarioViaje& p : participantes) {
        std::cout << "> Nickname: " << p.getNickname() << ", Tipo: " << (p.getTipo() == TipoUsuario::Pasajero ? "Pasajero" : "Conductor") << "\n";
    }
    std::string nicknameCalificado;
    std::cout << "Ingrese nickname del usuario a calificar: "; std::getline(std::cin, nicknameCalificado);
    bool nicknameCalificadoValido = false;
    for (const DTUsuarioViaje& p : participantes) {
    if (p.getNickname() == nicknameCalificado) {
        nicknameCalificadoValido = true;
        break;
        }
    }
    if (!nicknameCalificadoValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }
    //calificarUsuario
    int calificacion;
    std::cout << "Ingrese calificacion (1-5): "; std::cin >> calificacion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool calificacionOk = false;
    calificacionOk = controlador->calificarUsuario(nicknameCalificado, calificacion);
    if (calificacionOk) {
        std::cout << "Calificacion exitosa.\n";
    } else {
        std::cout << "Error al calificar.\n";
    }
}

void Menu::eliminarViaje() {
    Fabrica* fabrica = Fabrica::getInstance();
    IEliminarViaje* controlador = fabrica->getIEliminarViaje();
    std::vector<DTListarViaje> viajes = controlador->listarViajes();

    for (DTListarViaje v : viajes) {
        std::cout << "> Codigo: " << v.getCodigo() 
                  << ", Fecha: " << v.getFecha() 
                  << ", Origen: " << v.getOrigen() 
                  << ", Destino: " << v.getDestino()
                  << ", Conductor: " << v.getConductor() << "\n";
    }
    int codigo;
    std::cout << "Ingrese codigo del viaje a eliminar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    for (DTListarViaje v : viajes) {
        if (v.getCodigo() == codigo) {
            codigoValido = true;
            break;
        }
    }
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    DTDetalleViaje* DTViaje= controlador->detalleViaje(codigo);
    
    std::cout << ">> Viaje <<\n";
    std::cout << "--- Matricula: " << DTViaje->getCodigo()
              << ", Fecha: " << DTViaje->getFecha()
              << ", Origen: " << DTViaje->getOrigen()
              << ", Destino: " << DTViaje->getDestino()
              << ", Capacidad: " << DTViaje->getAsientosPublicados()
              << ", Precio por asiento: " << DTViaje->getPrecio() << "\n";
    DTDetalleVehiculo DTVehiculo = DTViaje->getVehiculo();
    std::cout << ">> Vehiculo <<";
    std::cout << "--- Matricula: " << DTVehiculo.getMatricula()
              << ", Capacidad: " << DTVehiculo.getCapacidad()
              << ", Marca: " << DTVehiculo.getMarca()
              << ", Modelo: " << DTVehiculo.getModelo()
              << ", Tipo: " << (DTVehiculo.getTipo() == Auto ? "Auto" : "Moto") << "\n";
    
     std::cout << ">> Reservas <<\n";
     for (DTDetalleReserva r : DTViaje->getReservas()) {
        std::cout << "---AsientosReservados: " << r.getAsientosReservados()
                  << ", Fecha: " << r.getFecha()
                  << ", Pasajero: " << r.getPasajero() << "\n";
     }
     delete DTViaje;
    
    int confirmar;
    std::cout << "¿Confirmar eliminacion? (1: Si, 0: No): "; std::cin >> confirmar;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirmar == 1) {
        controlador->eliminarViaje();
        std::cout << "Viaje eliminado exitosamente.\n";
    } else {
        controlador->cancelarEliminarViaje();
        std::cout << "Eliminacion cancelada.\n";
    }
}

void Menu::administrarFechaActual() {
    int opFecha;
    std::cout << "1. Ver fecha actual\n";
    std::cout << "2. Modificar fecha actual\n";
    std::cout << "Seleccione: ";
    std::cin >> opFecha;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorFechaActual* controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1) {
        DTFecha fecha = controladorFecha->getFecha();
        std::cout << "Fecha actual: " << fecha << "\n";
    } else if (opFecha == 2) {
        int dia, mes, anio;
        std::cout << "Ingrese dia: "; std::cin >> dia;
        std::cout << "Ingrese mes: "; std::cin >> mes;
        std::cout << "Ingrese anio: "; std::cin >> anio;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        std::cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    } else {
        std::cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos() {
    CargaDatos::getInstance()->cargarDatos();
}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 8) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Alta de Usuario\n";
        std::cout << "2. Alta de Viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar Usuario\n";
        std::cout << "5. Eliminar Viaje\n";
        std::cout << "6. Administrar Fecha Actual\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "8. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                altaUsuario();
                break;
            case 2:
                altaViaje();
                break;
            case 3:
                generarReserva();
                break;
            case 4:
                calificarUsuario();
                break;
            case 5:
                eliminarViaje();
                break;
            case 6:
                administrarFechaActual();
                break;
            case 7:
                cargarDatos();
                break;
            case 8:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
}
