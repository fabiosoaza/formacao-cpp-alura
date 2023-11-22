//
// Created by fabio on 11/18/23.
//

#include "ContaCorrente.hpp"
#include "PercentualSaque.hpp"
conta::ContaCorrente::ContaCorrente(pessoa::Pessoa*titular) : Conta(titular) {

}

float conta::ContaCorrente::valorTarifa() const {
    return PercentualSaque<5>().getPercentual();
}

void conta::ContaCorrente::transferir(Conta &destino, float valor) {
    sacar(valor);
    destino.depositar(valor);
}

void conta::ContaCorrente::operator+=(conta::ContaCorrente &origem) {
    origem.transferir(*this, origem.recuperaSaldo()/2);
}
