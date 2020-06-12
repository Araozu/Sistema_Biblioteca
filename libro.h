//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_LIBRO_H
#define SISTEMABIBLIOTECA_LIBRO_H
#include <iostream>
#include "Persona/autor.h"

class Libro {
private:
    int codigo;
    std::string nombre;
    Autor autor;
    std::string fechaPublicacion;  // TODO: Cambiar a un objeto
    std::string tema;  // Biologia/Matematica/etc

public:
    Libro(int _codigo, std::string _nombre, Autor _autor, std::string _fechaPublicacion, std::string _tema);
    
    int getCodigo() const;
    
    void setCodigo(int codigo);
    
    std::string getNombre() const;
    
    void setNombre(std::string nombre);
    
    Autor getAutor() const;
    
    void setAutor(Autor autor);
    
    std::string getFechaPublicacion() const;
    
    void setFechaPulicacion(std::string fechaPublicacion);
    
    std::string getTema() const;
    
    void setTema(std::string tema);      
};


#endif //SISTEMABIBLIOTECA_LIBRO_H
