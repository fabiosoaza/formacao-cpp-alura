//
// Created by fabio on 11/18/23.
//

#pragma once

#include <vector>
#include <memory>
#include "Conta.hpp"
#include "AutenticavelSenha.hpp"

namespace cadastro {
    class GerenciadorDeContas {

    private :
        std::vector<conta::Conta *> contas;

    public:
        void salvar(conta::Conta &conta);

        void excluir(const std::string &cpf);

        void gerar_relatorio();

        void efetuarLogin(Autenticavel *alguem, std::string senha);

    };

}