#include <iostream>
#include "Persona/persona.h"

int main() {
    std::string csv = "Juan,Perez,837485749,999495939,Av. Parra 2505";
    Persona p = Persona::fromCSV(csv);

    std::cout << "Hola mundo" << std::endl;
    return 0;
}
