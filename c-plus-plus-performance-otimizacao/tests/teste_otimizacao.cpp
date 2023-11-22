#define CATCH_CONFIG_MAIN

#include "../src/Avaliador.hpp"
#include "../src/Usuario.hpp"
#include <catch2/catch_all.hpp>
#include <iostream>

class String {
private:
    char *data;
    size_t size;
public:
    String(const char *txt) {
        std::cout << "String " << txt << " criada" << std::endl;
        size = strlen(txt);
        data = new char[size];
        //last delimiter char
        data[size] = 0;
        memcpy(data, txt, size);
    }
    //copy constructor
    String(const String& txt) {
        std::cout << "String " << txt.data << " copiada via copy constructor " << std::endl;
        size = strlen(txt.data);
        data = new char[size];
        //last delimiter char
        data[size] = 0;
        memcpy(data, txt.data, size);
    }
    //move constructor
    String( String&& txt) {
        std::cout << "String " << txt.data << " movida via move constructor " << std::endl;
        size = txt.size;
        data = txt.data;
        //invalida string original para evitar que o delete seja chamado duas vezes
        txt.size = 0;
        txt.data = nullptr;

    }

    ~String() {
        delete data;
    }
};

class User {
private :
    String name;
public:
    User(const String &str) : name(str) {

    }
    User( String &&str) : name((String&&)str) {

    }


};

class UserStdMove {
private :
    String name;
public:
    UserStdMove(const String &str) : name(str) {

    }

    UserStdMove(String &&str) : name(std::move(str)) {

    }

};



    /*
void *operator new(size_t bytes) {
    std::cout << "Alocando " << bytes << " bytes" << std::endl;
    return malloc(bytes);
}
 */

void exibeNome(const std::unique_ptr<Usuario> &usuario) {

    std::cout << "Usuario unique " << usuario->recuperaNome() << std::endl;
}

void exibeNome(const std::shared_ptr<Usuario> usuario) {

    std::cout << "Usuario shared " << usuario->recuperaNome() << std::endl;
}

TEST_CASE("Teste otimizacao") {
    std::cout << "Teste alocacao" << std::endl;
    //caso seja uma string pequena aloca na stack
    //mall string optimizations
    //std::string texto = "alloc";
    //texto maior 16bytes no g++ aloca na heap
    //std::string texto = "0123456789012345";

    std::string texto = "String muito grande um & string muito grande dois";
    //3 alocacoes
    //std::string parte1 = texto.substr(0, texto.find('&'));//copia string
    //std::string parte2 = texto.substr(texto.find('&') + 2);//copia string

    //uma alocacao apenas, disponivel apenas a partir do c++17
    std::string_view parte1(texto.c_str(), texto.find('&') - 1);//mantem referencia para parte da string
    std::string_view parte2(texto.c_str() + texto.find('&') + 2);//mantem referencia para parte da string

    //faz uma copia do construtor e move
    // auto usuario = std::make_unique<Usuario>( Usuario("teste"));
    //faz a criação direta do ponteiro sem fazer uma copia adicional
    auto usuario = std::make_unique<Usuario>("make_unique");
    //n uniq_ptr não pode ser copiado
    // neste caso tem duas alterativas garantir que o ponteiro continue "vivo"
    // e passar a referencia
    exibeNome(usuario);

    auto usuario_shared = std::make_shared<Usuario>("usuario_shared");
    exibeNome(usuario_shared);

    std::cout << parte1 << std::endl;
    std::cout << parte2 << std::endl;

    REQUIRE(true == true);


}

TEST_CASE("Teste lvalues e rvalues") {
    //Arrange
    Leilao leilao = Leilao("Fiat 147 0 KM");
    auto usuario = Usuario("Usuario");
    Avaliador leiloeiro;

    Lance segundoLance(usuario, 1500);
    //rvalue
    leilao.recebeLance(Lance(usuario, 1000));
    //lvalue segundoLance
    leilao.recebeLance(segundoLance);

    //Act - When
    leiloeiro.avaliar(leilao);
}

TEST_CASE("Teste move constructor") {
    //duas vezes chamando delete de String uma para String e outra para user
    //não funciona sem copy constructor, vai gerar um erro ao deletar User
    //chamando o move constructor de user, senão invalidar os dados originais da variavel passada pode gerar um erro ao chmar delete de string
    //pois existirao dois ponteiros de string apontando para a mesma variavel
    User(String("User"));
}

TEST_CASE("Teste std::move constructor") {
    //duas vezes chamando delete de String uma para String e outra para user
    //não funciona sem copy constructor, vai gerar um erro ao deletar User
    //chamando o move constructor de user, senão invalidar os dados originais da variavel passada pode gerar um erro ao chmar delete de string
    //pois existirao dois ponteiros de string apontando para a mesma variavel
    UserStdMove(String("User"));
}