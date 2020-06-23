//
// Created by Dell on 18/06/2020.
//
#include "categoria.h"

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
