//
// Created by fabio on 11/18/23.
//
#pragma once
#include "Funcionario.hpp"

namespace pessoa {
    class Caixa : public Funcionario {

    public:
        Caixa(const std::string &nome, const documento::Cpf &cpf, float salario, calendario::DiaSemana diaPagamento);

        float bonificacao() const override;

    };

}