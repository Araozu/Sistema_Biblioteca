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
    s.run();
    return 0;
}
