//
// Created by Dell on 18/06/2020.
//

#ifndef SISTEMABIBLIOTECA_CATEGORIA_H
#define SISTEMABIBLIOTECA_CATEGORIA_H

#include "iostream"

class Categoria {
private:
    std::string nombre;
    int id;

public:
    Categoria(std::string _nombre, int _id);

    std::string getNombre() const;

    void setNombre(std::string nombre);

    int getId() const;
    
	void setId(int  id);
	
    std::string toCSV();

    static Categoria fromCSV(std::string csv);
    
    static Categoria crearCategoriaPorConsola();

};

#endif //SISTEMABIBLIOTECA_CATEGORIA_H
