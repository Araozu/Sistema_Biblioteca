//
// Created by Fernando on 04/06/2020.
//

#include <sstream>
#include "libro.h"


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

Libro Libro::crearLibroPorConsola() {
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

    // TODO: En lugar de usar 0 como codigo de autor, habra un metodo
    //       Sistema::buscarAutor el cual busca el autor por consola, y
    //       devuelve su codigo para poder usarse aqui.
    //       Tambien para libro
    Libro l(0, nombreLibro, 0, fechaPublicacion, 0);
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

    for (int i = 0; i < csv.size(); i++) {
        if (csv[i] == ',') {
            n++;
        } else {
            datos[n] += csv[i];
        }
    }
    codigo = atoi(datos[0].c_str());

    // TODO: Usar un menu para obtener el Autor
    // autor = atoi(datos[1].c_str());
    nombre = datos[2];
    fechaPublicacion = datos[3];
    tema = atoi(datos[4].c_str());

    Libro nuevoLibro(codigo, nombre, 0, fechaPublicacion, tema);
    return nuevoLibro;
}




