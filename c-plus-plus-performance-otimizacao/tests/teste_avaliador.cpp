

#define CATCH_CONFIG_MAIN


#include <sstream>
#include "../src/Avaliador.hpp"
#include <catch2/catch_all.hpp>

static Leilao leilaoVazio() {
    Leilao leilao("Fiat 147 0 KM");
    return leilao;
}

static Leilao leilaoOrdemCrescente(int menorLance, int maiorLance, int lanceIncremento) {
    auto leilao = leilaoVazio();

    for (int valorLance = menorLance; valorLance <= maiorLance; valorLance += lanceIncremento) {
        auto nome = std::string("Zexinho ");

        std::stringstream ss;
        ss << nome << valorLance;
        nome = ss.str();

        auto lance = Lance(Usuario(nome), valorLance);
        leilao.recebeLance(lance);
    }
    return leilao;
}

static Leilao leilaoOrdemDecrescente(int menorLance, int maiorLance, int lanceIncremento) {
    auto leilao = leilaoVazio();

    for (int valorLance = maiorLance; valorLance >= menorLance; valorLance -= lanceIncremento) {
        auto nome = std::string("Zexinho ");

        std::stringstream ss;
        ss << nome << valorLance;
        nome = ss.str();

        auto lance = Lance(Usuario(nome), valorLance);
        leilao.recebeLance(lance);
    }
    return leilao;
}


TEST_CASE("Avaliar maior lance") {

    //Arrange
    Leilao leilao = GENERATE(
            leilaoOrdemCrescente(1000, 2000, 1000),
            leilaoOrdemDecrescente(1000, 2000, 1000)

    );
    Avaliador leiloeiro;

    //Act - When
    leiloeiro.avaliar(leilao);

    float valorEsperado = 2000;
    //Assert - Then


    REQUIRE(leiloeiro.recuperarMaiorValor() == valorEsperado);
}


TEST_CASE("Avaliar menor lance") {

    //Arrange
    Leilao leilao = GENERATE(
            leilaoOrdemCrescente(1000, 2000, 1000),
            leilaoOrdemDecrescente(1000, 2000, 1000)
    );
    Avaliador leiloeiro;

    //Act - When
    leiloeiro.avaliar(leilao);

    float valorEsperado = 1000;


    REQUIRE(leiloeiro.recuperarMenorValor() == valorEsperado);
}


TEST_CASE("Avaliar os 3 maiores lances") {
    SECTION("Deve recuperar os 3 maiores lances") {

        //Arrange
        Leilao leilao = GENERATE(
                leilaoOrdemCrescente(1000, 10000, 1000),
                leilaoOrdemDecrescente(1000, 10000, 1000)
        );
        Avaliador leiloeiro;

        //Act - When
        leiloeiro.avaliar(leilao);

        REQUIRE(leiloeiro.getMaiores3Lances().size() == 3);
        REQUIRE(leiloeiro.getMaiores3Lances().at(0).recuperaValor() == 10000);
        REQUIRE(leiloeiro.getMaiores3Lances().at(1).recuperaValor() == 9000);
        REQUIRE(leiloeiro.getMaiores3Lances().at(2).recuperaValor() == 8000);
    }

    SECTION("Deve recuperar apenas os 2 maiores lances")
    {

        //Arrange
        Leilao leilao = GENERATE(
                leilaoOrdemCrescente(1000, 2000, 1000),
                leilaoOrdemDecrescente(1000, 2000, 1000)
        );


        Avaliador leiloeiro;

        //Act - When
        leiloeiro.avaliar(leilao);

        REQUIRE(leiloeiro.getMaiores3Lances().size() == 2);
        REQUIRE(leiloeiro.getMaiores3Lances().at(0).recuperaValor() == 2000);
        REQUIRE(leiloeiro.getMaiores3Lances().at(1).recuperaValor() == 1000);
    }
}


TEST_CASE("Avaliar leilão sem lances") {

    Leilao leilao = leilaoVazio();

    SECTION("Não deve retornar maior lance") {
        //Arrange
        Avaliador leiloeiro;

        //Act - When
        leiloeiro.avaliar(leilao);

        REQUIRE(leiloeiro.recuperarMaiorValor() == 0);
    }

    SECTION("Não deve retornar menor lance ") {

        Avaliador leiloeiro;

        //Act - When
        leiloeiro.avaliar(leilao);

        float valorEsperado = 0;

        REQUIRE(leiloeiro.recuperarMenorValor() == valorEsperado);
    }

    SECTION("Não deve retornar os 3 maiores lances")
    {

        Avaliador leiloeiro;

        //Act - When
        leiloeiro.avaliar(leilao);

        REQUIRE(leiloeiro.getMaiores3Lances().empty());
    }


}

TEST_CASE("Leilão não deve receber lances consecutivos do mesmo usuário") {

    //Arrange
    Leilao leilao = leilaoVazio();
    auto usuario = Usuario("Usuario");
    Avaliador leiloeiro;

    Lance segundoLance(usuario, 1500);
    //rvalue
    leilao.recebeLance(Lance(usuario, 1000));
    //lvalue segundoLance
    leilao.recebeLance(segundoLance);

    //Act - When
    leiloeiro.avaliar(leilao);

   //Assert

    REQUIRE(leilao.recuperaLances().size() == 1);
    REQUIRE(leilao.recuperaLances()[0].recuperaValor() == 1000);
}

TEST_CASE("Usuario deve saber informar o seu primeiro nome") {

    //Arrange
//Usuario("Usuario da Silva"),
    auto usuario = GENERATE( Usuario("Usuario"));

    //Assert
    REQUIRE(usuario.recuperaPrimeiroNome() == "Usuario");

}
