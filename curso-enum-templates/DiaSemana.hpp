#pragma once

namespace calendario {
//pode extender tipos primitivos
    enum class DiaSemana : unsigned short {
        Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado

    };

    //função inline para que a implementação possa ser definida no cabecalho por simplicidade
    inline std::string toString(DiaSemana valor) {
        switch (valor) {
            case DiaSemana::Domingo:
                return "Domingo";
            case DiaSemana::Segunda:
                return "Segunda";
            case DiaSemana::Terca:
                return "Terca";
            case DiaSemana::Quarta:
                return "Quarta";
            case DiaSemana::Quinta:
                return "Quinta";
            case DiaSemana::Sexta:
                return "Sexta";
            case DiaSemana::Sabado:
                return "Sabado";
            default:
                return "Valor Desconhecido";
        }
    }

}