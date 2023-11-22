//
// Created by fabio on 11/18/23.
//

#include <iostream>
#include "ContaPoupanca.hpp"
#include "PercentualSaque.hpp"


float conta::ContaPoupanca::valorTarifa() const {
    return PercentualSaque<3>().getPercentual();;
}

conta::ContaPoupanca::ContaPoupanca( pessoa::Pessoa * titular): Conta(titular) {

}
