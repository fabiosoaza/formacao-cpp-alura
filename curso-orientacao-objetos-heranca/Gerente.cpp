//
// Created by fabio on 11/18/23.
//

#include "Gerente.hpp"

pessoa::Gerente::Gerente(const std::string &nome, const Cpf &cpf, float salario, std::string  senha) : Funcionario(nome, cpf, salario),
                                                                                               AutenticavelSenha(senha) {}

float pessoa::Gerente::bonificacao() const {
    return getSalario() * 0.5f;
}
