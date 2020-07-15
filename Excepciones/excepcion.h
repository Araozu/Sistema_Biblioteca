//
// Created by Fernando on 15/07/2020.
//

#ifndef SISTEMABIBLIOTECA_EXCEPCION_H
#define SISTEMABIBLIOTECA_EXCEPCION_H
#include <exception>
#include <string>

class Excepcion: public std::exception {

public:
    const std::string mensaje;
    explicit Excepcion(std::string mensaje);

    const char* what() const noexcept override;

};


#endif //SISTEMABIBLIOTECA_EXCEPCION_H
