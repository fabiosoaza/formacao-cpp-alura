cmake_minimum_required(VERSION 3.26)
project(curso_enum_templates)

set(CMAKE_CXX_STANDARD 17)

add_executable(curso_enum_templates main.cpp
        Conta.hpp
        Conta.cpp
        Titular.cpp
        Titular.hpp
        Cpf.cpp
        Cpf.hpp
        GerenciadorDeContas.cpp
        GerenciadorDeContas.hpp
        Funcionario.cpp
        Funcionario.hpp
        Pessoa.cpp
        Pessoa.hpp
        ContaPoupanca.cpp
        ContaPoupanca.hpp
        ContaCorrente.cpp
        ContaCorrente.hpp
        Caixa.cpp
        Caixa.hpp
        Gerente.cpp
        Gerente.hpp
        AutenticavelSenha.cpp
        AutenticavelSenha.hpp
        Autenticavel.hpp
        DiaSemana.hpp
        Documento.hpp
        PercentualSaque.hpp
)
