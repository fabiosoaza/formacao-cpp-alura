//
// Created by fabio on 11/18/23.
//

#include "Caixa.hpp"

pessoa::Caixa::Caixa(const std::string &nome, const documento::Cpf &cpf, float salario, calendario::DiaSemana diaPagamento) : Funcionario(nome, cpf, salario, diaPagamento) {}

float pessoa::Caixa::bonificacao() const {
    return getSalario() * 0.1f;
}
