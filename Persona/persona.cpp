//
// Created by Fernando on 04/06/2020.
//
#include "persona.h"
#include <sstream>
#include "../Excepciones/excepcionCsvIncorrecto.h"

using namespace std;

Persona::Persona(std::string nombres, std::string apellidos)
    : nombres(nombres), apellidos(apellidos) {}

std::string Persona::getNombres() const {
    return nombres;
}

void Persona::setNombres(std::string nombres) {
    Persona::nombres = nombres;
}

std::string Persona::getApellidos() const {
    return apellidos;
}

void Persona::setApellidos(std::string apellidos) {
    Persona::apellidos = apellidos;
}

Persona Persona::crearPersonaPorConsola() {
    cout << ("------------------------------------BIENVENIDO--------------------------------------------------")
         << endl;
    string nombres;
    string apellidos;

    //NOMBRE
    do {
        cout << "Ingrese Nombre: " << endl;
        //   cin >> nombres;
        getline(cin, nombres);
        if (nombres.length() <= 3 || nombres.length() >= 15 || nombres.empty())
            cout << "Ingreso no valido,volver a intentar!" << endl;
    } while (nombres.length() <= 3 || nombres.length() >= 15 || nombres.empty());
    cout << "INGRESO DE NOMBRRE EXITOSO." << endl;

    //APELLIDOS
    do {
        cout << "Ingrese Apellidos: " << endl;
        // cin>>apellidos;
        getline(cin, apellidos);
        if (apellidos.length() <= 3 || apellidos.length() >= 25 || apellidos.empty())
            cout << "Ingreso no valido,volver a intentar!" << endl;
    } while (apellidos.length() <= 3 || apellidos.length() >= 25 || apellidos.empty());
    cout << "INGRESO DE APELLIDO EXITOSO." << endl;


    cout << "----------------------------DATOS-------------------------" << endl;
    cout << "Nombre: " << nombres << endl;
    cout << "Apellidos: " << apellidos << endl;

    Persona persona(nombres, apellidos);
    return persona;
}

std::string Persona::toCSV() {
    std::stringstream sstream;

    sstream << nombres << ","
            << apellidos;

    return sstream.str();
}

Persona Persona::fromCSV(const std::string &csv) {
    std::string fragmentos[2];
    int n = 0;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            fragmentos[n] += i;
        }
    }

    Persona p{fragmentos[0], fragmentos[1]};
    return p;

}
