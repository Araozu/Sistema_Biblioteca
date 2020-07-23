//
// Created by Fernando on 04/06/2020.
//

#include "sistema.h"
#include "./Excepciones/excepcionAutorNoEncontrado.h"
#include "./Excepciones/excepcionCategoriaNoEncontrada.h"

Sistema::Sistema(bool esAdmin) : esAdmin(esAdmin) {
    std::cout << "Recuperando datos..." << std::endl;
    prestamos = Sistema::cargarPrestamos();
    libros = Sistema::cargarLibros();
    clientes = Sistema::cargarClientes();
    autores = Sistema::cargarAutores();
    personas = Sistema::cargarPersonas();
    categorias = Sistema::cargarCategorias();
    std::cout << "Listo." << std::endl;
}

Sistema::~Sistema() {
    std::cout << "Almacenando datos a memoria secundaria..." << std::endl;
    almacenarAutores();
    almacenarCategorias();
    almacenarClientes();
    almacenarLibros();
    almacenarPersonas();
    almacenarPrestamos();
    std::cout << "Listo." << std::endl;
}

void Sistema::run() {
    std::string opcionRaw;
    int opcion;
    do {

        std::cout << std::endl << "Menu Principal" << std::endl << std::endl
                  << "1: Ver libros" << std::endl
                  << "2: Buscar un libro por nombre" << std::endl
                  << "3: Buscar un libro por autor" << std::endl
                  << "4: Buscar un libro por categoria" << std::endl
                  << "5: Ver autores" << std::endl
                  << "6: Buscar un autor" << std::endl;

        if (esAdmin) {
            std::cout << "7: Registrar un prestamo" << std::endl
                      << "8: Registrar una devolucion" << std::endl
                      << "9: Registrar un usuario" << std::endl
                      << "10: Registrar un autor" << std::endl
                      << "11: Registrar un libro" << std::endl
                      << "12: Eliminar un usuario" << std::endl
                      << "13: Eliminar un autor" << std::endl
                      << "14: Eliminar un libro" << std::endl;
        }

        std::cout << "0: Salir" << std::endl
                  << "Escoge una opcion:" << std::endl;

        std::getline(std::cin, opcionRaw);
        opcion = std::stoi(opcionRaw);

        switch (opcion) {
            case 0: { break; }
            case 2: {
                buscarLibroPorNombre();
                break;
            }
            case 3: {
                buscarLibroPorAutor();
                break;
            }
            case 4: {
                buscarlibroPorCategoria();
                break;
            }
            default: {
                std::cerr << "Opcion incorrecta." << std::endl;
            }
        }

    } while (opcion != 0);

}

std::vector<Libro> Sistema::cargarLibros() {
    std::ifstream lectora("./data/libros.csv");
    std::vector<Libro> libros;
    std::string linea;

    std::getline(lectora, linea);

    while (!lectora.eof()) {
        getline(lectora, linea);
        if (linea.empty()) break;
        Libro l = Libro::fromCSV(linea);
        libros.push_back(l);
    }

    return libros;
}

std::vector<Prestamo> Sistema::cargarPrestamos() {
    std::ifstream lectora("./data/prestamos.csv");
    std::vector<Prestamo> prestamos;
    std::string linea;

    std::getline(lectora, linea);

    while (!lectora.eof()) {
        getline(lectora, linea);
        if (linea.empty()) break;
        Prestamo p = Prestamo::fromCSV(linea);
        prestamos.push_back(p);
    }

    return prestamos;
}

std::vector<Cliente> Sistema::cargarClientes() {
    std::ifstream lectora("./data/clientes.csv");
    std::vector<Cliente> clientes;
    std::string linea;

    std::getline(lectora, linea);

    while (!lectora.eof()) {
        getline(lectora, linea);
        if (linea.empty()) break;
        Cliente c = Cliente::fromCSV(linea);
        clientes.push_back(c);
    }

    return clientes;
}

std::vector<Autor> Sistema::cargarAutores() {
    std::ifstream lectora("./data/autores.csv");
    std::vector<Autor> autores;
    std::string linea;

    std::getline(lectora, linea);

    while (!lectora.eof()) {
        getline(lectora, linea);
        if (linea.empty()) break;
        Autor a = Autor::fromCSV(linea);
        autores.push_back(a);
    }

    return autores;
}

std::vector<Persona> Sistema::cargarPersonas() {
    std::ifstream lectora("./data/personas.csv");
    std::vector<Persona> personas;
    std::string linea;

    std::getline(lectora, linea);

    while (!lectora.eof()) {
        getline(lectora, linea);
        if (linea.empty()) break;
        Persona p = Persona::fromCSV(linea);
        personas.push_back(p);
    }

    return personas;
}

std::vector<Categoria> Sistema::cargarCategorias() {
    std::ifstream lectura("./data/categorias.csv");
    std::vector<Categoria> categorias;
    std::string linea;
    std::getline(lectura, linea);
    while (!lectura.eof()) {
        getline(lectura, linea);
        if (linea.empty()) break;
        Categoria c = Categoria::fromCSV(linea);
        categorias.push_back(c);
    }
    return categorias;
}

int Sistema::sigCodigoPrestamo() {
    int sigCod = -1;
    for (const auto &p: prestamos) {
        int codigoPrestamo = p.getCodigoPrestamo();
        if (codigoPrestamo > sigCod) sigCod = codigoPrestamo;
    }
    return sigCod + 1;
}

