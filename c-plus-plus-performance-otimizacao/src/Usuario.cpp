#include "Usuario.hpp"

Usuario::Usuario(std::string nome): nome(nome)
{
}

std::string Usuario::recuperaNome() const
{
    return nome;
}

 std::string Usuario::recuperaPrimeiroNome() const{
    //retorna o maximo de size_t se não encontrado
    auto pos = nome.find(' ');
     return nome.substr(0, pos);
}
