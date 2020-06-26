//
// Created by Fernando on 04/06/2020.
//

#include "prestamo.h"

Prestamo::Prestamo(int _codigoLibro, int _dniCliente, std::string _fechaPrestamo, std::string _fechaDevolucion) {
    codigoLibro = _codigoLibro;
    dniCliente = _dniCliente;
    fechaPrestamo = _fechaPrestamo;
    fechaDevolucion = _fechaDevolucion;
    devuelto = false;
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

std::string Prestamo::toCSV() const{
    std::string csv;
    csv=std::to_string(getCodigoLibro())+","+std::to_string(getDniCliente())+","+std::to_string(getFechaPrestamo())+","+std::to_string(getFechaDevolucion)+","+isDevuelto();
    return csv
}
    
static Prestamo Prestamo::fromCSV(std::string csv){
}
