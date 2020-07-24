//
// Created by Fernando on 04/06/2020.
//
#include <sstream>
#include "prestamo.h"
#include <cstdlib>
#include "Excepciones/excepcionCsvIncorrecto.h"

Prestamo::Prestamo(int codigoPrestamo, int codigoLibro, int dniCliente, std::string fechaPrestamo,
                   std::string fechaDevolucion, bool devuelto) :
        codigoPrestamo(codigoPrestamo), codigoLibro(codigoLibro), dniCliente(dniCliente), fechaPrestamo(fechaPrestamo),
        fechaDevolucion(fechaDevolucion), devuelto(devuelto) {
}

int Prestamo::getCodigoLibro() const {
    return codigoLibro;
}

void Prestamo::setCodigoLibro(int codigoLibro) {
    Prestamo::codigoLibro = codigoLibro;
}

int Prestamo::getDniCliente() const {
    return dniCliente;
}

void Prestamo::setDniCliente(int dniCliente) {
    Prestamo::dniCliente = dniCliente;
}

const std::string &Prestamo::getFechaPrestamo() const {
    return fechaPrestamo;
}

void Prestamo::setFechaPrestamo(const std::string &fechaPrestamo) {
    Prestamo::fechaPrestamo = fechaPrestamo;
}

const std::string &Prestamo::getFechaDevolucion() const {
    return fechaDevolucion;
}

void Prestamo::setFechaDevolucion(const std::string &fechaDevolucion) {
    Prestamo::fechaDevolucion = fechaDevolucion;
}

bool Prestamo::isDevuelto() const {
    return devuelto;
}

std::string Prestamo::toCSV() {
    std::string csv;
    std::stringstream gstream;

    gstream << getCodigoPrestamo() << ","
            << getCodigoLibro() << ","
            << getDniCliente() << ","
            << fechaPrestamo << ","
            << fechaDevolucion << ","
            << isDevuelto();

    csv = gstream.str();
    return csv;
}

Prestamo Prestamo::fromCSV(std::string csv) {
    std::string datos[6];
    int codigoPrestamo, codigoLibro, dni, n = 0;
    bool devuelto = false;
    std::string fechaPrestamo, fechaDevolucion;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            datos[n] += i;
        }
    }

    try {
        codigoPrestamo = std::stoi(datos[0]);
        codigoLibro = std::stoi(datos[1]);
        dni = std::stoi(datos[2]);
        fechaPrestamo = datos[3];
        fechaDevolucion = datos[4];
        if (std::stoi(datos[5]) == 1) devuelto = true;

        Prestamo nuevoPrestamo(codigoPrestamo, codigoLibro, dni, fechaPrestamo, fechaDevolucion, devuelto);
        return nuevoPrestamo;
    } catch (std::invalid_argument) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Prestamo. Argumento invalido." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (std::out_of_range) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Prestamo. Datos fuera de los rangos permitidos." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (...) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Prestamo." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    }

}

int Prestamo::getCodigoPrestamo() const {
    return codigoPrestamo;
}

void Prestamo::setCodigoPrestamo(int codigoPrestamo) {
    Prestamo::codigoPrestamo = codigoPrestamo;
}

void Prestamo::setDevuelto(bool devuelto) {
    Prestamo::devuelto = devuelto;
}

