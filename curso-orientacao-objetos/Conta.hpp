#pragma once

#include <string>
#include "Titular.hpp"
class Conta {

private:
    static int numeroContas;

private:
    std::string numeroConta;
    Titular titular;
public:
    const Titular &getTitular() const;

private:
    float saldo;


public:
    //Conta() = delete;
    Conta(Titular titular);
    ~Conta();//destructor executado quando variavel sai de escopo

    void sacar(float valor);

    void depositar(float valor);

    void imprimir();

    float recuperaSaldo() const;

    std::string recuperaNumeroConta() const;
    static int totalContas();

private:
    static std:: string formatarNumeroConta(int numero);



};