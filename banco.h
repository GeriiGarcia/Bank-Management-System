#include "cuenta.h"


class banco
{
public:
    banco();
    ~banco();

    void crearCuenta(); 
    
    bool comprovarNumeroCuenta(string num);
    void crearNumeroTarjeta(string num);
    cuenta *buscarCuenta(string num);

private:
    vector <cuenta> cu[0];

};

banco::banco(/* args */)
{
}

banco::~banco()
{
}
