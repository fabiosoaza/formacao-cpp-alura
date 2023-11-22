//
// Created by fabio on 11/18/23.
//

#include "Titular.hpp"
#include <iostream>
#include "Pessoa.hpp"

pessoa::Pessoa::Pessoa(std::string nome, Cpf cpf) : nome(nome), cpf(cpf) {

}

void pessoa::Pessoa::imprimir() const{
    std::cout << "*  cpf   : " << cpf.getNumero() << std::endl;
    std::cout << "*  nome  : " << nome << std::endl;
}

const std::string &pessoa::Pessoa::getNome() const {
    return nome;
}

const Cpf &pessoa::Pessoa::getCpf() const {
    return cpf;
}