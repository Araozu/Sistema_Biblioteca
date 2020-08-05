//
// Created by Fernando on 04/06/2020.
//

#include "autor.h"
#include "../Excepciones/excepcionCsvIncorrecto.h"

Autor::Autor(int id, std::string nombres, std::string apellidos)
        : Persona(nombres, apellidos), id(id) {}

std::string Autor::toCSV() {
    std::stringstream sstream;

    sstream << id << ","
            << nombres << ","
            << apellidos;

    return sstream.str();
}

Autor Autor::fromCSV(const std::string &csv) {
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
        int id = std::stoi(fragmentos[0]);
        Autor a{id, fragmentos[1], fragmentos[2]};
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

Autor Autor::crearAutorPorConsola(int idAutor) {
    std::cout << "Creando un Autor." << std::endl;

    std::string nombreAutor;
    do {
        std::cout << "Ingresa el nombre del autor:" << std::endl;
        std::getline(std::cin, nombreAutor);

        if (!nombreAutor.empty()) break;

        std::cout << "Por favor, ingresa un nombre.";
    } while (true);

    std::string apellidoAutor;
    do {
        std::cout << "Ingresa el nombre del autor:" << std::endl;
        std::getline(std::cin, apellidoAutor);

        if (!apellidoAutor.empty()) break;

        std::cout << "Por favor, ingresa un apellido.";
    } while (true);

    Autor a(idAutor, nombreAutor, apellidoAutor);
    return a;
}
