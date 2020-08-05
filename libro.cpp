//
// Created by Fernando on 04/06/2020.
//

#include <sstream>
#include "libro.h"
#include "Excepciones/excepcionCsvIncorrecto.h"

Libro::Libro(int codigo, std::string nombre, int autor, std::string fechaPublicacion, int codigoCat) :
        codigo(codigo), nombre(nombre), codigoAutor(autor), fechaPublicacion(fechaPublicacion),
        codigoCategoria(codigoCat) {}

int Libro::getCodigo() const {
    return codigo;
}

void Libro::setCodigo(int codigo) {
    Libro::codigo = codigo;
}

std::string Libro::getNombre() const {
    return nombre;
}

void Libro::setNombre(std::string nombre) {
    Libro::nombre = nombre;
}

int Libro::getCodigoAutor() const {
    return codigoAutor;
}

void Libro::setCodigoAutor(int codigoAutor) {
    Libro::codigoAutor = codigoAutor;
}

std::string Libro::getFechaPublicacion() const {
    return fechaPublicacion;
}

void Libro::setFechaPulicacion(std::string fechaPublicacion) {
    Libro::fechaPublicacion = fechaPublicacion;
}

void Libro::setFechaPublicacion(const std::string &fechaPublicacion) {
    Libro::fechaPublicacion = fechaPublicacion;
}

int Libro::getCodigoCategoria() const {
    return codigoCategoria;
}

void Libro::setCodigoCategoria(int codigoCategoria) {
    Libro::codigoCategoria = codigoCategoria;
}

Libro Libro::crearLibroPorConsola(int codLibro) {
    std::cout << "Creando un Libro." << std::endl;

    std::string nombreLibro;
    do {
        std::cout << "Ingresa el nombre del libro:" << std::endl;
        std::getline(std::cin, nombreLibro);

        if (!nombreLibro.empty()) break;

        std::cout << "Por favor, ingresa un nombre.";
    } while (true);

    std::string fechaPublicacion;
    do {
        std::cout << "Ingresa la fecha de publicacion del libro:" << std::endl;
        std::getline(std::cin, fechaPublicacion);

        if (!fechaPublicacion.empty()) break;

        std::cout << "Por favor, ingresa una fecha.";
    } while (true);

    std::string codAutorRaw;
    int codAutor;
    do {
        std::cout << "Ingresa el codigo del autor:" << std::endl;
        std::getline(std::cin, codAutorRaw);
        try {

            codAutor = std::stoi(codAutorRaw);
            break;

        } catch (...) {
            std::cout << "Por favor, ingresa un numero.";
        }

    } while (true);

    std::string codCatRaw;
    int codCat;
    do {
        std::cout << "Ingresa el codigo de la categoria:" << std::endl;
        std::getline(std::cin, codCatRaw);
        try {

            codCat = std::stoi(codCatRaw);
            break;

        } catch (...) {
            std::cout << "Por favor, ingresa un numero.";
        }

    } while (true);

    Libro l(codLibro, nombreLibro, codAutor, fechaPublicacion, codCat);
    return l;
}

std::string Libro::toCSV() {
    std::string csv;
    std::stringstream gstream;

    gstream << getCodigo() << ",";
    gstream << nombre << ",";
    gstream << codigoAutor << ",";
    gstream << fechaPublicacion << ",";
    gstream << codigoAutor;
    csv = gstream.str();
    return csv;
}

Libro Libro::fromCSV(std::string csv) {
    std::string datos[5];
    int codigo, tema, n = 0;

    std::string nombre, fechaPublicacion, aux;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            datos[n] += i;
        }
    }

    try {
        codigo = std::stoi(datos[0]);
        nombre = datos[1];
        int idAutor = std::stoi(datos[2]);
        fechaPublicacion = datos[3];
        tema = std::stoi(datos[4]);

        Libro nuevoLibro(codigo, nombre, idAutor, fechaPublicacion, tema);
        return nuevoLibro;
    } catch (std::invalid_argument &) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Libro. Argumento invalido." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (std::out_of_range &) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Libro. Datos fuera de los rangos permitidos." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (...) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Libro." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    }
}
