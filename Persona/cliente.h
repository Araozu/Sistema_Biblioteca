//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_CLIENTE_H
#define SISTEMABIBLIOTECA_CLIENTE_H
#include "persona.h"

class Cliente: Persona {
public:
    Cliente(const std::string &nombres, const std::string &apellidos, int dni, int telefono,
            const std::string &direccion);
    std::string toCSV() override;
    static Cliente fromCSV(const std::string &csv);
};


#endif //SISTEMABIBLIOTECA_CLIENTE_H
