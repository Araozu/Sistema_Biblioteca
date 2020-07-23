cmake_minimum_required(VERSION 3.12)
project(SistemaBiblioteca)

set(CMAKE_CXX_STANDARD 14)

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/data)
# file(GLOB MY_FILES "data/*.csv")
# file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/data)

add_executable(SistemaBiblioteca main.cpp libro.cpp libro.h Persona/persona.cpp Persona/persona.h Persona/autor.cpp Persona/autor.h prestamo.cpp prestamo.h almacen.cpp almacen.h sistema.cpp sistema.h Persona/cliente.cpp Persona/cliente.h categoria.cpp categoria.h Excepciones/excepcion.cpp Excepciones/excepcion.h Excepciones/excepcionCsvIncorrecto.cpp Excepciones/excepcionCsvIncorrecto.h Excepciones/excepcionCargaDatos.cpp Excepciones/excepcionCargaDatos.h Excepciones/excepcionAutorNoEncontrado.cpp Excepciones/excepcionAutorNoEncontrado.h)

add_custom_command(
        TARGET SistemaBiblioteca POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/data/
                ${CMAKE_CURRENT_BINARY_DIR}/data/
)
