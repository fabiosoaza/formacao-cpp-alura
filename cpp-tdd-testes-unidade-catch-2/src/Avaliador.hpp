

#pragma once

#include "Leilao.hpp"
#include <vector>

class Avaliador {

private:
    float maiorValor = 0;
    float menorValor = 0;
    std::vector<Lance> maiores3Lances;
    static bool ordenaLances(const Lance &, const Lance &);

public:
    void avaliar(Leilao);

    float recuperarMaiorValor() const;
    float recuperarMenorValor() const;

    std::vector<Lance> getMaiores3Lances() const;
};


