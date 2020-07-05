//
// Created by Fernando on 04/06/2020.
//

#include "sistema.h"

Sistema::Sistema() {
    // prestamos = Sistema::cargarPrestamos();
}

static std::vector<Libro> Sistema::cargarLibros(){
    ifstream lectura("/data/libros.csv");
    std::vector<Libro> libros;
    std::string line;
    std::getline(lectura,line);
    std::stringstream          lineStream(line);
    std::string cell;
    while(std::getline(lineStream,cell, ','))
    {
        libros.push_back(cell);
    }
    if (!lineStream && cell.empty())
    {
        libros.push_back("");
    }
    return libros;
}

