
#include "Cpf.hpp"

const std::string &Cpf::getNumero() const {
    return numero;
}

Cpf::Cpf(std::string numero) : numero(numero) {

}

bool Cpf::valido() {
    return true;
}
