cmake_minimum_required(VERSION 3.12)
project(SistemaBiblioteca)

set(CMAKE_CXX_STANDARD 14)

add_executable(SistemaBiblioteca main.cpp libro.cpp libro.h Persona/persona.cpp Persona/persona.h Persona/autor.cpp Persona/autor.h prestamo.cpp prestamo.h almacen.cpp almacen.h sistema.cpp sistema.h Persona/cliente.cpp Persona/cliente.h categoria.cpp categoria.h Utils/utils.cpp Utils/utils.h)
