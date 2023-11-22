#include <iostream>
#include "Conta.hpp"
#include "GerenciadorDeContas.hpp"

using namespace std;

void exibeSaldo(const Conta &conta) {
    std::cout << "Saldo da  conta : " << conta.recuperaSaldo() << std::endl;

}

int main() {

    GerenciadorDeContas contas;

    //aloca na stack
    Titular fabio("Aristóteles", Cpf("123.456.789-10"));
    Conta conta1(fabio);
    conta1.depositar(10);
    contas.salvar(conta1);

    Cpf *cpf = new Cpf("999.999.999-99") ;//equivalente malloc
    std::cout << "Cpf aleatorio: "<< cpf->getNumero() << std::endl;
    delete cpf;//equivalent free

    //conversao implicita string em cpf
    Conta conta2(Titular("Sófocles", string("123.456.789-11")));
    conta2.depositar(20);
    contas.salvar(conta2);

    Conta conta3(Titular("Sócrates", string("000.000.000-00")));
    conta3.depositar(30);
    contas.salvar(conta3);

    contas.gerar_relatorio();


    return 0;
}
