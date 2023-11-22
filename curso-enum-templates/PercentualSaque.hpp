//
// Created by fabio on 11/19/23.
//

#pragma once

/*
 * Teste de template recebendo valores resolvidos em tempo de compilação
 * */
template<int PercentualTarifa>
class PercentualSaque {

public:
    float getPercentual() {
        return PercentualTarifa / 100.0f;
    }

};