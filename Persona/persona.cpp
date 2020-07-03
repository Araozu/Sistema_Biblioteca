//
// Created by Fernando on 04/06/2020.
//
#include "persona.h"
#include <sstream>

using namespace std;

Persona::Persona(std::string _nombres, std::string _apellidos, int _dni, int _telefono, std::string _direccion) {
    nombres = _nombres;
    apellidos = _apellidos;
    dni = _dni;
    telefono = _telefono;
    direccion = _direccion;
}

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

int Persona::getDni() const {
    return dni;
}

void Persona::setDni(int dni) {
    Persona::dni = dni;
}

int Persona::getTelefono() const {
    return telefono;
}

void Persona::setTelefono(int telefono) {
    Persona::telefono = telefono;
}

std::string Persona::getDireccion() const {
    return direccion;
}

void Persona::setDireccion(std::string direccion) {
    Persona::direccion = direccion;
}

Persona Persona::crearPersonaPorConsola() {
    cout << ("------------------------------------BIENVENIDO--------------------------------------------------")
         << endl;
    string nombres;
    string apellidos;
    int dni;
    int telefono;
    string direccion;
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

    //DNI

    do {
        cout << "Ingrese Dni: ";
        cin >> dni;
        if (dni <= 10000000 || dni >= 999999999)
            cout << "DNI no valido,volver a intentar!" << endl;
    } while (dni <= 10000000 || dni >= 999999999);
    cout << "INGRESO DE DNI EXITOSO." << endl;

    //CELULAR
    do {
        cout << "Ingrese Celular: ";
        cin >> telefono;
        if (telefono <= 100000000 || telefono >= 999999999)
            cout << "Telefono no Valido,volver a intentar!" << endl;
    } while (telefono <= 100000000 || telefono >= 999999999);
    cout << "INGRESO DE TELEFONO EXITOSO." << endl;
    //DIRECCION
    do {
        cout << "Ingrese la Direccion: " << endl;
        getline(cin, direccion);
        if (direccion.length() <= 3 || direccion.length() >= 45)
            cout << "Ingreso no valido,volver a intentar!" << endl;
    } while (direccion.length() <= 3 || direccion.length() >= 45);
    cout << "INGRESO DE DIRECCION EXITOSO." << endl;
    //  cout<<"Ingrese Direccion: ";
    //  cin>>direccion;

    cout << "----------------------------DATOS-------------------------" << endl;
    cout << "Nombre: " << nombres << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "DNI: " << dni << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Direccion: " << direccion << endl;

    Persona persona(nombres, apellidos, dni, telefono, direccion);
    return persona;

}

std::string Persona::toCSV() {
    std::stringstream sstream;

    sstream << nombres << ","
            << apellidos << ","
            << dni << ","
            << telefono << ","
            << direccion;

    return sstream.str();
}

Persona Persona::fromCSV() {

}



