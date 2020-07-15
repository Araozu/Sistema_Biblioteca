//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_AUTOR_H
#define SISTEMABIBLIOTECA_AUTOR_H
#include "persona.h"
#include <sstream>

class Autor: public Persona {
public:
    Autor(std::string nombres, std::string apellidos, int dni, int telefono, std::string direccion);
    std::string toCSV() override;
    static Autor fromCSV(const std::string &csv);
};


#endif //SISTEMABIBLIOTECA_AUTOR_H
