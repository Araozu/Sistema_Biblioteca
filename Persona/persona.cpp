//
// Created by Fernando on 04/06/2020.
//
#include <stdio.h>
#include "persona.h"

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

void Persona::crearPersonaPorConsola() {
    cout << ("------------------------------------BIENVENIDO--------------------------------------------------")
         << endl;
    string nombres;
    string apellidos;
    int dni;
    int telefono;
    string direccion;
    cout << "Ingrese nombre: ";
    cin >> nombres;
    cout << "Ingrese Apellidos: ";
    cin >> apellidos;
    cout << "Ingrese Dni: ";
    cin >> dni;
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cout << "Ingrese Direccion: ";
    cin >> direccion;
    cout << "Nombre: " << nombres << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "DNI: " << dni << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Direccion: " << direccion << endl;

}

