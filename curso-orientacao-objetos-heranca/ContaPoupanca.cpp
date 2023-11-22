//
// Created by fabio on 11/18/23.
//

#include <iostream>
#include "ContaPoupanca.hpp"



float conta::ContaPoupanca::valorTarifa()  {
    return  0.03;
}

conta::ContaPoupanca::ContaPoupanca( pessoa::Pessoa * titular): Conta(titular) {

}
