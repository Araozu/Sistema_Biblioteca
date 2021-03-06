#include <iostream>
#include <string>
#include "sistema.h"

int main(int argc, char** argv) {

    bool esAdmin = false;
    unsigned int posPassword = -1;
    for (int i = 0; i < argc; i++) {
        std::string s = argv[i];
        if (s == "--password") {
            posPassword = i + 1;
        } else if (i == posPassword && s == "8k9e7b20bp2ld8b") {
            std::cout << "Iniciando sesion como administrador." << std::endl;
            esAdmin = true;
        }
    }

    Sistema s(esAdmin);
    try {
        s.run();
    } catch (std::exception &e) {
        std::cerr << "Se encontro un error sin tratar. Se guardaran los cambios y se saldra." << std::endl;
        std::cerr << e.what();
        std::cout << "Presiona enter para continuar.";
        std::cin.ignore();
        std::cout << std::endl;
    }

    return 0;
}
