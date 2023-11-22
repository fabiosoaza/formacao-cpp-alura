
#pragma once

#include <string>
#include "Documento.hpp"

namespace documento {
    class Cpf : public Documento {

    private :
        std::string numero;
    public:
        explicit Cpf(std::string numero);

        const std::string &getNumero() const override;

        bool valido() const override ;


    };
}