//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_AUTOR_H
#define SISTEMABIBLIOTECA_AUTOR_H
#include "persona.h"

class Autor: public Persona {
public:
    Autor(std::string nombres, std::string apellidos, int dni, int telefono, std::string direccion);

};


#endif //SISTEMABIBLIOTECA_AUTOR_H
