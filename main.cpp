// YML_header.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
