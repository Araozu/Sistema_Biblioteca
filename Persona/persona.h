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
    int dni;
    int telefono;
    std::string direccion;

public:
    Persona(std::string _nombres, std::string _apellidos, int _dni, int _telefono, std::string _direccion);

    std::string getNombres() const;

    void setNombres(std::string nombres);

    std::string getApellidos() const;

    void setApellidos(std::string apellidos);

    int getDni() const;

    void setDni(int dni);

    int getTelefono() const;

    void setTelefono(int telefono);

    std::string getDireccion() const;

    void setDireccion(std::string direccion);

    static Persona crearPersonaPorConsola();

    virtual std::string toCSV();

    static Persona fromCSV(const std::string &csv);

};

#endif //SISTEMABIBLIOTECA_PERSONA_H
