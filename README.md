# yml_header_string
yml_header_string


Ejemplo de ejecución:

#include <iostream>
#include"YML_readchange_parameter.hpp"


int main()
{
    std::cout << "Esto es un ejemplo de uso\n";
    changeparameter("parametro1", "1", "C:/Users/Héctor/source/repos/YML_header");
    std::cout << "Valor parametro 1 (folder):" << readvalue("parametro1", "C:/Users/Héctor/source/repos/YML_header") << "\n";
    std::cout << "Valor parametro 1 (file) :" << readvaluefromfile("parametro1", "C:/Users/Héctor/source/repos/YML_header", "ejemplo_yml.yml") << "\n";
    changeparameter("parametro1", "2", "C:/Users/Héctor/source/repos/YML_header");
    std::cout << "Valor mod (folder): " << readvalue("parametro1", "C:/Users/Héctor/source/repos/YML_header") << "\n";
    changeparameterinfile("parametro1", "3", "C:/Users/Héctor/source/repos/YML_header/ejemplo_yml.yml");
    std::cout << "Valor mod(file): " << readvalue("parametro1", "C:/Users/Héctor/source/repos/YML_header") << "\n";
}



