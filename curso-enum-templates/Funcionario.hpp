#pragma once

#include <string>

#include "Cpf.hpp"
#include "Pessoa.hpp"

#include "DiaSemana.hpp"

namespace pessoa {

class Funcionario : public pessoa::Pessoa{

    private:
        float salario;
        //0 - Domingo, 1- Segunda ...
        calendario::DiaSemana diaPagamento;

    public:
        Funcionario(const std::string &nome, const documento::Cpf &cpf, float salario, calendario::DiaSemana diaPagamento);


        float getSalario() const;


        std::string toString() const override;

        virtual float bonificacao() const = 0;

        calendario::DiaSemana getDiaPagamento() const;

    };


}