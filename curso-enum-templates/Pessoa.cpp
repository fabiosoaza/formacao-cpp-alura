//
// Created by fabio on 11/18/23.
//

#include "Titular.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include "Pessoa.hpp"

pessoa::Pessoa::Pessoa(std::string nome, documento::Cpf cpf) : nome(nome), documento(cpf) {

}

void pessoa::Pessoa::imprimir() const{
    std::cout << toString();
}

std::string pessoa::Pessoa::toString() const {
    std::ostringstream output;
    output << "*  cpf   : " << documento.getNumero() << std::endl;
    output << "*  nome  : " << nome << std::endl;
    auto str = output.str();
    return str;
}

const std::string &pessoa::Pessoa::getNome() const {
    return nome;
}

const documento::Cpf &pessoa::Pessoa::getDocumento()  const {
    return documento;
}

