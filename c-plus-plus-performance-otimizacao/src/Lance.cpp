#include "Lance.hpp"
#include <iostream>

Lance::Lance(Usuario usuario, float valor) : usuario(usuario), valor(valor) {
}

float Lance::recuperaValor() const {
    return valor;
}

std::string Lance::recuperaNomeUsuario() const {
    return usuario.recuperaNome();
}

Lance::Lance(const Lance &lance) : usuario(lance.usuario), valor(lance.valor) {
    std::cout << "Inicializando copia do lance com valor " << valor << std::endl;
}
