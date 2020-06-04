//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_SISTEMA_H
#define SISTEMABIBLIOTECA_SISTEMA_H
#include <iostream>
#include "libro.h"
#include "Persona/cliente.h"

class Sistema {
public:
    void agregarLibro(Libro libro);
    void removerLibro(Libro libro);
    void actualizarLibro();                 // TODO: Identificar parametros
    Libro buscarLibro(std::string nombre);
    void prestarLibro(Libro libro, Cliente cliente);
    void devolverLibro(Libro libro, Cliente cliente);
    Libro* listaLibros();

};


#endif //SISTEMABIBLIOTECA_SISTEMA_H
