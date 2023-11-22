#pragma once

#include <string>
#include "Pessoa.hpp"

namespace conta {
    class Conta {

    private:
        static int numeroContas;

    private:
        std::string numeroConta;
        pessoa::Pessoa *titular;  // Agora, usando um ponteiro para Pessoa

    private:
        float saldo;

    public:
        static int totalContas();

    public:
        virtual void imprimir();

        //metodo abstrato puro
        virtual float valorTarifa() = 0;

    public:
        Conta(pessoa::Pessoa *titular);

        virtual ~Conta();

        void sacar(float valor);

        void depositar(float valor);

        float recuperaSaldo() const;

        std::string recuperaNumeroConta() const;

        const pessoa::Pessoa *getTitular() const;

    private:
        static std::string formatarNumeroConta(int numero);
    };
}