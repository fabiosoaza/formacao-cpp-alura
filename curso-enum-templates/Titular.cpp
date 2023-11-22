    #include <iostream>
    #include <string>
    #include "Titular.hpp"

    pessoa::Titular::Titular(std::string nome, documento::Cpf cpf, std::string senha): Pessoa(nome,cpf), AutenticavelSenha(senha) {

    }
