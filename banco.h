#include "cuenta.h"


class banco
{
public:
    banco();
    ~banco();

    void crearCuenta(bool tarjeta);
    bool comprovarNumeroCuenta(string num);
    void crearNumeroTarjeta(string num);
    Cuenta *buscarCuenta(string num);
    void eliminarCuenta();

    void iniciarTodo();
    void guardarTodo();

private:
    vector <Cuenta> m_cuentas[0];

};

banco::banco(/* args */)
{
}

banco::~banco()
{
}
