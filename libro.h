//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_LIBRO_H
#define SISTEMABIBLIOTECA_LIBRO_H
#include <iostream>
#include "Persona/autor.h"

class Libro {
private:
    int codigo;
    std::string nombre;
    int codigoAutor;
    std::string fechaPublicacion;  // TODO: Cambiar a un objeto
    int codigoCategoria;  // Biologia/Matematica/etc

public:
    Libro(int codigo, std::string nombre, int autor, std::string fechaPublicacion, int codigoCat);

    int getCodigoAutor() const;

    void setCodigoAutor(int codigoAutor);

    int getCodigo() const;

    void setCodigo(int codigo);

    std::string getNombre() const;

    void setNombre(std::string nombre);

    std::string getFechaPublicacion() const;

    void setFechaPulicacion(std::string fechaPublicacion);

    void setFechaPublicacion(const std::string &fechaPublicacion);

    int getCodigoCategoria() const;

    void setCodigoCategoria(int codigoCategoria);

    static Libro crearLibroPorConsola();

    std::string toCSV();

    static Libro fromCSV(std::string csv);
};


#endif //SISTEMABIBLIOTECA_LIBRO_H
