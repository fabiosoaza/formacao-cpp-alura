#pragma once
#include <iostream>
using namespace std;

//função inline: inclui o conteudo da funcao no arquivo ao inves de fazer uma chamada de funcao na execução.
//usada para otimização para evitar um salto na memória na excução
//não é criada uma unidade de tradução
//definição deve estar no cabeçalho
/*
 Uma função inline não é compilada por si só. Se você modificar uma função inline, todos os arquivos que a usam vão precisar ser recompilados. Além disso, como o código pode muito bem ser incluído em mais de uma unidade de tradução, é possível que o arquivo final fique um pouco maior.
 * */
inline void imprime_cabecalho(){
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}
