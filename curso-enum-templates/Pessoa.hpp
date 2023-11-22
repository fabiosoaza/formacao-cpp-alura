//
// Created by fabio on 11/18/23.
//

#pragma once

#include "Cpf.hpp"
#include <string>
#include <iostream>
namespace pessoa {

    class Pessoa {

    protected:
        documento::Cpf documento;
        std::string nome;
    public:
        Pessoa(std::string nome, documento::Cpf cpf);

        const std::string &getNome() const;

        const documento::Cpf &getDocumento() const;

        virtual void imprimir() const;

        virtual std::string toString() const ;

        friend std::ostream &operator<<(std::ostream &out, const Pessoa &pessoa);

    };

}