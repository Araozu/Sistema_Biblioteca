//
// Created by Fernando on 04/06/2020.
//

#include "almacen.h"

Almacen::Almacen(Libro* libros, int cantidadDeLibros) : libros(libros), cantidadDeLibros(cantidadDeLibros) {}

Libro* Almacen::getLibros() const {
    return libros;
}

void Almacen::setLibros(Libro* libros) {
    Almacen::libros = libros;
}

int Almacen::getCantidadDeLibros() const {
    return cantidadDeLibros;
}

void Almacen::setCantidadDeLibros(int cantidadDeLibros) {
    Almacen::cantidadDeLibros = cantidadDeLibros;
}
