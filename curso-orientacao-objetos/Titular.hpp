#pragma once

#include <string>
#include "Cpf.hpp"

class Titular {

private:
    std::string nome;
    Cpf cpf;

public:
    Titular(std::string nome, Cpf cpf);

    const std::string &getNome() const;

    const Cpf &getCpf() const;

    void imprimir() const;

};

