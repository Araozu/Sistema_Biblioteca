//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_CLIENTE_H
#define SISTEMABIBLIOTECA_CLIENTE_H
#include "persona.h"

class Cliente: Persona {
public:
    Cliente(const std::string &nombres, const std::string &apellidos, int dni, int telefono,
            const std::string &direccion);
};


#endif //SISTEMABIBLIOTECA_CLIENTE_H
