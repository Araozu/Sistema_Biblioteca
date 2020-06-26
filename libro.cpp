//
// Created by Fernando on 04/06/2020.
//

#include <sstream>
#include "libro.h"


Libro::Libro(int codigo, std::string nombre, Autor autor, std::string fechaPublicacion, std::string tema) :
        codigo(codigo), nombre(nombre), autor(autor), fechaPublicacion(fechaPublicacion), tema(tema) {}

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

Autor Libro::getAutor() const {
    return autor;
}

void Libro::setAutor(Autor autor) {
    Libro::autor = autor;
}

std::string Libro::getFechaPublicacion() const {
    return fechaPublicacion;
}

void Libro::setFechaPulicacion(std::string fechaPublicacion) {
    Libro::fechaPublicacion = fechaPublicacion;
}

std::string Libro::getTema() const {
    return tema;
}

void Libro::setTema(std::string tema) {
    Libro::tema = tema;
}

// TODO: Usar un Autor apropiado para crear el objeto.
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

    std::string tema;
    do {
        std::cout << "Ingresa el tema del libro:" << std::endl;
        std::getline(std::cin, tema);

        if (!tema.empty()) break;

        std::cout << "Por favor, ingresa un tema.";
    } while (true);

    Autor t("_", "_", -1, -1, "_");
    Libro l(0, nombreLibro, t, fechaPublicacion, tema);
    return l;
}

std::string Libro::toCSV() {
    std::string csv;
    std::stringstream gstream;
    gstream << getCodigo();
    std::string codigo = gstream.str();
    gstream << getAutor().getDni();
    std::string autor = gstream.str();
    csv = codigo + "," + getNombre() + "," + autor + "," + getFechaPublicacion() + "," + getTema();
    return csv;
}

Libro Libro::fromCSV(std::string csv) {
    std::string datos[5];
    int codigo, n = 0;
    Autor autor("", "", -1, -1, "");
    std::string nombre, fechaPublicacion, tema, aux;

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
    tema = datos[4];

    Libro nuevoLibro(codigo, nombre, autor, fechaPublicacion, tema);
    return nuevoLibro;
}


