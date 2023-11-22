#include <array>

using namespace std;

extern int chutes_dados;

bool nao_enforcou(array<char, 5> chutes_errados){
    return chutes_dados < 5;
}