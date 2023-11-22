

#pragma once

#include "Conta.hpp"
#include "Documento.hpp"

namespace conta {
class ContaPoupanca final : public Conta {
    public:


        ContaPoupanca(pessoa::Pessoa *titular);

        float valorTarifa() const override;
    };

}