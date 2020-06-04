//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_PRESTAMO_H
#define SISTEMABIBLIOTECA_PRESTAMO_H
#include <iostream>

class Prestamo {
private:
    int codigoLibro;
    int dniCliente;
    std::string fechaPrestamo;
    std::string fechaDevolucion;
    bool devuelto;

};


#endif //SISTEMABIBLIOTECA_PRESTAMO_H
