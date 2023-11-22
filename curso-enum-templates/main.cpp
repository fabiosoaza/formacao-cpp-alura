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
#include "Pessoa.hpp"
;

using namespace std;
using namespace pessoa;
using namespace conta;
using namespace cadastro;
using namespace calendario;
using namespace documento;

std::ostream &pessoa::operator<<(std::ostream &out, const pessoa::Pessoa &pessoa) {
    return out << pessoa.toString();
}

//preciso informar o namespace conta pois foi definido dentro de conta
std::ostream &conta::operator<<(std::ostream &out, const conta::Conta &conta) {
    Pessoa *titular = conta.titular;
    out << "Titular: " << std::endl;
    out << *titular << std::endl;
    out << "Conta :" << conta.toString();
    return out;
}

void depositar(ContaCorrente *conta, int valor) {
    auto resDeposito = conta->depositar(valor);
    if (auto saldo = get_if<float>(&resDeposito)) {
        cout << "Deposito feito com sucesso. Saldo final  " << *saldo << endl;
    } else {
        auto error = get_if<conta::Conta::ErroDeposito>(&resDeposito);
        std::cout << "Erro " << *error << " ao fazer deposito do valor " << valor << endl;
    }
}


pair<conta::Conta::ResultadoSaque, float> sacar(ContaCorrente *conta, float valor) {
    auto res = conta->sacar(valor);
    //ou c++ 17
//    auto [result, saldo_final] = conta1->sacar(valorSaque);
    if (res.first == Conta::SaqueComSucesso) {
        cout << "Saque de " << valor << " realizado com sucesso! Novo Saldo: " << res.second << endl;
    } else if (res.first == Conta::SaldoInsuficiente) {
        cout << "Saldo da conta insuficiente para fazer o saque de " << valor << endl;
    } else if (res.first == Conta::ValorNegativo) {
        cout << "Valor a sacar deve ser maior que 0 " << valor << endl;
    }
    return res;
}

std::optional<conta::Conta *> buscarConta(GerenciadorDeContas &contas, const std::string &id) {
    cout << "Buscando conta com numero " << id << endl;
    auto opt = contas.buscarContaPorNumero(id);
    if (opt.has_value()) {
        cout << "Conta Encontrada : " << endl;
        cout << (*opt.value());
        cout << endl;
    } else {
        cout << "Conta com numero " << id << " não encontrada : " << endl;
    }
    return opt;
}

template<typename MeuTipo>
MeuTipo menor(const MeuTipo a, const MeuTipo b) {
    return a < b ? a : b;
}

int main() {

    GerenciadorDeContas contas;

    //aloca na stack
    Titular *fabio = new Titular("Aristóteles", Cpf("123.456.789-10"), "fabio");
    auto conta1 = new ContaCorrente(fabio);
    depositar(conta1, 10);
    contas.salvar((*conta1));
    depositar(conta1, 0);




    //conversao implicita string em cpf
    Titular *sofocles = new Titular("Sófocles", Cpf("123.456.789-11"), "sofocles");
    auto conta2 = new ContaCorrente(sofocles);
    conta2->depositar(20);
    contas.salvar((*conta2));

    Titular *socrates = new Titular("Sócrates", Cpf("000.000.000-00"), "socrates");
    auto conta3 = new ContaPoupanca(socrates);
    conta3->depositar(30);
    contas.salvar((*conta3));

    Titular *pitagoras = new Titular("Pitágoras", Cpf("111.111.111-11"), "pitagoras");
    auto conta4 = new ContaPoupanca(pitagoras);
    conta4->depositar(30);
    contas.salvar((*conta4));

    Funcionario *caixa = new Caixa("Caixa", Cpf("333.333.333-33"), 2000, DiaSemana::Quarta);
    auto conta5 = new ContaCorrente(caixa);
    conta5->depositar(300);
    contas.salvar((*conta5));

    Funcionario *gerente = new Gerente("Gerente", Cpf("444.444.444-44"), 12000, "gerente", DiaSemana::Terca);
    auto conta6 = new ContaPoupanca(gerente);
    conta6->depositar(12000);
    //deref do ponteiro
    (*conta6) += 33;
    contas.salvar((*conta6));

    Funcionario *segundoCaixa = new Caixa("Segundo caixa", Cpf("444.444.444-44"), 1500, DiaSemana::Terca);
    auto conta7 = new ContaCorrente(segundoCaixa);
    //deref do ponteiro
    //como não suporta sobrecarga é enecessario fazer o cast para chamar o valor metodo correto
    //poderia resolver deixando de usar auto e usar o tipo mais abstrato na declaracao
    (*(Conta *) conta7) += (1000);
    contas += (*conta7);
    //transfere metade do saldo da cc7 para a cc5
    (*conta5) += (*conta7);


    contas.gerar_relatorio();

    conta1->transferir((*conta5), 1);
    auto res = sacar(conta1, 0.5f);


    auto r = sacar(conta1, 100000);

    contas.gerar_relatorio();

    std::cout << "Teste erro Fabio " << std::endl;
    contas.efetuarLogin(fabio, "erro");

    std::cout << "Teste sucesso Fabio " << std::endl;
    contas.efetuarLogin(fabio, "fabio");

    std::cout << "Teste Sobrecarga cout " << std::endl;
    std::cout << "Pessoa : " << std::endl << (*gerente) << std::endl << "Conta : " << std::endl << (*conta6)
              << std::endl;

    //

    string id = "000005-2";
    auto contaEncontrada = buscarConta(contas, id);

    id = "42";
    auto contaInexistente = buscarConta(contas, id);

    //compara contas
    std::cout << "Teste templates" << std::endl;
    auto contaTemplate3 = buscarConta(contas, "000003-2");
    auto contaTemplate5 = buscarConta(contas, "000005-2");
    if (!contaTemplate3.has_value()) {
        std::cout << "Conta 000003-2 não encontrada " << std::endl;
    }
    if (!contaTemplate5.has_value()) {
        std::cout << "Conta 000005-2 não encontrada " << std::endl;
    }
    if (contaTemplate3.has_value() && contaTemplate5.has_value()) {
        std::cout << "Conta menor " << std::endl << *menor(contaTemplate5, contaTemplate3).value() << std::endl;
    }


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


