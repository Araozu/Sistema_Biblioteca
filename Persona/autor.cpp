//
// Created by Fernando on 04/06/2020.
//

#include "autor.h"

Autor::Autor(std::string nombres, std::string apellidos, int dni, int telefono, std::string direccion)
        : Persona(nombres, apellidos, dni, telefono, direccion) {

}

Autor Autor::fromCSV(const std::string &csv) {
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
    Autor a{fragmentos[0], fragmentos[1], dni, telefono, fragmentos[4]};
    return a;
}
