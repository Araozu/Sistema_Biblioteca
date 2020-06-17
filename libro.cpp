//
// Created by Fernando on 04/06/2020.
//

#include "libro.h"

Libro::Libro(int _codigo, std::string _nombre, Autor _autor, std::string _fechaPublicacion, std::string _tema)
        : autor(std::__cxx11::string(), std::__cxx11::string(), 0, 0, std::__cxx11::string()) {
    codigo = _codigo;
    nombre = _nombre;
    autor = _autor;
    fechaPublicacion = _fechaPublicacion;
    tema = _tema;
}

int Libro::getCodigo() const{
    return codigo;
}   

void Libro::setCodigo(int codigo){
    Libro::codigo = codigo;
}   

std::string Libro::getNombre() const{
    return nombre;
}

void Libro::setNombre(std::string nombre){
    Libro::nombre = nombre;
}
   
Autor Libro::getAutor() const{
    return autor;
}
    
void Libro::setAutor(Autor autor){
    Libro::autor = autor;
}
    
std::string Libro::getFechaPublicacion() const{
    return fechaPublicacion;
}
    
void Libro::setFechaPulicacion(std::string fechaPublicacion){
    Libro::fechaPublicacion = fechaPublicacion;
}

std::string Libro::getTema() const{
    return tema;
}
    
void Libro::setTema(std::string tema){
    Libro::tema = tema;
}
