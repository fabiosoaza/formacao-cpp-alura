//
// Created by fabio on 11/18/23.
//

#pragma once

#include "Conta.hpp"

namespace conta {
    class ContaCorrente final : public Conta {

    public:
        ContaCorrente(pessoa::Pessoa *titular);

        float valorTarifa() override;

        void transferir(Conta &conta, float valor);

    };

}