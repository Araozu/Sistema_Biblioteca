//
// Created by Fernando on 04/06/2020.
//

#include "almacen.h"

Almacen::Almacen(int _cantidadLibros, int _numeroEstante, int _numeroPasillo){
	cantidadLibros = _cantidadLibros;
	numeroEstante = _numeroEstante;
	numeroPasillo = _numeroPasillo;
	
}
int Almacen::getCantidadLibros()const{
return cantidadLibros;

}
void Almacen :: setCantidadLibros(int cantidadLibros){
	Almacen ::cantidadLibros=cantidadLibros;
}

int Almacen :: getNumeroEstante()const{
return numeroEstante;
}
void Almacen::setNumeroEstante(int numeroEstante){
	Almacen::numeroEstante = numeroEstante;
}
int Almacen::getNumeroPasillo()const{
return numeroPasillo;
}
void Almacen::setNumeroPasiillo(int numeroPasillo){
	Almacen::numeroPasillo = numeroPasillo;
}
