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
    std::cout << "Programa terminado." << std::endl;
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
                      << "9: Registrar un cliente" << std::endl
                      << "10: Registrar un autor" << std::endl
                      << "11: Registrar un libro" << std::endl
                      << "12: Eliminar un cliente" << std::endl
                      << "13: Eliminar un autor" << std::endl
                      << "14: Eliminar un libro" << std::endl;
        }

        std::cout << "0: Salir" << std::endl
                  << "Escoge una opcion:" << std::endl;

        std::getline(std::cin, opcionRaw);
        opcion = std::stoi(opcionRaw);

        if (opcion > 6 && !esAdmin) {
            std::cerr << "Opcion invalida" << std::endl;
            continue;
        }

        switch (opcion) {
            case 0: {
                break;
            }
            case 1: {
                verLibros();
                break;
            }
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
            case 6: {
                buscarAutor();
                break;
            }
            case 12: {
                eliminarCliente();
                break;
            }
            case 13: {
                eliminarAutor();
                break;
            }
            case 14: {
                eliminarLibro();
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
    std::ofstream escribir("./data/prestamos.csv");
    if (!escribir.is_open()) {
        std::cerr << "Error al escribir los datos al archivo prestamos.csv." << std::endl;
    }

    escribir << "codigoPrestamo,codigoLibro,dniCliente,fechaPrestamo,fechaDevolucion,devuelto" << std::endl;
    for (Prestamo p: prestamos) {
        escribir << p.toCSV() << std::endl;
    }

    escribir.close();
}

void Sistema::almacenarLibros() {
    std::ofstream escribir("./data/libros.csv");
    if (!escribir.is_open()) {
        std::cerr << "Error al escribir los datos al archivo libros.csv." << std::endl;
    }

    escribir << "codigo,nombre,codigoAutor,fechaPublicacion,codigoCategoria" << std::endl;
    for (Libro l: libros) {
        escribir << l.toCSV() << std::endl;
    }

    escribir.close();
}

void Sistema::almacenarClientes() {
    std::ofstream escribir("./data/clientes.csv");
    if (!escribir.is_open()) {
        std::cerr << "Error al escribir los datos al archivo clientes.csv." << std::endl;
    }

    escribir << "nombres,apellidos,dni,telefono,direccion" << std::endl;
    for (Cliente c : clientes) {
        escribir << c.toCSV() << std::endl;
    }

    escribir.close();
}

void Sistema::almacenarAutores() {
    std::ofstream escribir("./data/autores.csv");
    if (!escribir.is_open()) {
        std::cerr << "Error al escribir los datos al archivo autores.csv." << std::endl;
    }

    escribir << "id,nombres,apellidos,dni,telefono,direccion" << std::endl;
    for (Autor a : autores) {
        escribir << a.toCSV() << std::endl;
    }

    escribir.close();
}

void Sistema::almacenarPersonas() {
    std::ofstream escribir("./data/personas.csv");
    if (!escribir.is_open()) {
        std::cerr << "Error al escribir los datos al archivo personas.csv." << std::endl;
    }

    escribir << "nombres,apellidos,dni,telefono,direccion" << std::endl;
    for (Persona p: personas)
        escribir << p.toCSV() << std::endl;
    escribir.close();
}

void Sistema::almacenarCategorias() {
    std::ofstream escribir("./data/categorias.csv");
    if (!escribir.is_open()) {
        std::cerr << "Error al escribir los datos al archivo categorias.csv." << std::endl;
    }

    escribir << "nombre,id" << std::endl;
    for (Categoria c: categorias) {
        escribir << c.toCSV() << std::endl;
    }

    escribir.close();
}

void Sistema::verLibros() {
    //PEPE
    //   std::int codigo;
    for (const auto &l: libros) {
        std::cout << std::endl
                  << "------------------------------------------------------------------" << std::endl
                  << "Codigo de libro     : " << l.getCodigo() << std::endl
                  << "Nombre del libro    : " << l.getNombre() << std::endl
                  << "Codigo del autor    : " << l.getCodigoAutor() << std::endl
                  << "Fecha de publicacion: " << l.getFechaPublicacion() << std::endl
                  << "Codigo de categoria : " << l.getCodigoCategoria() << std::endl
                  << "------------------------------------------------------------------" << std::endl;

    }

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
                          << "Autor               : " << a.getNombres() << std::endl
                          << "Fecha de publicacion: " << l.getFechaPublicacion() << std::endl
                          << "Codigo de categoria : " << l.getCodigoCategoria() << std::endl
                          << std::endl;
            }
        } catch (ExcepcionAutorNoEncontrado &) {
            std::cerr << "Advertencia: Se intento recuperar un autor con id " << l.getCodigoAutor()
                      << ", pero no se encontro." << std::endl;
        }
    }

    if (!libroEncontrado) {
        std::cout << "No se encontro un libro con autor '" << nombre << "'." << std::endl;
    }

    std::cout << "Presiona enter para continuar.";
    std::cin.ignore();
}

