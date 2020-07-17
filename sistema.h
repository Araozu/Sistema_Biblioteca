//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_SISTEMA_H
#define SISTEMABIBLIOTECA_SISTEMA_H
#include <iostream>
#include <fstream>
#include <vector>
#include "libro.h"
#include "Persona/cliente.h"
#include "prestamo.h"
#include "categoria.h"

class Sistema {
private:
    bool esAdmin;
    std::vector<Prestamo> prestamos;
    std::vector<Libro> libros;
    std::vector<Cliente> clientes;
    std::vector<Autor> autores;
    std::vector<Persona> personas;
    std::vector<Categoria>categorias;

public:
    Sistema(bool esAdmin);
    ~Sistema();

    void run();

    void agregarLibro(Libro libro);
    void removerLibro(Libro libro);
    void actualizarLibro();                 // TODO: Identificar parametros
    Libro buscarLibro(std::string nombre);
    void prestarLibro(Libro libro, Cliente cliente);
    void devolverLibro(Libro libro, Cliente cliente);
    Libro* listaLibros();

    static std::vector<Prestamo> cargarPrestamos();
    static std::vector<Libro> cargarLibros();
    static std::vector<Cliente> cargarClientes();
    static std::vector<Autor> cargarAutores();
    static std::vector<Persona> cargarPersonas();
    static std::vector<Categoria> cargarCategorias();

    int sigCodigoPrestamo();
    int sigCodigoLibro();
    int sigCodigoCategoria();

};


#endif //SISTEMABIBLIOTECA_SISTEMA_H
