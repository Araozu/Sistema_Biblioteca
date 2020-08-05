//
// Created by Fernando on 04/06/2020.
//

#include "cliente.h"
#include <sstream>
#include "../Excepciones/excepcionCsvIncorrecto.h"

Cliente::Cliente(const std::string &nombres, const std::string &apellidos, int dni, int telefono,
                 const std::string &direccion) : Persona(nombres, apellidos),
                 direccion(direccion), dni(dni), telefono(telefono) {}

std::string Cliente::toCSV() {
    std::stringstream sstream;

    sstream << nombres << ","
            << apellidos << ","
            << dni << ","
            << telefono << ","
            << direccion;

    return sstream.str();
}

Cliente Cliente::fromCSV(const std::string &csv) {
    std::string fragmentos[5];
    int n = 0;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            fragmentos[n] += i;
        }
    }

    try {
        int dni = std::stoi(fragmentos[2]);
        int telefono = std::stoi(fragmentos[3]);
        Cliente c{fragmentos[0], fragmentos[1], dni, telefono, fragmentos[4]};
        return c;
    } catch (std::invalid_argument) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Cliente. Argumento invalido." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (std::out_of_range) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Cliente. Datos fuera de los rangos permitidos." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (...) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Cliente." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    }
}

Cliente Cliente::crearClientePorConsola() {
    std::cout << "Creando un cliente." << std::endl;

    std::string dniRaw;
    int dni;
    do {
        std::cout << "Ingresa el dni del cliente:" << std::endl;
        std::getline(std::cin, dniRaw);
        try {

            dni = std::stoi(dniRaw);
            break;

        } catch (...) {
            std::cout << "Por favor, ingresa un numero.";
        }

    } while (true);

    std::string nombreCliente;
    do {
        std::cout << "Ingresa el nombre del cliente:" << std::endl;
        std::getline(std::cin, nombreCliente);

        if (!nombreCliente.empty()) break;

        std::cout << "Por favor, ingresa un nombre.";
    } while (true);

    std::string apellidoCliente;
    do {
        std::cout << "Ingresa el apellido del cliente:" << std::endl;
        std::getline(std::cin, apellidoCliente);

        if (!apellidoCliente.empty()) break;

        std::cout << "Por favor, ingresa un apellido.";
    } while (true);

    std::string telefonoRaw;
    int telefono;
    do {
        std::cout << "Ingresa el telefono del cliente:" << std::endl;
        std::getline(std::cin, telefonoRaw);
        try {

            telefono = std::stoi(telefonoRaw);
            break;

        } catch (...) {
            std::cout << "Por favor, ingresa un numero.";
        }

    } while (true);

    std::string direccionCliente;
    do {
        std::cout << "Ingresa la direccion del cliente:" << std::endl;
        std::getline(std::cin, direccionCliente);

        if (!direccionCliente.empty()) break;

        std::cout << "Por favor, ingresa una direccion.";
    } while (true);

    Cliente c(nombreCliente, apellidoCliente, dni, telefono, direccionCliente);
    return c;
}

const std::string &Cliente::getDireccion() const {
    return direccion;
}

void Cliente::setDireccion(const std::string &direccion) {
    Cliente::direccion = direccion;
}

int Cliente::getDni() const {
    return dni;
}

void Cliente::setDni(int dni) {
    Cliente::dni = dni;
}

int Cliente::getTelefono() const {
    return telefono;
}

void Cliente::setTelefono(int telefono) {
    Cliente::telefono = telefono;
}
