// =g
// Created by Dell on 18/06/2020.
//
#include "categoria.h"
#include <cstdlib>
#include <sstream>

Categoria::Categoria(std::string _nombre, int _id) {
    nombre = _nombre;
    id = _id;
}

std::string Categoria::getNombre() const {
    return nombre;
}

void Categoria::setNombre(std::string nombre) {
    Categoria::nombre = nombre;
}

int Categoria::getId() const {
    return id;
}

std::string Categoria::toCSV() {
    std::string csv;
    std::stringstream gstream;

    gstream << getNombre() << ",";
    gstream << getId();

    csv = gstream.str();
    return csv;
}

Categoria Categoria::fromCSV(std::string csv) {
    std::string datos[5];
    int id, n = 0;
    std::string nombre;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            datos[n] += i;
        }
    }

    nombre = datos[0];
    id = atoi(datos[1].c_str());

    Categoria nuevoCategoria(nombre, id);
    return nuevoCategoria;
}

Categoria Categoria::crearCategoriaPorConsola() {
    std::cout << "Seccion Categoria" << std::endl;
    std::string categoria;
    do {
        std::cout << "Ingresa categoria del libro:" << std::endl;
        std::getline(std::cin, categoria);

        if (!categoria.empty()) break;

        std::cout << "Ingrese categoria";
    } while (true);
    
    Categoria categoria1(categoria,0);
    return    categoria1;
}
