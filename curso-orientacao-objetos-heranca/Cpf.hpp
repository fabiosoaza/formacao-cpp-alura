
#pragma once

#include <string>

class Cpf {

private :
    std::string numero;
public:
    explicit Cpf( std::string numero);
    const std::string &getNumero() const;
    bool valido();


};
