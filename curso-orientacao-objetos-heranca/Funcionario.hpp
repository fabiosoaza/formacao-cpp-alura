//
// Created by fabio on 11/18/23.
//
#include <string>
#include "Cpf.hpp"
#include "Pessoa.hpp"
#pragma once

namespace pessoa {

    class Funcionario : public pessoa::Pessoa {

    private:
        float salario;

    public:
        Funcionario(const std::string &nome, const Cpf &cpf, float salario);


        float getSalario() const;


        void imprimir() const override;

        virtual float bonificacao() const = 0;

    };


}