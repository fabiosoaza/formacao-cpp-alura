//
// Created by fabio on 11/18/23.
//

#pragma once

#include <string>
#include "Autenticavel.hpp"

class AutenticavelSenha : public Autenticavel {

private :
    std::string senha ;

public :
    AutenticavelSenha(std::string senha);
    bool autenticar(std::string senha) const override;

    const std::string &getSenha() const;

};