int Sistema::sigCodigoLibro() {
    int sigCod = -1;
    for (const auto &l: libros) {
        int codigoLibro = l.getCodigo();
        if (codigoLibro > sigCod) sigCod = codigoLibro;
    }
    return sigCod + 1;
}

int Sistema::sigCodigoCategoria() {
    int sigCod = -1;
    for (const auto &c: categorias) {
        int codigoCategoria = c.getId();
        if (codigoCategoria > sigCod) sigCod = codigoCategoria;
    }
    return sigCod + 1;
}

void Sistema::almacenarPrestamos() {

}

void Sistema::almacenarLibros() {

}

void Sistema::almacenarClientes() {

}

void Sistema::almacenarAutores() {

}

void Sistema::almacenarPersonas() {

}

void Sistema::almacenarCategorias() {

}

void Sistema::verLibros() {

}

void Sistema::buscarLibroPorNombre() {
    std::string nombre;
    std::cout << "Ingresa el nombre del libro:";
    std::getline(std::cin, nombre);

    bool libroEncontrado = false;
    for (const auto &l: libros) {
        if (l.getNombre().find(nombre) != std::string::npos) {
            libroEncontrado = true;
            std::cout << std::endl
                      << "Codigo de libro     : " << l.getCodigo() << std::endl
                      << "Nombre del libro    : " << l.getNombre() << std::endl
                      << "Codigo del autor    : " << l.getCodigoAutor() << std::endl
                      << "Fecha de publicacion: " << l.getFechaPublicacion() << std::endl
                      << "Codigo de categoria : " << l.getCodigoCategoria() << std::endl;
        }
    }

    if (!libroEncontrado) {
        std::cout << "No se encontro un libro con nombre '" << nombre << "'." << std::endl;
    }

    std::cout << "Presiona enter para continuar.";
    std::cin.ignore();
}

void Sistema::buscarLibroPorAutor() {
    std::string nombre;
    std::cout << "Ingresa el nombre del autor:";
    std::getline(std::cin, nombre);

    bool libroEncontrado = false;
    for (const auto &l: libros) {
        try {
            Autor a = obtenerAutorConId(l.getCodigoAutor());
            if (a.getNombres().find(nombre) != std::string::npos) {
                libroEncontrado = true;
                std::cout << "Codigo de libro     : " << l.getCodigo() << std::endl
                          << "Nombre del libro    : " << l.getNombre() << std::endl
                          << "Codigo del autor    : " << l.getCodigoAutor() << std::endl
                          << "Fecha de publicacion: " << l.getFechaPublicacion() << std::endl
                          << "Codigo de categoria : " << l.getCodigoCategoria() << std::endl
                          << std::endl;
            }
        } catch (ExcepcionAutorNoEncontrado&) {
            std::cerr << "Advertencia: Se intento recuperar un autor con id " << l.getCodigoAutor()
                      << ", pero no se encontro." << std::endl;
        }
    }

    if (!libroEncontrado) {
        std::cout << "No se encontro un libro con autor '" << nombre << "'." << std::endl;
    }
}

void Sistema::buscarlibroPorCategoria() {
    std::string nombre;
    std::cout << "Ingresa el nombre del autor:";
    std::getline(std::cin, nombre);

    bool libroEncontrado = false;
    for (const auto &l: libros) {
        try {
            Categoria c = obtenerCategoriaConId(l.getCodigoCategoria());
            if (c.getNombre().find(nombre) != std::string::npos) {
                libroEncontrado = true;
                std::cout << "Codigo de libro     : " << l.getCodigo() << std::endl
                          << "Nombre del libro    : " << l.getNombre() << std::endl
                          << "Codigo del autor    : " << l.getCodigoAutor() << std::endl
                          << "Fecha de publicacion: " << l.getFechaPublicacion() << std::endl
                          << "Codigo de categoria : " << l.getCodigoCategoria() << std::endl
                          << std::endl;
            }
        } catch (ExcepcionCategoriaNoEncontrada&) {
            std::cerr << "Advertencia: Se intento recuperar una categoria con id " << l.getCodigoAutor()
                      << ", pero no se encontro." << std::endl;
        }
    }

    if (!libroEncontrado) {
        std::cout << "No se encontro un libro con autor '" << nombre << "'." << std::endl;
    }
}

void Sistema::verAutores() {

}

void Sistema::buscarAutor() {

}

void Sistema::registrarPrestamo() {

}

void Sistema::registrarDevolucion() {

}

void Sistema::registrarUsuario() {

}

void Sistema::registrarAutor() {

}

void Sistema::registrarLibro() {

}

void Sistema::eliminarUsuario() {

}

void Sistema::eliminarAutor() {

}

void Sistema::eliminarLibro() {

}

Autor Sistema::obtenerAutorConId(int id) {
    for (const auto &a: autores) {
        if (a.getId() == id) return a;
    }

    throw ExcepcionAutorNoEncontrado("No se pudo obtener un autor con id. En obtenerAutorConId.");
}

Categoria Sistema::obtenerCategoriaConId(int id) {
    for (const auto &c: categorias) {
        if (c.getId() == id) return c;
    }

    throw  ExcepcionCategoriaNoEncontrada("No se pudo obtener una categoria con id. En obtenerCategoriaConId");
}

