//
// Created by fabio on 11/18/23.
//

#pragma once

#include "Conta.hpp"
#include "Documento.hpp"

namespace conta {
class ContaCorrente final : public Conta {

    public:
        ContaCorrente(pessoa::Pessoa *titular);

        float valorTarifa() const override;

        void transferir(Conta &conta, float valor);
        /**
         * Transfere metade do saldo da conta de origem paraa conta de destino
         * @param origem
         */
        void operator +=(ContaCorrente &origem);

    };

}