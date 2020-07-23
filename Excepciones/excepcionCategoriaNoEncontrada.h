//
// Created by Fernando on 23/07/2020.
//

#ifndef SISTEMABIBLIOTECA_EXCEPCIONCATEGORIANOENCONTRADA_H
#define SISTEMABIBLIOTECA_EXCEPCIONCATEGORIANOENCONTRADA_H
#include "excepcion.h"

class ExcepcionCategoriaNoEncontrada: public Excepcion {
public:
    ExcepcionCategoriaNoEncontrada(const std::string &mensaje);
};


#endif //SISTEMABIBLIOTECA_EXCEPCIONCATEGORIANOENCONTRADA_H
