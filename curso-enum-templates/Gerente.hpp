//
// Created by fabio on 11/18/23.
//

#pragma once

#include "Funcionario.hpp"
#include "AutenticavelSenha.hpp"

namespace pessoa {
    class Gerente : public Funcionario, AutenticavelSenha {

    public:
        Gerente(const std::string &nome, const documento::Cpf &cpf, float salario, std::string senha, calendario::DiaSemana diaPagamento);

    private:
        float bonificacao() const override;
    };

}