//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_AUTOR_H
#define SISTEMABIBLIOTECA_AUTOR_H
#include "persona.h"
#include <sstream>

class Autor: public Persona {
private:
    int id;

public:
    Autor(int id, std::string nombres, std::string apellidos);
    std::string toCSV() override;
    static Autor fromCSV(const std::string &csv);
    static Autor crearAutorPorConsola(int idAutor);

    int getId() const;
};


#endif //SISTEMABIBLIOTECA_AUTOR_H
