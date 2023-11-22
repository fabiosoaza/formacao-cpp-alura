#include <iostream>
#include <array>
#include "imprime_erros.hpp"

void forca::imprime_erros(std::array<char, 5> &chutes_errados) {
    std::cout << "Chutes errados: ";
    for (char letra: chutes_errados) {
        std::cout << letra << " ";
    }
    std::cout << std::endl;
}
