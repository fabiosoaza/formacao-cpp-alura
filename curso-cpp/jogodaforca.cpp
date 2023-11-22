#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>




using namespace std;

void imprime_cabecalho() {
    cout << "************************************************************" << endl;
    cout << "* Bem-vindos ao jogo da forca                              *" << endl;
    cout << "************************************************************" << endl;
}

vector<string> ler_arquivo() {
    ifstream arquivo("palavras.txt");
    vector<string> palavras;
    if (arquivo.is_open()) {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;
        for (int i = 0; i < quantidade_palavras; ++i) {
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras.push_back(palavra_lida);
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o banco de palavras";
        exit(0);
    }
    return palavras;
}

bool palavra_existe(const std::vector<std::string> &vetor, const std::string &palavra) {
    return std::find(vetor.begin(), vetor.end(), palavra) != vetor.end();
}

void salvar_palavra(const string &nova_palavra) {
    vector<string> palavras = ler_arquivo();

    if (palavra_existe(palavras, nova_palavra)) {
        cout << "A palavra digitada já existe" << endl;
    } else {
        palavras.push_back(nova_palavra);
    }

    ofstream arquivo("palavras.txt");
    if (arquivo.is_open()) {
        arquivo << palavras.size() << endl;
        for (string palavra: palavras) {
            arquivo << palavra << endl;
        }

    } else {
        cout << "Não foi possível salvar a nova palavra";
        exit(0);
    }

}


bool letra_existe(string palavra, char letra) {
    for (char l: palavra) {
        if (std::tolower(letra) == std::tolower(l)) {
            return true;
        }
    }
    return false;
}




void imprime_resultado(const string &palavra_secreta, bool acertou) {
    cout << "Fim de jogo!!!" << endl;
    cout << "A palavra era : " << palavra_secreta << endl;
    if (acertou) {
        char resp;
        cout << "Parabéns você acertou a palavra" << endl;
        cout << "Deseja adicionar uma nova palavra S/N: ";
        cin >> resp;
        resp = toupper(resp);
        if (resp == 'S') {
            string nova_palavra;
            cout << "Digite a nova palavra: ";
            cin >> nova_palavra;
            salvar_palavra(nova_palavra);
        }

    } else {
        cout << "Você não adivinhou a palavra secreta" << endl;
    }
}


void imprime_tentativas(const string &palavra, const vector<char> &chutes_errados, int tentativas) {
    cout << "Palavra: " << palavra << endl;
    cout << "Chutes errados: " << string(chutes_errados.begin(), chutes_errados.end()) << endl;
    cout << "Tentativas: " << tentativas << endl;
}


char ler_chute(char chute) {
    cout << "Informe uma letra : ";
    cin >> chute;
    chute = tolower(chute);
    return chute;
}


string sortear_palavra() {

    vector<string> palavras = ler_arquivo();
    srand(time(NULL));
    int index = rand() % palavras.size();

    return palavras[index];
}


int main() {

    map<char, bool> chutes;
    vector<char> chutes_errados;
    bool acertou = false;
    int tentativas = 5;

    imprime_cabecalho();

    string palavra_secreta = sortear_palavra();

    string palavra(palavra_secreta.size(), '_');

    while (tentativas > 0 and !acertou) {
        char chute;
        chute = ler_chute(chute);
        if (!std::isalpha(chute)) {
            cout << "Você deve informar uma letra " << endl;
            continue;
        } else if (chutes[chute]) {
            cout << "Você já informou a letra : " << chute << endl;
        } else if (letra_existe(palavra_secreta, chute)) {
            for (int i = 0; i < palavra_secreta.size(); i++) {
                if (chute == palavra_secreta[i]) {
                    palavra[i] = chute;
                }
            }
            chutes[chute] = true;
        } else {
            cout << "Palavra não contem a letra: " << chute << endl;
            tentativas--;
            chutes[chute] = true;
            chutes_errados.push_back(chute);
        }
        imprime_tentativas(palavra, chutes_errados, tentativas);
        if (palavra == palavra_secreta) {
            acertou = true;
            break;
        }
    }
    imprime_resultado(palavra_secreta, acertou);

    return 0;
}

