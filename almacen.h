//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_ALMACEN_H
#define SISTEMABIBLIOTECA_ALMACEN_H
#include "libro.h"

class Almacen {
private:
    Libro* libros;          // Array de libros disponibles.
    int cantidadDeLibros;   // Para poder manejar el array de libros
public:
    Libro* getLibros() const;

    void setLibros(Libro* libros);

    int getCantidadDeLibros() const;

    void setCantidadDeLibros(int cantidadDeLibros);

public:
    Almacen(Libro* libros, int cantidadDeLibros);

};


#endif //SISTEMABIBLIOTECA_ALMACEN_H
