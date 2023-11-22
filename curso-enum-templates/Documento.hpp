//
// Created by fabio on 11/19/23.
//

#pragma once

#include <string>

namespace documento {

    struct Documento {

        virtual ~Documento() = default;

        virtual const std::string &getNumero() const = 0;

        virtual bool valido() const = 0;
    };

}