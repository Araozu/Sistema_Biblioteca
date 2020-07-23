//
// Created by Fernando on 23/07/2020.
//

#ifndef SISTEMABIBLIOTECA_EXCEPCIONAUTORNOENCONTRADO_H
#define SISTEMABIBLIOTECA_EXCEPCIONAUTORNOENCONTRADO_H
#include "excepcion.h"

class ExcepcionAutorNoEncontrado: public Excepcion {
public:
    ExcepcionAutorNoEncontrado(const std::string &mensaje);
};


#endif //SISTEMABIBLIOTECA_EXCEPCIONAUTORNOENCONTRADO_H
