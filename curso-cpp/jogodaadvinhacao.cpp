#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    std::cout << "************************************************************" << std::endl;
    std::cout << "* Bem-vindos ao jogo da adivinhação                        *" << std::endl;
    cout << "************************************************************" << endl;

    srand(time(NULL));
    int numero_secreto = rand() % 100;

    int chute = 0;
    bool acertou = false;
    int tentativas = 0;
    double pontuacao = 1000;
    char dificuldade;
    int maximo_tentativas;

    cout << "Escolha o seu nível de dificuldade : ";
    cout << "(F)ácil, (M)édio ou (D)ifícil : ";
    cin >> dificuldade;

    if (dificuldade == 'F') {
        maximo_tentativas = 3;

    } else if (dificuldade == 'M') {
        maximo_tentativas = 2;
    } else if (dificuldade == 'D') {
        maximo_tentativas = 1;
    } else {
        maximo_tentativas = 0;
    }

    for (tentativas = 1; tentativas <= maximo_tentativas; tentativas++) {

        cout << "Tentativa  " << tentativas << endl;
        cout << "Qual o seu chute ? ";
        cin >> chute;

        double pontos_perdidos = abs((chute - numero_secreto) / 2.0);
        pontuacao -= pontos_perdidos;

        acertou = chute == numero_secreto;
        bool menor = chute < numero_secreto;
        if (acertou) {
            break;
        } else if (menor) {
            cout << "O seu chute foi menor do que o número secreto " << endl;
        } else {
            cout << "O seu chute foi maior do que o número secreto " << endl;
        }

    }

    if (acertou) {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de " << pontuacao << " pontos" << endl;
    } else {
        cout << "Você perdeu !!! O número secreto é "<<numero_secreto << endl;
    }


    return 0;
}
