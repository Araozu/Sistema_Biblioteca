//
// Created by Fernando on 04/06/2020.
//

#include "cliente.h"

Cliente::Cliente(const std::string &nombres, const std::string &apellidos, int dni, int telefono,
                 const std::string &direccion) : Persona(nombres, apellidos, dni, telefono, direccion) {}
