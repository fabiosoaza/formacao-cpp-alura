//
// Created by fabio on 11/18/23.
//

#pragma once

#include "Cpf.hpp"
#include <string>

namespace pessoa {
    class Pessoa {

    protected:
        Cpf cpf;
        std::string nome;
    public:
        Pessoa(std::string nome, Cpf cpf);

        const std::string &getNome() const;

        const Cpf &getCpf() const;

        virtual void imprimir() const;
    };

}