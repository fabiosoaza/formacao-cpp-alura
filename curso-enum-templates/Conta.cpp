#include <iostream>
#include <sstream>
#include <string>
#include "Conta.hpp"
#include <variant>



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

std::pair<conta::Conta::ResultadoSaque, float> conta::Conta::sacar(float valor) {
    if (valor < 0) {
        return std::make_pair(ValorNegativo, saldo);
    }

    float valor_tarifa = valorTarifa();
    float valor_sacar = valor + (valor_tarifa * valor);

    if (saldo < valor_sacar) {
        return std::make_pair(SaldoInsuficiente, saldo);
    }

    saldo -= valor_sacar;
    return std::make_pair(SaqueComSucesso, saldo);
}


std::variant<conta::Conta::ErroDeposito, float> conta::Conta::depositar(float valor) {
    if (valor <= 0) {
        return ValorDepositoNegativo;
    }
    saldo += valor;
    return saldo;
}

void conta::Conta::imprimir() {
    std::cout << toString();
}


std::string conta::Conta::toString() const {
    std::ostringstream output;
    output << "*  conta : " << numeroConta << std::endl;

    if (titular) {
        output << titular->toString();
    } else {
        output << "*  titular : (titular não disponível)" << std::endl;
    }

    output << "*  saldo :  " << saldo << std::endl;
    output << "*  tarifa do saque :  " << valorTarifa() << std::endl;
    auto str = output.str();
    return str;
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

void conta::Conta::operator+=(float valor) {
    depositar(valor);
}

bool conta::Conta::operator < (const conta::Conta &conta) {
    return this->saldo < conta.saldo;
}
