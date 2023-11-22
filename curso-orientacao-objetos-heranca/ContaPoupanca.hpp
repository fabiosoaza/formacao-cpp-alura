

#pragma once

#include "Conta.hpp"

namespace conta {
    class ContaPoupanca final : public Conta {
    public:


        ContaPoupanca(pessoa::Pessoa *titular);

        float valorTarifa() override;
    };

}