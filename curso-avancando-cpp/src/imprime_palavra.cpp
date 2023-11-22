#include <iostream>
#include <map>


using namespace std;

void imprime_palavra(string palavra_secreta, map<char, bool> chutou){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}