//
// Created by Fernando on 15/07/2020.
//

#ifndef SISTEMABIBLIOTECA_EXCEPCIONCSVINCORRECTO_H
#define SISTEMABIBLIOTECA_EXCEPCIONCSVINCORRECTO_H
#include "excepcion.h"

class ExcepcionCSVIncorrecto: public Excepcion {

public:
    ExcepcionCSVIncorrecto(std::string mensaje);

};


#endif //SISTEMABIBLIOTECA_EXCEPCIONCSVINCORRECTO_H
