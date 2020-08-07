//
// Created by Fernando on 04/06/2020.
//

#include <sstream>
#include "libro.h"
#include "Excepciones/excepcionCsvIncorrecto.h"

Libro::Libro(int codigo, std::string nombre, int autor, std::string fechaPublicacion, int codigoCat) :
        codigo(codigo), nombre(nombre), codigoAutor(autor), fechaPublicacion(fechaPublicacion),
        codigoCategoria(codigoCat) {}

int Libro::getCodigo() const {
    return codigo;
}

void Libro::setCodigo(int codigo) {
    Libro::codigo = codigo;
}

std::string Libro::getNombre() const {
    return nombre;
}

void Libro::setNombre(std::string nombre) {
    Libro::nombre = nombre;
}

int Libro::getCodigoAutor() const {
    return codigoAutor;
}

void Libro::setCodigoAutor(int codigoAutor) {
    Libro::codigoAutor = codigoAutor;
}

std::string Libro::getFechaPublicacion() const {
    return fechaPublicacion;
}

void Libro::setFechaPulicacion(std::string fechaPublicacion) {
    Libro::fechaPublicacion = fechaPublicacion;
}

void Libro::setFechaPublicacion(const std::string &fechaPublicacion) {
    Libro::fechaPublicacion = fechaPublicacion;
}

int Libro::getCodigoCategoria() const {
    return codigoCategoria;
}

void Libro::setCodigoCategoria(int codigoCategoria) {
    Libro::codigoCategoria = codigoCategoria;
}

/**
 * Declaracion del metodo CrearLibroPorConsola
 * @param codLibro al crear un libro por Consola se autoenumerara con un codigo correspondiente
 * Retorna todos los valores introduccidos del libro nuevo
 */
Libro Libro::crearLibroPorConsola(int codLibro) {
    std::cout << "Creando un Libro." << std::endl;

    std::string nombreLibro;
    do {
        std::cout << "Ingresa el nombre del libro:" << std::endl;
        //Se ingresa el nombre del Libro Nuevo
        std::getline(std::cin, nombreLibro);
        //Se Verifica que el nombre ingresado del Libre no sea un valor Nulo o vacio
        if (!nombreLibro.empty()) break;

        std::cout << "Por favor, ingresa un nombre.";
    } while (true);

    std::string fechaPublicacion;
    do {
        //Se ingresa la fecha de publicacion del libro
        std::cout << "Ingresa la fecha de publicacion del libro:" << std::endl;
        std::getline(std::cin, fechaPublicacion);
        //Se Verifica que el ingreso de la fecha no sea un valor Nulo o vacio
        if (!fechaPublicacion.empty()) break;

        std::cout << "Por favor, ingresa una fecha.";
    } while (true);

    std::string codAutorRaw;
    int codAutor;
    do {
        std::cout << "Ingresa el codigo del autor:" << std::endl;
        //Se ingresa el codigo del Autor
        std::getline(std::cin, codAutorRaw);
        try {
            //Se atrapa el codigo de Autor y se verifica que no este vacio, caso contrario pasa a la excepcion catch y se le pide que ingrese un numero
            codAutor = std::stoi(codAutorRaw);
            break;

        } catch (...) {
            std::cout << "Por favor, ingresa un numero.";
        }

    } while (true);

    std::string codCatRaw;
    int codCat;
    do {
        //Se pide ingresar el codigo de la categoria de Libro
        std::cout << "Ingresa el codigo de la categoria:" << std::endl;
        std::getline(std::cin, codCatRaw);
        try {

            codCat = std::stoi(codCatRaw);
            break;

        } catch (...) {
            std::cout << "Por favor, ingresa un numero.";
        }

    } while (true);

    Libro l(codLibro, nombreLibro, codAutor, fechaPublicacion, codCat);
    return l;
}
/**
 * Metodo para dirigir libro a los archivos excel con sus datos respectivos
 * @return Devuelve el valor de excel ya ingresado los datos correspondientes
 */
std::string Libro::toCSV() {
    std::string csv;
    std::stringstream gstream;

    gstream << getCodigo() << ",";
    gstream << nombre << ",";
    gstream << codigoAutor << ",";
    gstream << fechaPublicacion << ",";
    gstream << codigoAutor;
    csv = gstream.str();
    return csv;
}
/**
 * Meotod para la verificacion del Libro enviado a archivo excel si los valores son aceptados de manera correcta
 * @param csv valor que tendra los datos de libro ingresado
 * @return Se ingresara de manera exitosa los datos del libro al excel, caos contrario se mostrara el error de dato ingresado
 */
Libro Libro::fromCSV(std::string csv) {
    std::string datos[5];
    int codigo, tema, n = 0;

    std::string nombre, fechaPublicacion, aux;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            datos[n] += i;
        }
    }

    try {
        codigo = std::stoi(datos[0]);
        nombre = datos[1];
        int idAutor = std::stoi(datos[2]);
        fechaPublicacion = datos[3];
        tema = std::stoi(datos[4]);

        Libro nuevoLibro(codigo, nombre, idAutor, fechaPublicacion, tema);
        return nuevoLibro;
    } catch (std::invalid_argument &) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Libro. Argumento invalido." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (std::out_of_range &) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Libro. Datos fuera de los rangos permitidos." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (...) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Libro." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    }
}