void Sistema::buscarlibroPorCategoria() {
    std::string nombre;
    std::cout << "Ingresa el nombre de la categoria:";
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
                          << "Categoria           : " << c.getNombre() << std::endl
                          << std::endl;
            }
        } catch (ExcepcionCategoriaNoEncontrada &) {
            std::cerr << "Advertencia: Se intento recuperar una categoria con id " << l.getCodigoAutor()
                      << ", pero no se encontro." << std::endl;
        }
    }

    if (!libroEncontrado) {
        std::cout << "No se encontro un libro con autor '" << nombre << "'." << std::endl;
    }

    std::cout << "Presiona enter para continuar.";
    std::cin.ignore();
}

void Sistema::verAutores() {

}

void Sistema::buscarAutor() {
    std::string nombre;
    std::cout << "Ingresa el nombre del autor:";
    std::getline(std::cin, nombre);

    bool autorEncontrado = false;
    for (const auto &a: autores) {
        if (a.getNombres().find(nombre) != std::string::npos) {
            autorEncontrado = true;
            std::cout << "Nombres del autor   : " << a.getNombres() << std::endl
                      << "Appellidos del autor: " << a.getApellidos() << std::endl
                      << std::endl;
        }
    }

    if (!autorEncontrado) {
        std::cout << "No se encontro un autor con nombre '" << nombre << "'." << std::endl;
    }

    std::cout << "Presiona enter para continuar.";
    std::cin.ignore();
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

void Sistema::eliminarCliente() {
    std::string dniS;
    std::cout << "Ingresa el dni del usuario:" << std::endl;
    std::getline(std::cin, dniS);
    int dni = std::stoi(dniS);

    bool clienteEliminado = false;
    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->getDni() == dni) {
            std::cout << "Cliente eliminado." << std::endl;
            clienteEliminado = true;
            clientes.erase(it);
            break;
        }
    }

    if (!clienteEliminado) {
        std::cout << "No se encontro un usuario con dni '" << dni << "'." << std::endl;
    }

    std::cout << "Presiona enter para continuar.";
    std::cin.ignore();
}

void Sistema::eliminarAutor() {
    std::string idS;
    std::cout << "Ingresa el id del autor:" << std::endl;
    std::getline(std::cin, idS);
    int id = std::stoi(idS);

    bool autorEliminado = false;
    for (auto it = autores.begin(); it != autores.end(); ++it) {
        if (it->getId() == id) {
            std::cout << "Autor eliminado." << std::endl;
            autorEliminado = true;
            autores.erase(it);
            break;
        }
    }

    if (!autorEliminado) {
        std::cout << "No se encontro un autor con id '" << id << "'." << std::endl;
    }

    std::cout << "Presiona enter para continuar.";
    std::cin.ignore();
}

void Sistema::eliminarLibro() {
    std::string idS;
    std::cout << "Ingresa el id del libro:" << std::endl;
    std::getline(std::cin, idS);
    int id = std::stoi(idS);

    bool libroEliminado = false;
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if (it->getCodigo() == id) {
            std::cout << "Libro eliminado." << std::endl;
            libroEliminado = true;
            libros.erase(it);
            break;
        }
    }

    if (!libroEliminado) {
        std::cout << "No se encontro un libro con id '" << id << "'." << std::endl;
    }

    std::cout << "Presiona enter para continuar.";
    std::cin.ignore();
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

    throw ExcepcionCategoriaNoEncontrada("No se pudo obtener una categoria con id. En obtenerCategoriaConId");
}

