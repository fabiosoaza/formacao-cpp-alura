#include <iostream>
#include <string>
#include <memory>
#include "Usuario.hpp"

/*
void *operator new(size_t bytes) {
    std::cout << "Alocando " << bytes << " bytes" << std::endl;
    return malloc(bytes);
}*/

/*
void exibeNome( const std::unique_ptr<Usuario> usuario)  {
    std::cout << "Usuario " <<std::endl;
    //std::cout << "Usuario " << usuario->recuperaNome();
}
*/
int main_() {
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
    std::string_view parte1(texto.c_str(),  texto.find('&')-1);//mantem referencia para parte da string
    std::string_view parte2(texto.c_str()+texto.find('&') + 2);//mantem referencia para parte da string

    Usuario *args = new Usuario("teste");
    //std::unique_ptr<Usuario> usuario = std::make_unique<Usuario>(args);
    //n uniq_ptr não pode ser copiado
    // neste caso tem duas alterativas garantir que o ponteiro continue "vivo"
    // e passar a referencia
   // exibeNome(usuario);

    std::cout << parte1 << std::endl;
    std::cout << parte2 << std::endl;
    return 0;
}