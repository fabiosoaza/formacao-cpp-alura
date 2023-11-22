#include <iostream>
#include "Titular.hpp"

Titular::Titular(std::string nome, Cpf cpf) : nome(nome), cpf(cpf) {

}

const std::string &Titular::getNome() const {
    return nome;
}

const Cpf &Titular::getCpf() const {
    return cpf;
}

void Titular::imprimir() const{
    std::cout << "*  cpf   : " << cpf.getNumero() << std::endl;
    std::cout << "*  nome  : " << nome << std::endl;
}
