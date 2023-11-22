//
// Created by fabio on 11/18/23.
//

#pragma once

#include <vector>
#include "Conta.hpp"

class GerenciadorDeContas {

private :
    std::vector<Conta> contas;

public:
    void salvar(Conta & conta);
    void excluir(const std::string& cpf);
    void gerar_relatorio();

};

