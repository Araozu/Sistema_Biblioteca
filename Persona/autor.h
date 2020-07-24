//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_AUTOR_H
#define SISTEMABIBLIOTECA_AUTOR_H
#include "persona.h"
#include <sstream>

class Autor: public Persona {
public:
    int id;
    Autor(int id, std::string nombres, std::string apellidos);
    std::string toCSV() override;
    static Autor fromCSV(const std::string &csv);

    int getId() const;
};


#endif //SISTEMABIBLIOTECA_AUTOR_H
