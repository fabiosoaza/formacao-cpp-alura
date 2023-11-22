//
// Created by fabio on 11/18/23.
//

#include <iostream>
#include "GerenciadorDeContas.hpp"
#include "Conta.hpp"

void GerenciadorDeContas::salvar(Conta &conta) {
    contas.push_back(conta);

}

void GerenciadorDeContas::excluir(const std::string& cpf) {
    for (auto it = contas.begin(); it != contas.end();) {
        if (it->getTitular().getCpf().getNumero() == cpf) {
            it = contas.erase(it);
        } else {
            ++it;
        }
    }
}

void GerenciadorDeContas::gerar_relatorio() {
    std::cout << "Numero de contas: " << Conta::totalContas() << std::endl;
    for(Conta conta: contas){
        conta.imprimir();
    }
}
