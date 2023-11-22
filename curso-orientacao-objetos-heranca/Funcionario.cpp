//
// Created by fabio on 11/18/23.
//
#include <iostream>
#include "Funcionario.hpp"

pessoa::Funcionario::Funcionario(const std::string &nome, const Cpf &cpf, float salario) : Pessoa(nome, cpf),
                                                                                   salario(salario) {}

float pessoa::Funcionario::getSalario() const {
    return salario;
}

void pessoa::Funcionario::imprimir() const {
   Pessoa::imprimir();
    std::cout << "*  salario   : " << salario << std::endl;
    std::cout << "*  bonificacao   : " << bonificacao() << std::endl;
}











