#include <string>
using namespace std;


bool letra_existe(char chute, string palavra_secreta){
    for(char letra : palavra_secreta){
        if(chute == letra){
            return true;
        }
    }
    return false;
}