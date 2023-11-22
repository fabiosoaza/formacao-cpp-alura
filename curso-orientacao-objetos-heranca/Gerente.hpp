//
// Created by fabio on 11/18/23.
//

#pragma once

#include "Funcionario.hpp"
#include "AutenticavelSenha.hpp"

namespace pessoa {
    class Gerente : public Funcionario, AutenticavelSenha {

    public:
        Gerente(const std::string &nome, const Cpf &cpf, float salario, std::string senha);

    private:
        float bonificacao() const override;
    };

}