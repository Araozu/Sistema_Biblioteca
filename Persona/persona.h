//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_PERSONA_H
#define SISTEMABIBLIOTECA_PERSONA_H

#include <iostream>

class Persona {
protected:
    std::string nombres;
    std::string apellidos;

public:
    Persona(std::string nombres, std::string apellidos);

    std::string getNombres() const;

    void setNombres(std::string nombres);

    std::string getApellidos() const;

    void setApellidos(std::string apellidos);

    static Persona crearPersonaPorConsola();

    virtual std::string toCSV();

    static Persona fromCSV(const std::string &csv);

};

#endif //SISTEMABIBLIOTECA_PERSONA_H
