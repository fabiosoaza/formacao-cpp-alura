//
// Created by fabio on 11/19/23.
//

#include <algorithm>
#include "Avaliador.hpp"

;

float Avaliador::recuperarMaiorValor() const {
    return maiorValor;
}

void Avaliador::avaliar(Leilao leilao) {
    auto lances = leilao.recuperaLances();
    if(lances.empty() ){
        return;
    }
    menorValor = lances.front().recuperaValor();
    maiorValor = lances.front().recuperaValor();
    for(const auto& lance: lances){
        if(lance.recuperaValor() > maiorValor){
            maiorValor = lance.recuperaValor();
        }
        if(lance.recuperaValor() < menorValor){
            menorValor = lance.recuperaValor();
        }
    }
    std::sort(lances.begin(), lances.end(), ordenaLances);
    auto tamanho = lances.size() > 3 ? 3 : lances.size();
    maiores3Lances = std::vector<Lance>(lances.begin(), lances.begin()+tamanho);

}

float Avaliador::recuperarMenorValor() const {
    return menorValor;
}

std::vector<Lance> Avaliador::getMaiores3Lances() const {
    return maiores3Lances;
}

bool Avaliador::    ordenaLances(const Lance & lance1, const Lance & lance2) {
    return lance1.recuperaValor() > lance2.recuperaValor();
}
