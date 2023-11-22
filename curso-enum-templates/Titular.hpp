#pragma once

#include <string>
#include "Cpf.hpp"
#include "Pessoa.hpp"
#include "AutenticavelSenha.hpp"

namespace pessoa {
class Titular : public Pessoa, public AutenticavelSenha {

    public:

        Titular(std::string, documento::Cpf cpf, std::string senha);


    };

}