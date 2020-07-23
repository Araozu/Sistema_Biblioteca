//
// Created by Fernando on 17/07/2020.
//

#ifndef SISTEMABIBLIOTECA_EXCEPCIONCARGADATOS_H
#define SISTEMABIBLIOTECA_EXCEPCIONCARGADATOS_H
#include "excepcion.h"

class ExcepcionCargaDatos: public Excepcion {

public:
    ExcepcionCargaDatos(std::string mensaje);

};


#endif //SISTEMABIBLIOTECA_EXCEPCIONCARGADATOS_H
