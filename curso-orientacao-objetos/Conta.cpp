#include <iostream>
#include "Conta.hpp"
#include "Titular.hpp"

/**
Conta::Conta(std::string numeroConta, std::string cpfTitular, std::string nomeTitular) {
    this->numeroConta = numeroConta;
    this->cpfTitular = cpfTitular;
    this->nomeTitular = nomeTitular;
    this->saldo = 0;
}*/

int Conta::numeroContas = 0;

int Conta::totalContas() {
    return numeroContas;
}


Conta::Conta(Titular titular) :
        titular(titular),
        numeroConta(formatarNumeroConta(++numeroContas)),
        saldo(0) {

}


Conta::~Conta() {
    //   numeroContas--;
    //ao fazer uma passagem de parametros do objeto contas é feita uma cópia que não executa o construtor
    //que será destruida dentro do contexto do método e fará o decremento erroneamente
}


std::string Conta::recuperaNumeroConta() const {
    return numeroConta;
}

float Conta::recuperaSaldo() const {
    return saldo;
}

void Conta::sacar(float valor) {
    if (valor < 0 && valor > saldo) {
        return;
    }
    saldo -= valor;
}

void Conta::depositar(float valor) {
    if (valor <= 0) {
        return;
    }
    saldo += valor;
}

void Conta::imprimir() {
    std::cout << "*********************************************************" << std::endl;
    std::cout << "*  conta : " << numeroConta << std::endl;
    titular.imprimir();
    std::cout << "*  saldo :  " << saldo << std::endl;
    std::cout << "*********************************************************" << std::endl;

}

const Titular &Conta::getTitular() const {
    return titular;
}

std::string Conta::formatarNumeroConta(int numero) {
    std::string numeroDeContaFormatado = std::to_string(numero);

    while (numeroDeContaFormatado.length() < 6) {
        numeroDeContaFormatado.insert(0, "0");
    }

    numeroDeContaFormatado.append("-2");
    return numeroDeContaFormatado;
}
