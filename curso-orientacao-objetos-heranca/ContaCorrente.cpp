//
// Created by fabio on 11/18/23.
//

#include "ContaCorrente.hpp"

conta::ContaCorrente::ContaCorrente(pessoa::Pessoa *titular) : Conta(titular) {

}

float conta::ContaCorrente::valorTarifa() {
    return 0.05;
}

void conta::ContaCorrente::transferir(Conta &destino, float valor) {
    sacar(valor);
    destino.depositar(valor);
}
