//
// Created by fabio on 11/18/23.
//

#include <iostream>
#include <algorithm>
#include "GerenciadorDeContas.hpp"
#include "Conta.hpp"
#include "Pessoa.hpp"

void cadastro::GerenciadorDeContas::salvar(conta::Conta &conta) {
    contas.push_back(&conta);
}



void cadastro::GerenciadorDeContas::gerar_relatorio() {
    std::cout << "****************************************************************" << std::endl;
    std::cout << "* Relatório de contas " << std::endl;
    std::cout << "* Numero de contas: " << contas.size() << std::endl;
    for (const auto contaPtr: contas) {
        std::cout << "****************************************************************" << std::endl;
        std::cout << contaPtr->toString();
    }
    std::cout << "****************************************************************" << std::endl;
}

void cadastro::GerenciadorDeContas::efetuarLogin(Autenticavel *alguem, std::string senha) {
    if (alguem->autenticar(senha)) {
        std::cout << "Login efetuado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao fazer login" << std::endl;
    }
}

void cadastro::GerenciadorDeContas::operator+=(conta::Conta &conta) {
    salvar(conta);
}

std::optional<conta::Conta *> cadastro::GerenciadorDeContas::buscarContaPorNumero(std::string numeroConta) {
    for (const auto contaPtr: contas) {
        if(contaPtr->recuperaNumeroConta() == numeroConta){
            return  std::optional<conta::Conta *>(contaPtr);
        }
    }
    //{} equivalente std::optional<conta::Conta *>()
    return {};
}



