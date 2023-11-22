#ifndef Lance_hpp
#define Lance_hpp
#include "Usuario.hpp"

class Lance
{
private:
    Usuario usuario;
    float valor;
public:
    Lance(Usuario usuario, float valor);
    float recuperaValor() const;
    std::string recuperaNomeUsuario() const;
    Lance(const Lance &lance);//copy constructor
    //por padrão o c++ cria o copy constructot, neste caso esta sendo criado explicitamente para testar a execução de um codigo na copia
    //Lance(const Lance &lance) = default;
    //desabilitar copy constructor
    //Lance(const Lance &lance)= delete;

};


#endif /* Lance_hpp */
