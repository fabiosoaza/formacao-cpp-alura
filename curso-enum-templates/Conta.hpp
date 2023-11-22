#pragma once

#include <string>
#include "Pessoa.hpp"
#include "Documento.hpp"
#include <iostream>
#include <utility>
#include <variant>

namespace conta {
    class Conta {

    public :
        enum ResultadoSaque {
            SaqueComSucesso, ValorNegativo, SaldoInsuficiente
        };

        enum ErroDeposito {
             ValorDepositoNegativo
        };


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

        virtual std::string toString() const;

        //metodo abstrato puro
        virtual float valorTarifa() const = 0;

    public:
        Conta(pessoa::Pessoa *titular);

        virtual ~Conta();

        std::pair<ResultadoSaque, float> sacar(float valor);

        std::variant<ErroDeposito, float> depositar(float valor);

        void operator+=(float valor);

        float recuperaSaldo() const;

        std::string recuperaNumeroConta() const;

        const pessoa::Pessoa *getTitular() const;

        friend std::ostream &operator<<(std::ostream &out, const Conta &conta);

        bool operator < (const Conta & conta );


    private:
        static std::string formatarNumeroConta(int numero);
    };
}