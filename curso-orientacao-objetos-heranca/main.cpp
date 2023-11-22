#include <iostream>
#include "Conta.hpp"
#include "GerenciadorDeContas.hpp"
#include "Funcionario.hpp"
#include "Pessoa.hpp"
#include "Titular.hpp"
#include "ContaPoupanca.hpp"
#include "ContaCorrente.hpp"
#include "Caixa.hpp"
#include "Gerente.hpp"

using namespace std;
using namespace pessoa;
using namespace conta;
using namespace cadastro;

void exibeSaldo(const Conta &conta) {
    std::cout << "Saldo da  conta : " << conta.recuperaSaldo() << std::endl;

}

int main() {

    GerenciadorDeContas contas;

    //aloca na stack
    Titular * fabio = new Titular("Aristóteles", Cpf("123.456.789-10"), "fabio");
    auto conta1 = new ContaCorrente(fabio);
    conta1->depositar(10);
    contas.salvar((*conta1));

    //conversao implicita string em cpf
    Titular *  sofocles = new Titular("Sófocles", Cpf("123.456.789-11"), "sofocles");
    auto conta2 = new ContaCorrente(sofocles);
    conta2->depositar(20);
    contas.salvar((*conta2));

    Titular *  socrates =  new Titular("Sócrates", Cpf("000.000.000-00"), "socrates");
    auto conta3 = new ContaPoupanca(socrates);
    conta3->depositar(30);
    contas.salvar((*conta3));

    Titular *  pitagoras = new Titular("Pitágoras", Cpf("111.111.111-11"), "pitagoras");
    auto conta4 = new ContaPoupanca(pitagoras);
    conta4->depositar(30);
    contas.salvar((*conta4));

    Funcionario *  caixa = new Caixa("Caixa", Cpf("333.333.333-33"), 2000);
    auto conta5 = new ContaPoupanca(caixa);
    conta5->depositar(300);
    contas.salvar((*conta5));

    Funcionario *  gerente = new Gerente("Gerente", Cpf("444.444.444-44"), 12000, "gerente");
    auto conta6= new ContaPoupanca(gerente);
    conta6->depositar(12000);
    contas.salvar((*conta6));

    contas.gerar_relatorio();

    conta1->transferir((*conta5), 1);
    contas.gerar_relatorio();

    std::cout <<"Teste erro Fabio "<< std::endl;
    contas.efetuarLogin(fabio, "erro");

    std::cout <<"Teste sucesso Fabio "<< std::endl;
    contas.efetuarLogin(fabio, "fabio");

    delete fabio;
    delete sofocles;
    delete socrates;
    delete pitagoras;
    delete caixa;
    delete gerente;

    delete conta1;
    delete conta2;
    delete conta3;
    delete conta4;
    delete conta5;
    delete conta6;

    return 0;
}
