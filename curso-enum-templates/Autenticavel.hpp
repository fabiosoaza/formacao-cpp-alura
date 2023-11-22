//
// Created by fabio on 11/18/23.
//

#pragma once

#include <string>

/*
 * Classe puramente virtual equivalente a uma interface
 * */
struct Autenticavel {
    virtual bool autenticar(std::string senha) const = 0;
};