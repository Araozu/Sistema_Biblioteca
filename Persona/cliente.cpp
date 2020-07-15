//
// Created by Fernando on 04/06/2020.
//

#include "cliente.h"
#include <sstream>
#include "../Excepciones/excepcionCsvIncorrecto.h"

Cliente::Cliente(const std::string &nombres, const std::string &apellidos, int dni, int telefono,
                 const std::string &direccion) : Persona(nombres, apellidos, dni, telefono, direccion) {}

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
