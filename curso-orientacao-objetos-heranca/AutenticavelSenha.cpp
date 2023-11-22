//
// Created by fabio on 11/18/23.
//

#include "AutenticavelSenha.hpp"

AutenticavelSenha::AutenticavelSenha(std::string senha) : senha(senha) {

}


const std::string &AutenticavelSenha::getSenha() const {
    return senha;
}

bool AutenticavelSenha::autenticar(std::string senha) const {
    return senha == this->senha;
}

