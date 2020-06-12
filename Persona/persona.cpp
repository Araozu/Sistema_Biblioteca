//
// Created by Fernando on 04/06/2020.
//

#include "persona.h"
Persona::Persona(std::string _nombres,std::string _apellidos,int _dni,int _telefono, std::string _direccion,){
    nombres=_nombres;
    apellidos=_apellidos;
    dni=_dni;
    telefono=_telefono;
    direccion=_direccion;
}
std::string Persona::getNombres() const{
    return nombres;
}

void Persona::setNombres(std::string nombres){
    Persona::nombres = nombres;
}

std::string Persona::getApellidos() const{
    return apellidos;
}

void Persona::setApellidos(std::string apellidos){
    Persona::apellidos = apellidos;
}

int Persona::getDni() const{
    return dni;
}

void Persona::setDni(int dni){
    Persona::dni = dni;
}

int Persona::getTelefono() const{
    return telefono;
}

void Persona::setTelefono(int telefono){
    Persona::telefono = telefono;
}

std::string Persona::getDireccion() const{
    return direccion;
}

void Persona::setDireccion(std::string direccion){
    Persona::direccion = direccion;
}
