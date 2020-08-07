// =g
// Created by Dell on 18/06/2020.
//
#include "categoria.h"
#include <cstdlib>
#include <sstream>
#include "Excepciones/excepcionCsvIncorrecto.h"

Categoria::Categoria(std::string _nombre, int _id) {
    nombre = _nombre;
    id = _id;
}

std::string Categoria::getNombre() const {
    return nombre;
}

void Categoria::setNombre(std::string nombre) {
    Categoria::nombre = nombre;
}

int Categoria::getId() const {
    return id;
}
/*
 * Metodo para el ingreso de valores de Categoria a los archivos excel
 */
std::string Categoria::toCSV() {
    std::string csv;
    std::stringstream gstream;

    gstream << getNombre() << ",";
    gstream << getId();

    csv = gstream.str();
    return csv;
}
/**
 * Metodo que verificara los valores ingresados en toCsv
 * @param csv valor que contiene los valores de Categoria
 * @return  retornara el archivo actualizado con la categoria ingresado , caso contrario mostrara un mensaje señalando el error que tiene el ingreso de los datos
 */
Categoria Categoria::fromCSV(std::string csv) {
    std::string datos[5];
    int id, n = 0;
    std::string nombre;

    for (char i : csv) {
        if (i == ',') {
            n++;
        } else {
            datos[n] += i;
        }
    }

    try {
        nombre = datos[0];
        id = std::stoi(datos[1]);

        Categoria nuevoCategoria(nombre, id);
        return nuevoCategoria;
    } catch (std::invalid_argument) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Categoria. Argumento invalido." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (std::out_of_range) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Categoria. Datos fuera de los rangos permitidos." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    } catch (...) {
        std::stringstream s;
        s << "Error al intentar convertir datos CSV a Categoria." << std::endl
          << "El string causante es:" << std::endl
          << csv;
        throw ExcepcionCSVIncorrecto(s.str());
    }
}

Categoria Categoria::crearCategoriaPorConsola() {
    std::cout << "Seccion Categoria" << std::endl;
    std::string categoria;
    do {
        std::cout << "Ingresa categoria del libro:" << std::endl;
        std::getline(std::cin, categoria);

        if (!categoria.empty()) break;

        std::cout << "Ingrese categoria";
    } while (true);

    Categoria categoria1(categoria, 0);
    return categoria1;
}
