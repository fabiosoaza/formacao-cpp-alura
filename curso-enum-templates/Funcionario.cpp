//
// Created by fabio on 11/18/23.
//
#include <iostream>
#include "Funcionario.hpp"
#include <sstream>
#include <string>

pessoa::Funcionario::Funcionario(const std::string &nome, const documento::Cpf &cpf, float salario, calendario::DiaSemana diaPagamento) : Pessoa(nome, cpf),
                                                                                   salario(salario),diaPagamento(diaPagamento) {}

float pessoa::Funcionario::getSalario() const {
    return salario;
}


std::string pessoa::Funcionario::toString() const {
    std::ostringstream output;
    output << Pessoa::toString();
    output << "*  salario   : " << salario << std::endl;
    output << "*  bonificacao   : " << bonificacao() << std::endl;
    output << "*  dia pagamento   : " << calendario::toString(diaPagamento) << std::endl;
    auto str = output.str();
    return str;
}

calendario::DiaSemana pessoa::Funcionario::getDiaPagamento() const {
    return diaPagamento;
}











