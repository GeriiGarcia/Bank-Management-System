#include "cuenta.h"


class banco
{
public:
    banco() {};
    ~banco() {};

    void crearCuenta(bool tarjeta);
    bool comprovarNumeroCuenta(string num);
    Cuenta *buscarCuenta(string num);
    void eliminarCuenta(string num);

    void iniciarTodo();
    void guardarTodo();

private:
    vector <Cuenta> m_cuentas[0];

};


