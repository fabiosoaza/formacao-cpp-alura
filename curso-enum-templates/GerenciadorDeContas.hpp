//
// Created by fabio on 11/18/23.
//

#pragma once

#include <vector>
#include <memory>
#include <optional>
#include "Conta.hpp"
#include "AutenticavelSenha.hpp"

namespace cadastro {



    class GerenciadorDeContas {

    private :
        std::vector<conta::Conta *> contas;

    public:
        void salvar(conta::Conta &conta);
        void operator += (conta::Conta &conta);

        std::optional<conta::Conta *> buscarContaPorNumero(std::string numeroConta);

        void gerar_relatorio();

        void efetuarLogin(Autenticavel *alguem, std::string senha);

    };

}