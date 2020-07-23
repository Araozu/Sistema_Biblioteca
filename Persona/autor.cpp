//
// Created by Fernando on 04/06/2020.
//

#include "autor.h"
#include "../Excepciones/excepcionCsvIncorrecto.h"

Autor::Autor(int id, std::string nombres, std::string apellidos, int dni, int telefono, std::string direccion)
        : Persona(nombres, apellidos, dni, telefono, direccion), id(id) {}

std::string Autor::toCSV() {
    std::stringstream sstream;

    sstream << id << ","
            << nombres << ","
            << apellidos << ","
            << dni << ","
            << telefono << ","
            << direccion;

    return sstream.str();
}

Autor Autor::fromCSV(const std::string &csv) {
    std::string fragmentos[6];
    int n = 0;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            fragmentos[n] += i;
        }
    }

    try {
        int id = std::stoi(fragmentos[0]);
        int dni = std::stoi(fragmentos[3]);
        int telefono = std::stoi(fragmentos[4]);
        Autor a{id, fragmentos[1], fragmentos[2], dni, telefono, fragmentos[5]};
        return a;
    } catch (std::invalid_argument) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Autor. Argumento invalido." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (std::out_of_range) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Autor. Datos fuera de los rangos permitidos." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (...) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Autor." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    }

}

int Autor::getId() const {
    return id;
}
