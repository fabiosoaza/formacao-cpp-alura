//
// Created by fabio on 11/18/23.
//

#include "Caixa.hpp"

pessoa::Caixa::Caixa(const std::string &nome, const Cpf &cpf, float salario) : Funcionario(nome, cpf, salario) {}

float pessoa::Caixa::bonificacao() const {
    return getSalario() * 0.1f;
}
