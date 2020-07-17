//
// Created by Fernando on 04/06/2020.
//

#ifndef SISTEMABIBLIOTECA_PRESTAMO_H
#define SISTEMABIBLIOTECA_PRESTAMO_H
#include <iostream>

class Prestamo {
private:
    int codigoPrestamo;
    int codigoLibro;
    int dniCliente;
    std::string fechaPrestamo;
    std::string fechaDevolucion;
    bool devuelto;
public:
    int getCodigoPrestamo() const;

    void setCodigoPrestamo(int codigoPrestamo);

    void setDevuelto(bool devuelto);

public:
    Prestamo(int codigoPrestamo, int codigoLibro, int dniCliente, std::string fechaPrestamo,
            std::string fechaDevolucion, bool devuelto);

    int getCodigoLibro() const;

    void setCodigoLibro(int codigoLibro);

    int getDniCliente() const;

    void setDniCliente(int dniCliente);

    const std::string &getFechaPrestamo() const;

    bool isDevuelto() const;

    void setFechaPrestamo(const std::string &fechaPrestamo);

    const std::string &getFechaDevolucion() const;

    void setFechaDevolucion(const std::string &fechaDevolucion);

    std::string toCSV();

    static Prestamo fromCSV(std::string csv);
};


#endif //SISTEMABIBLIOTECA_PRESTAMO_H
