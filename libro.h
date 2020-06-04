//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_LIBRO_H
#define SISTEMABIBLIOTECA_LIBRO_H
#include <iostream>
#include "Persona/autor.h"

class Libro {
private:
    int codigo;
    std::string nombre;
    Autor autor;
    std::string fechaPublicacion;  // TODO: Cambiar a un objeto
    std::string tema;  // Biologia/Matematica/etc

public:

};


#endif //SISTEMABIBLIOTECA_LIBRO_H
