
#include "Cpf.hpp"

const std::string &documento::Cpf::getNumero() const {
    return numero;
}

documento::Cpf::Cpf(std::string numero) : numero(numero) {

}

bool documento::Cpf::valido() const{
    return true;
}
