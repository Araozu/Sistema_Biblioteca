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

std::vector<Prestamo> Sistema::cargarPrestamos() {
    std::ifstream lectora("./data/prestamos.csv");
    std::vector<Prestamo> prestamos;
    std::string linea;

    std::getline(lectora, linea);

    while (!lectora.eof()) {
        getline(lectora, linea);
        Prestamo p = Prestamo::fromCSV(linea);
        prestamos.push_back(p);
    }

    return prestamos;
}

std::vector<Cliente> Sistema::cargarClientes() {
    std::ifstream lectora("./data/clientes.csv");
    std::vector<Cliente> clientes;
    std::string linea;

    std::getline(lectora,linea);

    while(!lectora.eof()){
        getline(lectora,linea);
        Cliente c= Cliente::fromCSV(linea);
        clientes.push_back(c);

    }

    return clientes;

}
std::vector<Persona> Sistema::cargarPersonas() {
    std::ifstream lectora("./data/personas.csv");
    std::vector<Persona> personas;
    std::string linea;

    std::getline(lectora, linea);

    while (!lectora.eof()) {
        getline(lectora, linea);
        Persona p = Persona::fromCSV(linea);
        
        personas.push_back(p);
    }

    return personas;
}

