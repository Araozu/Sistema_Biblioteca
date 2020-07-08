//
// Created by Fernando on 04/06/2020.
//

#include "sistema.h"

Sistema::Sistema() {
    // prestamos = Sistema::cargarPrestamos();
}

std::vector<Libro> Sistema::cargarLibros() {
    std::ifstream lectora("./data/libros.csv");
    std::vector<Libro> libros;
    std::string linea;

    std::getline(lectora, linea);

    while (!lectora.eof()) {
        getline(lectora, linea);
        Libro l = Libro::fromCSV(linea);
        libros.push_back(l);
    }

    return libros;
}


