cmake_minimum_required(VERSION 3.26)
project(curso_orientacao_objetos)

set(CMAKE_CXX_STANDARD 17)

add_executable(curso_orientacao_objetos main.cpp
        Conta.hpp
        Conta.cpp
        Titular.cpp
        Titular.hpp
        Cpf.cpp
        Cpf.hpp
        GerenciadorDeContas.cpp
        GerenciadorDeContas.hpp)
