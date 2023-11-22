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


void cadastro::GerenciadorDeContas::excluir(const std::string &cpf) {
    contas.erase(
            std::remove_if(contas.begin(), contas.end(), [&](const auto &conta) {
                return conta->getTitular()->getCpf().getNumero() == cpf;
            }),
            contas.end()
    );
}

void cadastro::GerenciadorDeContas::gerar_relatorio() {
    std::cout << "Numero de contas: " << contas.size() << std::endl;
    for (const auto contaPtr: contas) {
        contaPtr->imprimir();
    }
}

void cadastro::GerenciadorDeContas::efetuarLogin(Autenticavel * alguem, std::string senha) {
    if (alguem->autenticar(senha)) {
        std::cout << "Login efetuado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro ao fazer login" << std::endl;
    }
}


