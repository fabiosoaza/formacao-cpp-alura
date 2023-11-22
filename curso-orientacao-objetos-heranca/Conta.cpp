#include <iostream>
#include "Conta.hpp"
#include "Titular.hpp"



int conta::Conta::numeroContas = 0;

int conta::Conta::totalContas() {
    return numeroContas;
}

conta::Conta::Conta(pessoa::Pessoa* titular) : titular(titular), numeroConta(formatarNumeroConta(++numeroContas)), saldo(0) {}

conta::Conta::~Conta() {

}

std::string conta::Conta::recuperaNumeroConta() const {
    return numeroConta;
}

float conta::Conta::recuperaSaldo() const {
    return saldo;
}

void conta::Conta::sacar(float valor) {
    if (valor < 0) {
        return;
    }

    float valor_tarifa = valorTarifa();
    float valor_sacar = valor + (valor_tarifa * valor);

    if (saldo < valor_sacar) {
        return;
    }

    saldo -= valor_sacar;
}


void conta::Conta::depositar(float valor) {
    if (valor <= 0) {
        return;
    }
    saldo += valor;
}

void conta::Conta::imprimir() {
    std::cout << "*********************************************************" << std::endl;
    std::cout << "*  conta : " << numeroConta << std::endl;

    if (titular) {
        titular->imprimir();
    } else {
        std::cout << "*  titular : (titular não disponível)" << std::endl;
    }

    std::cout << "*  saldo :  " << saldo << std::endl;
    std::cout << "*  tarifa do saque :  " << valorTarifa() << std::endl;
    std::cout << "*********************************************************" << std::endl;
}

const pessoa::Pessoa* conta::Conta::getTitular() const {
    return titular;
}

std::string conta::Conta::formatarNumeroConta(int numero) {
    std::string numeroDeContaFormatado = std::to_string(numero);

    while (numeroDeContaFormatado.length() < 6) {
        numeroDeContaFormatado.insert(0, "0");
    }

    numeroDeContaFormatado.append("-2");
    return numeroDeContaFormatado;
}