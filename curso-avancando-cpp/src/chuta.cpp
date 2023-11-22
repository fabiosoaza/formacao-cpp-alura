#include <iostream>
#include <map>
#include <array>
#include "letra_existe.hpp"
using namespace std;

extern int chutes_dados;

void chuta(array<char, 5> *chutes_errados, map<char, bool> *chutou, string palavra_secreta) {
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    (*(chutou))[chute] = true;

    if (letra_existe(chute,palavra_secreta)) {
        cout << "Você acertou! Seu chute está na palavra." << endl;
    } else {
        cout << "Você errou! Seu chute não está na palavra." << endl;
        (* chutes_errados)[chutes_dados++]=chute;
    }
    cout << endl;
}