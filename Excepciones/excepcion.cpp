//
// Created by Fernando on 15/07/2020.
//

#include "excepcion.h"

Excepcion::Excepcion(std::string mensaje): mensaje(mensaje) {}

const char* Excepcion::what() const noexcept {
    return mensaje.c_str();
}

