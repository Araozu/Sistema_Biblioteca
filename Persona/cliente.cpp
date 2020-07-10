//
// Created by Fernando on 04/06/2020.
//

#include "cliente.h"

Cliente::Cliente(const std::string &nombres, const std::string &apellidos, int dni, int telefono,
                 const std::string &direccion) : Persona(nombres, apellidos, dni, telefono, direccion) {}

Cliente Cliente::fromCSV(const std::string &csv) {
    std::string fragmentos[5];
    int n = 0;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            fragmentos[n] += i;
        }
    }

    int dni = std::stoi(fragmentos[2]);
    int telefono = std::stoi(fragmentos[3]);
    Cliente c{fragmentos[0], fragmentos[1], dni, telefono, fragmentos[4]};
    return c;
}
